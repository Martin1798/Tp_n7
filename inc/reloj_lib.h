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
#include <stdint.h>
#include <stdbool.h>
//////////////////////////////////////////////////
//! cantidad de pulsos por segundos a utilizar
#define PULSO_SEG 1000

//! Veces por segundo que se llamará a la función para mantener la hora actualizada.
#define REFRESCO 60

//! Minutos que se pospone la alarma
#define POSPONER_MINUTOS 5
//////////////////////////////////////////////////
typedef struct reloj_s *reloj_t;
//////////////////////////////////////////////////


/// @brief Esta funcion lo unico que hace es poner las cuentas de pulsos de reloj en 0
/// @param reloj objeto reloj al cual queremos cambiar el estado de pulsos actuales
void ConfigurarPulsos(reloj_t reloj);

/// @brief Esta funcion aumenta es estado actual de pulsos de reloj en 1
/// @param reloj 
void AumentarPulsos(reloj_t reloj);

/// @brief Crea un objeto reloj
/// @param Pulsos_segundo Este parametro configura la cantidad de pulsos que incrementara una unidad los segundos
/// @return 
reloj_t CrearReloj(uint32_t Pulsos_segundo);

/// @brief Carga verifica si la hora es correcta y la carga en el reloj correspondiente
/// @param reloj Objeto a caragr
/// @param hora Array de 6 elementos a cargar
/// @param tamaño Tamaño del array
/// @return Si el valor de retorno es true significa que se realizo la carga con exito
bool ConfigurarHora(reloj_t reloj, const uint8_t * hora, uint32_t tamaño);

/// @brief Esta funcion devuelve la hora del objeto reloj
/// @param reloj objeto al cual se le quiere ver la hora
/// @param hora array donde se carga la hora
/// @param tamaño tamaño del array
/// @return La funcion retorna si la hora es valida
bool DarHora(reloj_t reloj, uint8_t * hora, uint8_t tamaño);

/// @brief Esta funcion despues de ser llamada un cierto numero de veces aumenta y hace toda la gestion de incremetar las horas del reloj
/// @param reloj 
void ActualizarHora(reloj_t reloj);

/// @brief Esta funcion verifica que la alarma sea valida y la carga en el objeto reloj correspondiente
/// @param reloj objeto donde se realizara la carga
/// @param hora Horas de la alarma
/// @param tamaño Tamaño del array hora
/// @return si la alarma se pude establecer devuelve un false
bool FijarAlarma(reloj_t reloj, const uint8_t * hora, uint8_t tamaño);

/// @brief Devuelve en horas el horario de la alarma del objeto reloj y activa alarma
/// @param reloj 
/// @param hora 
/// @param tamaño 
/// @return retorna true pues enciende la alarma 
bool ConsultarHoraAlarma(reloj_t reloj, uint8_t * hora, uint32_t tamaño);

/// @brief actica y desactiva el sonido de la alarma
/// @param reloj 
/// @param estado false/apagada true/encendida
/// @return 
bool GestionAlarma(reloj_t reloj, bool estado);

/// @brief Indica si la alarma se encuenta encendida o apagada
/// @param reloj 
/// @return True encendida, False apagada
bool EstadoActualAlarma(reloj_t reloj);

/// @brief pospone alarma un tiempo determinado
/// @param reloj 
/// @param inactivo 
/// @return reloj->tiempo_pospuesto;
bool PosponerAlarma(reloj_t reloj, uint8_t inactivo);

/// @brief nos dice si la alarma se encuentra sonando
/// @param reloj 
/// @return 
bool AlarmaActivar(reloj_t reloj);

/// @brief pospone alarma 24 horas
/// @param reloj 
/// @return 
bool PosponerAlarmaDia(reloj_t reloj);