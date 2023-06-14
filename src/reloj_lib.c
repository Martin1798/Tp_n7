/* Copyright 2022, Laboratorio de Microprocesadores
 * Facultad de Ciencias Exactas y Tecnología
 * Universidad Nacional de Tucuman
 * http://www.microprocesadores.unt.edu.ar/
 * Copyright 2022, Lopez Luque,Martin Eduardo
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS  "
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#include "reloj_lib.h"
#include <string.h>

//////////////////////////////////////////////////
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
    if(hora[1]>9)retornar=true;

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

    if (!memcmp(hora, alarma, 6)){
        reloj->alarma_activada = true;
    }

    return ((reloj->alarma_activada) && (!reloj->tiempo_pospuesto)&&(reloj->alarma_on));
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
    if(hora[1]>9)retornar=true;
    return retornar;
}
//////////////////////////////////////////////////


