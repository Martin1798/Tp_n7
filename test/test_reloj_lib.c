/* === Headers files inclusions =============================================================== */
#include "reloj_lib.h"
#include "unity.h"
#include <stdint.h>
#include <string.h>


void test_Prueba_DARHORA_Return_y_Mostrar_Hora(void) {
    //Creo un Reloj
    reloj_t reloj = CrearReloj(PULSO_SEG);
    //Se supone que el reloj deberia arrancar con el siguiente valor
    static const uint8_t Valor_de_inicio[] = {0, 0, 0, 0, 0, 0}; 
    //Aqui se guarda la hora del reloj
    uint8_t hora[6];
 
    //Dar hora devuelve el valor de reloj->valida el cual tendria que ser false
    TEST_ASSERT_FALSE(DarHora(reloj, hora, 6));  
    //En hora se copia el valor de reloj->hora_actual y se compara con el valor de inicio el cual tendria que ser todo cero
    TEST_ASSERT_EQUAL_UINT8_ARRAY(Valor_de_inicio, hora, 6); // pasa el test si la ESPERADO es igual hora=reloj->hora_actual
}

// Al ajustar la hora el reloj queda en hora y es válida.
void test_Configurar_hora(void) {

    //Creo un Reloj
    reloj_t reloj = CrearReloj(PULSO_SEG);

    //Se supone que el reloj deberia tener con el siguiente valor despues de caragr
    static uint8_t Valor_de_carga[] = {2, 3, 3, 4, 5, 9};
    //Aqui se guardara la hora del reloj cuando se la pida
    uint8_t hora[6];

    //Verifica el retorno de la funcion, si es valida deberiamos tener un true
    TEST_ASSERT_TRUE(ConfigurarHora(reloj,Valor_de_carga, 6)); 
    // Al valor inicial cargado, lo pone en hora y compara valor de carga con hora
    TEST_ASSERT_TRUE(DarHora(reloj, hora, 6));   
    // Si son iguales es test es correcto y paso la prueba 
    TEST_ASSERT_EQUAL_UINT8_ARRAY(Valor_de_carga, hora, 6); 

    //Ahora poner un valor incorrecto y veremos que sucede

    //Tener un 3 en esta posicion es algo invalido {3,3,3,4,5,9} ese numero de hora esta mal
    Valor_de_carga[0]=3;

    //Verifica el retorno de la funcion, si es valida deberiamos tener un false
    TEST_ASSERT_FALSE(ConfigurarHora(reloj,Valor_de_carga, 6)); 
    // Al valor inicial cargado, no se tendria que haber cargado
    TEST_ASSERT_TRUE(DarHora(reloj, hora, 6));   
    //Tiene que quedar la hora original asi que este test deberia dar ok
    Valor_de_carga[0]=2;
    TEST_ASSERT_EQUAL_UINT8_ARRAY(Valor_de_carga, hora, 6); 

}

// Después de n ciclos de reloj la hora avanza un segundo
void test_incremento_reloj(void) {

    //Creo un Reloj un argumento 1000 implica que cada 1000 pulsos tengo un segundo
    reloj_t reloj = CrearReloj(1000);

    //Se supone que el reloj deberia estar con el siguiente valor despues de incrementarlo
    static  uint8_t Valor_de_esperado [] = {0, 0, 0, 0, 0, 1};
    static  uint8_t Valor_de_esperado1[] = {0, 0, 0, 0, 5, 9};
    static  uint8_t Valor_de_esperado2[] = {0, 0, 0, 1, 0, 0};
    static  uint8_t Valor_de_esperado3[] = {0, 0, 5, 9, 0, 0};
    static  uint8_t Valor_de_esperado4[] = {0, 1, 0, 0, 0, 0};
    static  uint8_t Valor_de_esperado5[] = {0, 9, 0, 0, 0, 0};
    static  uint8_t Valor_de_esperado6[] = {2, 3, 0, 0, 0, 0};

    //Aqui se guardara la hora del reloj cuando se la pida
    uint8_t hora[6];
    //Configura los pulsos actuales del reloj en cero
    ConfigurarPulsos(reloj); 
    //Esta funcion es la encargada de aumentar los segundos cuando las condiciones se cumplan
    for (int i = 0; i < 1000; i++) {
        ActualizarHora(reloj);  //faltan 58 para los 59
    }
    DarHora(reloj,hora,6);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(Valor_de_esperado, hora, 6);


    for (int i = 0; i < 58000; i++) {
        ActualizarHora(reloj);  //faltan 58 para los 59
    }
    DarHora(reloj,hora,6);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(Valor_de_esperado1, hora, 6);


    for (int i = 0; i < 1000; i++) {
        ActualizarHora(reloj);  //un segundo mas para el primer minuto
    }
    DarHora(reloj,hora,6);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(Valor_de_esperado2, hora, 6);



    for (int i = 0; i < 3480000; i++) {
        ActualizarHora(reloj);  //faltan 3480 segundos para los 59 minutos
    }
    DarHora(reloj,hora,6);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(Valor_de_esperado3, hora, 6);

    for (int i = 0; i < 60000; i++) {
        ActualizarHora(reloj);  //faltan 60 segundos para la primera hora
    }
    DarHora(reloj,hora,6);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(Valor_de_esperado4, hora, 6);


    for (int i = 0; i < 28800000; i++) {
        ActualizarHora(reloj);  // llegamos a las 9 horas
    }
    DarHora(reloj, hora, 6);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(Valor_de_esperado5, hora, 6);

    for (int i = 0; i < (14*3600000); i++) {
        ActualizarHora(reloj);  // llegamos a las 23 horas
    }
    DarHora(reloj, hora, 6);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(Valor_de_esperado6, hora, 6);

    Valor_de_esperado[5]=0;

    for (int i = 0; i < (3600000); i++) {
        ActualizarHora(reloj);  // debe reiniciar
    }
    DarHora(reloj, hora, 6);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(Valor_de_esperado, hora, 6);

}



