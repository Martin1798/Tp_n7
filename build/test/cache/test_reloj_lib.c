#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"
#include "inc/reloj_lib.h"










void test_reloj_arranca_con_hora_invalida(void) {



    static const uint8_t ESPERADO[] = {0, 0, 0, 0, 0, 0};

    uint8_t hora[6] = {0xf0};

    reloj_t reloj = CrearReloj(5);



    do {if (!(DarHora(reloj, hora, 6))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(14)));}} while(0);

    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(15), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}
