/* **************************************************************
* Nombre: Proyecto_2
* Módulo: Tiva Launchpad EK-TM4C123GXL
* Descripción: Prende y apaga un led en el pin 1 del puerto F.
* Autor: Zenón Cucho / Hugo Pratt
* Fecha: Semestre 2016-2
* ***************************************************************
*/
#include <stdint.h>
#include "tm4c123gh6pm.h"
void main(void) {
    uint32_t n;
    // activamos la señal de reloj del puerto F
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;
    // esperamos a que realmente se active
    while( (SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R5)==0) { }
    GPIO_PORTF_DIR_R |= 0x02; // Configura el bit 1 del puerto F como salida
    GPIO_PORTF_DR8R_R |=0x02; // se activa el driver de 8 mA en el pin 1.
    GPIO_PORTF_DEN_R |=0x02; // se activa el pin 1 del puerto F, como salida
    digital.
    while(1){
    GPIO_PORTF_DATA_R |=0X02; // se prende el led conectado al pin PF1.
    //retardo de encendido:
    for(n = 0; n < 800000; n++);
    // se apaga el led:
    GPIO_PORTF_DATA_R &= ~(0X02);
    // retardo de apagado:
    for(n = 0; n < 800000; n++);
} //fin de while
