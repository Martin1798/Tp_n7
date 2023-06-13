#include <stdint.h>

//////////////////////////////////////////////////
//! cantidad de pulsos por segundos a utilizar
#define PULSO_SEG 5

//! Veces por segundo que se llamará a la función para mantener la hora actualizada.
#define REFRESCO 60

//! Minutos que se pospone la alarma
#define POSPONER_MINUTOS 5
//////////////////////////////////////////////////
typedef struct reloj_s *reloj_t;
//////////////////////////////////////////////////
void ConfigurarPulsos(reloj_t reloj);
void AumentarPulsos(reloj_t reloj);
reloj_t CrearReloj(uint32_t Pulsos_segundo);

char ConfigurarHora(reloj_t reloj, const uint8_t * hora, uint32_t tamaño);

char DarHora(reloj_t reloj, uint8_t * hora, uint32_t tamaño);
void ActualizarHora(reloj_t reloj);