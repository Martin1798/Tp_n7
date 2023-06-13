#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"
#include "inc/reloj_lib.h"










void test_Prueba_DARHORA_Return_y_Mostrar_Hora(void) {



    reloj_t reloj = CrearReloj(1000);



    static const uint8_t Valor_de_inicio[] = {0, 0, 0, 0, 0, 0};



    uint8_t hora[6];





    do {if (!(DarHora(reloj, hora, 6))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(17)));}} while(0);



    UnityAssertEqualIntArray(( const void*)((Valor_de_inicio)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(19), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_Configurar_hora(void) {





    reloj_t reloj = CrearReloj(1000);





    static uint8_t Valor_de_carga[] = {2, 3, 3, 4, 5, 9};



    uint8_t hora[6];





    do {if ((ConfigurarHora(reloj,Valor_de_carga, 6))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(34)));}} while(0);



    do {if ((DarHora(reloj, hora, 6))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(36)));}} while(0);



    UnityAssertEqualIntArray(( const void*)((Valor_de_carga)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(38), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);









    Valor_de_carga[0]=3;





    do {if (!(ConfigurarHora(reloj,Valor_de_carga, 6))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(46)));}} while(0);



    do {if ((DarHora(reloj, hora, 6))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(48)));}} while(0);





    UnityAssertEqualIntArray(( const void*)((Valor_de_carga)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(51), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);







}
