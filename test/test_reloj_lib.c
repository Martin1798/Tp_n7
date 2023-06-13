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



