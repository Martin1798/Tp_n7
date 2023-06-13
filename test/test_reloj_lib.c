/* === Headers files inclusions =============================================================== */
#include "reloj_lib.h"
#include "unity.h"
#include <stdint.h>
#include <string.h>


void test_reloj_arranca_con_hora_invalida(void) {
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




