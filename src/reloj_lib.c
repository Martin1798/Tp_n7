#include "reloj_lib.h"
#include <string.h>
#include <stdbool.h>

struct reloj_s {

    uint8_t hora_actual[6];
    bool valida;
    uint8_t alarma[6]; 
    bool alarma_on;
    bool alarma_activada;
    uint8_t tiempo_pospuesto;
    uint32_t Pulsos_seg;    
    uint32_t Pulsos_actual; 
};
//////////////////////////////////////////////////
void ConfigurarPulsos(reloj_t reloj){
    reloj->Pulsos_actual= reloj->Pulsos_seg-1;
}
//////////////////////////////////////////////////
void AumentarPulsos(reloj_t reloj){ 
    reloj->Pulsos_actual++;
}
//////////////////////////////////////////////////
//! Crea reloj_s puntero y la llena de 0
reloj_t CrearReloj(uint32_t Pulsos_segundo) {
    static struct reloj_s self[1];
    memset(self, 0, sizeof(self));
    self->Pulsos_seg=Pulsos_segundo;
    return self;
}
//////////////////////////////////////////////////
































































//!Actializa la hora a cargar y descuenta el tiempo propuesto para la alarma
void Cada_Segundo(reloj_t reloj) {

    reloj->hora_actual[5]++; // incrementa en 1 los segundos
                             
    if (reloj->hora_actual[5]>9){
        reloj->hora_actual[5]=0;
        reloj->hora_actual[4]++;
    }
    if (reloj->hora_actual[4]>5){
        reloj->hora_actual[4]=0;
        reloj->hora_actual[3]++;
    }
    if (reloj->hora_actual[3]>9){
        reloj->hora_actual[3]=0;
        reloj->hora_actual[2]++;
    }
    if (reloj->hora_actual[2]>5){
        reloj->hora_actual[2]=0;
        reloj->hora_actual[1]++;
    }
    if (reloj->hora_actual[1]>9){
        reloj->hora_actual[1]=0;
        reloj->hora_actual[0]++;
    }
    if ((reloj->hora_actual[0]==2)&&(reloj->hora_actual[1]==4)){
        reloj->hora_actual[0]=0;
        reloj->hora_actual[1]=0;
    }
    if (reloj->tiempo_pospuesto > 0) {
        reloj->tiempo_pospuesto--;
    }
}
//////////////////////////////////////////////////
//! Si la hora a almacenar es valida retorna false
bool validar_hora(const uint8_t * hora){
    bool retornar=false;
    if(hora[5]>9||hora[4]>5||hora[3]>9||hora[2]>5)retornar=true;
    if(hora[0]>1&&hora[1]>3)retornar=true;
    return retornar;
}
//////////////////////////////////////////////////


