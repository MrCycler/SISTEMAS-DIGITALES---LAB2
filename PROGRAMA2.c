/* ****************************************************************************
* Nombre: Proyecto_3
* Módulo: Tiva Launchpad EK-TM4C123GXL
* Descripción: Prende y apaga un led conectado al pin PF1 según estado del
* pulsador SW1 conectado a pin PF4
* Autor: Zenón Cucho / Hugo Pratt
* Fecha: Semestre 2016-2
* ******************************************************************************
*/
#include <stdint.h>
#include "tm4c123gh6pm.h"
void config_sw1(void){
    // activamos la señal de reloj del puerto F
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;
    // esperamos a que realmente se active
    while( (SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R5)==0) { }
    // SW1 está conectado al pin PF4
    GPIO_PORTF_DIR_R &= ~(0x10); // PF4 pin de entrada
    GPIO_PORTF_AFSEL_R &= ~(0x10); // no usamos función alternativa
    GPIO_PORTF_PUR_R |= 0x10; // activamos resistencia de pull-up en pin PF4
    GPIO_PORTF_DEN_R |= 0x10; // PF4 pin digital
}
void config_led_rojo(void){
    // activamos la señal de reloj del puerto F
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;
    // esperamos a que realmente se active
    while( (SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R5)==0) { }
    GPIO_PORTF_DIR_R |= 0x02; // Configura el bit 1 del puerto F como salida
    GPIO_PORTF_DR8R_R |=0x02; // se activa el driver de 8 mA en el pin 1.
    GPIO_PORTF_DEN_R |=0x02; // se activa el pin 1, como salida digital.
    GPIO_PORTF_DATA_R &= ~(0X02); // apagamos el led
}
void main(void) {
    uint32_t temp;
    config_sw1();
    config_led_rojo();
    while(1){
        temp =GPIO_PORTF_DATA_R;
        if ((temp & 0x10) == 0) // si SW1(conectado a PF4) está presionado
        GPIO_PORTF_DATA_R |= 0x02; // prendemos el led
        else // si SW1 no está presionado
        GPIO_PORTF_DATA_R &= ~0x02; // apagamos el led
    }
} // fin main()
