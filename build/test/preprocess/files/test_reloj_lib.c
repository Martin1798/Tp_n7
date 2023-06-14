#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"
#include "inc/reloj_lib.h"








void test_Prueba_DARHORA_Return_y_Mostrar_Hora(void) {



    reloj_t reloj = CrearReloj(1000);



    static const uint8_t Valor_de_inicio[] = {0, 0, 0, 0, 0, 0};



    uint8_t hora[6];





    do {if (!(DarHora(reloj, hora, 6))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(50)));}} while(0);



    UnityAssertEqualIntArray(( const void*)((Valor_de_inicio)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(52), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_Configurar_hora(void) {





    reloj_t reloj = CrearReloj(1000);





    static uint8_t Valor_de_carga[] = {2, 3, 3, 4, 5, 9};



    uint8_t hora[6];





    do {if ((ConfigurarHora(reloj,Valor_de_carga, 6))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(67)));}} while(0);



    do {if ((DarHora(reloj, hora, 6))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(69)));}} while(0);



    UnityAssertEqualIntArray(( const void*)((Valor_de_carga)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(71), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);









    Valor_de_carga[0]=3;





    do {if (!(ConfigurarHora(reloj,Valor_de_carga, 6))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(79)));}} while(0);



    do {if ((DarHora(reloj, hora, 6))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(81)));}} while(0);



    Valor_de_carga[0]=2;

    UnityAssertEqualIntArray(( const void*)((Valor_de_carga)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(84), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);



}





void test_incremento_reloj(void) {





    reloj_t reloj = CrearReloj(1000);





    static uint8_t Valor_de_esperado [] = {0, 0, 0, 0, 0, 1};

    static uint8_t Valor_de_esperado1[] = {0, 0, 0, 0, 5, 9};

    static uint8_t Valor_de_esperado2[] = {0, 0, 0, 1, 0, 0};

    static uint8_t Valor_de_esperado3[] = {0, 0, 5, 9, 0, 0};

    static uint8_t Valor_de_esperado4[] = {0, 1, 0, 0, 0, 0};

    static uint8_t Valor_de_esperado5[] = {0, 9, 0, 0, 0, 0};

    static uint8_t Valor_de_esperado6[] = {2, 3, 0, 0, 0, 0};





    uint8_t hora[6];



    ConfigurarPulsos(reloj);



    for (int i = 0; i < 1000; i++) {

        ActualizarHora(reloj);

    }

    DarHora(reloj,hora,6);

    UnityAssertEqualIntArray(( const void*)((Valor_de_esperado)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(112), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);





    for (int i = 0; i < 58000; i++) {

        ActualizarHora(reloj);

    }

    DarHora(reloj,hora,6);

    UnityAssertEqualIntArray(( const void*)((Valor_de_esperado1)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(119), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);





    for (int i = 0; i < 1000; i++) {

        ActualizarHora(reloj);

    }

    DarHora(reloj,hora,6);

    UnityAssertEqualIntArray(( const void*)((Valor_de_esperado2)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(126), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);







    for (int i = 0; i < 3480000; i++) {

        ActualizarHora(reloj);

    }

    DarHora(reloj,hora,6);

    UnityAssertEqualIntArray(( const void*)((Valor_de_esperado3)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(134), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);



    for (int i = 0; i < 60000; i++) {

        ActualizarHora(reloj);

    }

    DarHora(reloj,hora,6);

    UnityAssertEqualIntArray(( const void*)((Valor_de_esperado4)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(140), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);





    for (int i = 0; i < 28800000; i++) {

        ActualizarHora(reloj);

    }

    DarHora(reloj, hora, 6);

    UnityAssertEqualIntArray(( const void*)((Valor_de_esperado5)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(147), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);



    for (int i = 0; i < (14*3600000); i++) {

        ActualizarHora(reloj);

    }

    DarHora(reloj, hora, 6);

    UnityAssertEqualIntArray(( const void*)((Valor_de_esperado6)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(153), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);



    Valor_de_esperado[5]=0;



    for (int i = 0; i < (3600000); i++) {

        ActualizarHora(reloj);

    }

    DarHora(reloj, hora, 6);

    UnityAssertEqualIntArray(( const void*)((Valor_de_esperado)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(161), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);



}







void test_Poner_alarma(void) {



    reloj_t reloj = CrearReloj(1000);



    static const uint8_t Valor_alarma[] = {1, 1, 3, 4, 1, 1};

    uint8_t hora[6];





    do {if (!(FijarAlarma(reloj, Valor_alarma, 6))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(175)));}} while(0);



    do {if ((ConsultarHoraAlarma(reloj, hora, 6))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(177)));}} while(0);



    UnityAssertEqualIntArray(( const void*)((Valor_alarma)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(179), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}







void test_sonar_alarma(void) {





    reloj_t reloj = CrearReloj(1);



    static const uint8_t hora[] = {0, 0, 0, 0, 0, 0};

    uint8_t alarma[6] = {0, 0, 0, 0, 0, 1};





    ConfigurarHora(reloj, hora, 6);





    FijarAlarma(reloj, alarma, 6);





    ConfigurarPulsos(reloj);





    ActualizarHora(reloj);

    do {if ((AlarmaActivar(reloj))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(203)));}} while(0);

}







void test_no_sonar_alarma(void) {





    reloj_t reloj = CrearReloj(1);



    static const uint8_t hora[] = {0, 0, 0, 0, 0, 0};

    uint8_t alarma[6] = {0, 0, 0, 0, 0, 1};





    ConfigurarHora(reloj, hora, 6);



    FijarAlarma(reloj, alarma, 6);



    ConfigurarPulsos(reloj);



    ActualizarHora(reloj);





    GestionAlarma(reloj, 

                        0

                             );

    do {if (!(GestionAlarma(reloj, 

   0

   ))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(227)));}} while(0);



    do {if (!(AlarmaActivar(reloj))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(229)));}} while(0);

}



