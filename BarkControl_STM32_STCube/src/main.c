
/***********************************************************************
*! \file:                   main.c
*  \projekt:                BarkControl
*  \created on:             2022 07 25
*  \author:                 R. Gräber
*  \version:                0
*  \history:                -
*  \brief
***********************************************************************/
 
/***********************************************************************
* Includes
***********************************************************************/
#include "mbed.h"
#include "user_config.h"
/***********************************************************************
* Informations
***********************************************************************/
//https://www.dyclassroom.com/c/c-pointers-and-two-dimensional-array
//https://os.mbed.com/platforms/ST-Nucleo-L476RG/
/***********************************************************************
* Declarations
***********************************************************************/
AnalogIn analog_mic(A0);                      // Create the analog pin object
Ticker time_up;
#ifdef _debug_enable_
    Serial debugserial(CONSOLE_TX, CONSOLE_RX, 115200); // tx, rx
    char debug_buffer[1024];
    char *ptr_debug_buffer;
#endif

/***********************************************************************
* Global Variable
***********************************************************************/
 
/***********************************************************************
* Constant
***********************************************************************/
 
/***********************************************************************
* Local Funtions
***********************************************************************/
 
void read_adc_value_from_mic(void);

/***********************************************************************
*! \fn          int main()
*  \brief       startup function
*  \param       none
*  \exception   none
*  \return      none
***********************************************************************/
int main(){
    // Initialise the digital pin LED1 as an output
    DigitalOut led(LED1);
    time_up.attach(&read_adc_value_from_mic, adc_mic_task_timing);
    while (true) {
        led = !led;
        ThisThread::sleep_for(BLINKING_RATE);
    }
}

/***********************************************************************
*! \fn          void read_adc_value_from_mic(void)
*  \brief       read the adc channel with the mic to buffer
*  \param       none
*  \exception   none
*  \return      none
***********************************************************************/
void read_adc_value_from_mic(void){

    analog_mic.read_u16();
#ifdef _debug_enable_
    sprintf(ptr_debug_buffer, "This is a Test\r\n");
    debugserial.write(ptr_debug_buffer, sizeof(ptr_debug_buffer));
#endif

}