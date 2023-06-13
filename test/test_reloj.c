/* === Headers files inclusions =============================================================== */
#include "calculadora.h"
#include "unity.h"
#include <stdint.h>


void test_calcu(void){
    TEST_ASSERT_EQUAL(3,calc(1,1));
}