void test_posponer_alarma(void) {



    reloj_t reloj = CrearReloj(1);



    static const uint8_t hora[] = {0, 0, 0, 0, 0, 0};

    uint8_t alarma[6] = {0, 0, 0, 0, 0, 1};



    ConfigurarHora(reloj, hora, 6);

    FijarAlarma(reloj, alarma, 6);



    ConfigurarPulsos(reloj);





    ActualizarHora(reloj);

    do {if ((AlarmaActivar(reloj))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(246)));}} while(0);

    do {if ((PosponerAlarma(reloj, 5))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(247)));}} while(0);

    do {if (!(AlarmaActivar(reloj))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(248)));}} while(0);





    ActualizarHora(reloj);

    ActualizarHora(reloj);

    ActualizarHora(reloj);

    ActualizarHora(reloj);



    do {if (!(AlarmaActivar(reloj))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(256)));}} while(0);



    ActualizarHora(reloj);

    do {if ((AlarmaActivar(reloj))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(259)));}} while(0);

}





void test_saltar_dia(void) {



    reloj_t reloj = CrearReloj(1);



    static uint8_t hora[] = {0, 0, 0, 0, 0, 0};

    uint8_t alarma[6] = {0, 0, 0, 0, 0, 1};



    ConfigurarHora(reloj, hora, 6);

    FijarAlarma(reloj, alarma, 6);







    ActualizarHora(reloj);

    do {if ((AlarmaActivar(reloj))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(276)));}} while(0);



    do {if (!(PosponerAlarmaDia(reloj))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(278)));}} while(0);



    ConfigurarPulsos(reloj);



    ActualizarHora(reloj);

    do {if (!(AlarmaActivar(reloj))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(283)));}} while(0);





    ConfigurarHora(reloj, hora, 6);



    ConfigurarPulsos(reloj);



    ActualizarHora(reloj);



    DarHora(reloj, hora, 6);

    UnityAssertEqualIntArray(( const void*)((alarma)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(293), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

    do {if ((AlarmaActivar(reloj))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(294)));}} while(0);

}
