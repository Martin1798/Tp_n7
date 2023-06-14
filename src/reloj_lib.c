#include "reloj_lib.h"
#include <string.h>


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
void Cada_Segundo(uint8_t * hora_actual, reloj_t reloj);
bool validar_hora(const uint8_t * hora);
//////////////////////////////////////////////////
void ConfigurarPulsos(reloj_t reloj){
    reloj->Pulsos_actual= 0;
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
bool ConfigurarHora(reloj_t reloj, const uint8_t * hora, uint32_t tamaño){
    bool select = true;

    if (!validar_hora(hora)) {
        memcpy(reloj->hora_actual, hora, tamaño);
        reloj->valida = true;
    } else {
        select = false;
    }
    return select;    
}
//////////////////////////////////////////////////
bool DarHora(reloj_t reloj, uint8_t * hora, uint8_t tamaño){
    memcpy(hora, reloj->hora_actual, tamaño);
    return reloj->valida;    
}
//////////////////////////////////////////////////
void ActualizarHora(reloj_t reloj){
    uint8_t hora[6];

    reloj->Pulsos_actual++;

    if (reloj->Pulsos_actual == reloj->Pulsos_seg) {
        DarHora(reloj, hora, 6);
        
        Cada_Segundo(hora,reloj);

        ConfigurarHora(reloj, hora, 6);

        reloj->Pulsos_actual = 0;

        if (reloj->alarma_on) { 
            AlarmaActivar(reloj);
        }
    }   
}
//////////////////////////////////////////////////
bool FijarAlarma(reloj_t reloj, const uint8_t * hora, uint8_t tamaño){

    bool retornar=false;
    if(hora[5]>9||hora[4]>5||hora[3]>9||hora[2]>5)retornar=true;
    if(hora[0]>1&&hora[1]>3)retornar=true;
    if(hora[0]>2)retornar=true;

    if(!retornar){
        memcpy(reloj->alarma, hora, tamaño);
        reloj->alarma_on = true;
    }

    return retornar;//si retornar es false se cargo la alarma correctamente
}
//////////////////////////////////////////////////
bool ConsultarHoraAlarma(reloj_t reloj, uint8_t * hora, uint32_t tamaño){
    memcpy(hora, reloj->alarma, tamaño);
    return reloj->alarma_on;
}
//////////////////////////////////////////////////
bool GestionAlarma(reloj_t reloj, bool estado){
    reloj->alarma_on = estado;
    return reloj->alarma_on;    
}
//////////////////////////////////////////////////
bool EstadoActualAlarma(reloj_t reloj){
        return reloj->alarma_on;
}
//////////////////////////////////////////////////
bool PosponerAlarma(reloj_t reloj, uint8_t inactivo){
    reloj->tiempo_pospuesto = inactivo;
    return reloj->tiempo_pospuesto;    
}
//////////////////////////////////////////////////
bool PosponerAlarmaDia(reloj_t reloj){
    reloj->alarma_activada = false;
    return reloj->alarma_activada;    
}
//////////////////////////////////////////////////
bool AlarmaActivar(reloj_t reloj) {
    uint8_t hora[6];
    uint8_t alarma[6];

    memcpy(hora, reloj->hora_actual, 6);
    memcpy(alarma, reloj->alarma, 6);

    if (hora[0] == alarma[0] && hora[1] == alarma[1] && hora[2] == alarma[2] && hora[3] == alarma[3] &&
        hora[4] == alarma[4] && hora[5] == alarma[5]) {
        reloj->alarma_activada = true;
    }

    return (reloj->alarma_activada && !reloj->tiempo_pospuesto);
}
//////////////////////////////////////////////////

//!Actializa la hora a cargar y descuenta el tiempo propuesto para la alarma
void Cada_Segundo(uint8_t * hora_actual, reloj_t reloj) {

    hora_actual[5]++; // incrementa en 1 los segundos
                             
    if (hora_actual[5]>9){
        hora_actual[5]=0;
        hora_actual[4]++;
    }
    if (hora_actual[4]>5){
        hora_actual[4]=0;
        hora_actual[3]++;
    }
    if (hora_actual[3]>9){
        hora_actual[3]=0;
        hora_actual[2]++;
    }
    if (hora_actual[2]>5){
        hora_actual[2]=0;
        hora_actual[1]++;
    }
    if (hora_actual[1]>9){
        hora_actual[1]=0;
        hora_actual[0]++;
    }
    if ((hora_actual[0]>=2)&&(hora_actual[1]>=4)){
        hora_actual[0]=0;
        hora_actual[1]=0;
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
    if(hora[0]>2)retornar=true;
    return retornar;
}
//////////////////////////////////////////////////


