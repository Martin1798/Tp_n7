/* === Headers files inclusions =============================================================== */
#include "reloj_lib.h"
#include "unity.h"
#include <stdint.h>


// Al inicializar el reloj está en 00:00 y con hora invalida.
void test_reloj_arranca_con_hora_invalida(void) {

    static const uint8_t ESPERADO[] = {0, 0, 0, 0, 0, 0}; // crea un vector que se toma como referencia para comparar
    uint8_t hora[6] = {0xf0};                             // variable para almacenar la hora auxiliar
    reloj_t reloj = CrearReloj(PULSO_SEG); // cuando lo creo un objeto reloj le digo cuanto pulso(ticks) por segundo

    TEST_ASSERT_FALSE(DarHora(reloj, hora, 6));  // pasa el test si la hora->valida es FALSE o 0
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, 6); // pasa el test si la ESPERADO es igual hora=reloj->hora_actual
}