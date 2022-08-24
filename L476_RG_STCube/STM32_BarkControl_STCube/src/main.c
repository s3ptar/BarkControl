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
#if F0
#include "stm32f0xx_hal.h"
#elif F1
#include "stm32f1xx_hal.h"
#elif F2
#include "stm32f2xx_hal.h"
#elif F3
#include "stm32f3xx_hal.h"
#elif F4
#include "stm32f4xx_hal.h"
#elif F7
#include "stm32f7xx_hal.h"
#elif L0
#include "stm32l0xx_hal.h"
#elif L1
#include "stm32l1xx_hal.h"
#elif L4
#include "stm32l4xx_hal.h"
#else
#error "Unsupported STM32 Family"
#endif

/***********************************************************************
* Informations
***********************************************************************/
//https://github.com/platformio/platform-ststm32/tree/master/examples
/***********************************************************************
* Declarations
***********************************************************************/

#define LED_PIN                                GPIO_PIN_5
#define LED_GPIO_PORT                          GPIOA
#define LED_GPIO_CLK_ENABLE()                  __HAL_RCC_GPIOA_CLK_ENABLE()


/***********************************************************************
* Global Variable
***********************************************************************/
 
/***********************************************************************
* Constant
***********************************************************************/
 
/***********************************************************************
* Local Funtions
***********************************************************************/


/***********************************************************************
*! \fn          int main()
*  \brief       startup function
*  \param       none
*  \exception   none
*  \return      none
***********************************************************************/
int main(void){

    HAL_Init();
  
    LED_GPIO_CLK_ENABLE();
  
    GPIO_InitTypeDef GPIO_InitStruct;
  
    GPIO_InitStruct.Pin = LED_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct); 

    while (1){
        HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_PIN);
    
        HAL_Delay(5000);
    }
}

/***********************************************************************
*! \fn          void SysTick_Handler(void)
*  \brief       delay handler
*  \param       none
*  \exception   none
*  \return      none
***********************************************************************/
void SysTick_Handler(void){
    HAL_IncTick();
}

/***********************************************************************
*! \fn          void NMI_Handler(void)
*  \brief       none maskable interrupt
*  \param       none
*  \exception   none
*  \return      none
***********************************************************************/
void NMI_Handler(void){
}

/***********************************************************************
*! \fn          void HardFault_Handler(void)
*  \brief       Hard Fault handler
*  \param       none
*  \exception   none
*  \return      none
***********************************************************************/
void HardFault_Handler(void){
    while (1) {}
}

/***********************************************************************
*! \fn          void MemManage_Handler(void)
*  \brief       Memnory Manager
*  \param       none
*  \exception   none
*  \return      none
***********************************************************************/
void MemManage_Handler(void){
    while (1) {}
}

/***********************************************************************
*! \fn          void BusFault_Handler(void)
*  \brief       Bus fault handler
*  \param       none
*  \exception   none
*  \return      none
***********************************************************************/
void BusFault_Handler(void){
    while (1) {}
}

/***********************************************************************
*! \fn          void UsageFault_Handler(void)
*  \brief       UsageFault Handler
*  \param       none
*  \exception   none
*  \return      none
***********************************************************************/
void UsageFault_Handler(void){
    while (1) {}
}

/***********************************************************************
*! \fn          void SVC_Handler(void)
*  \brief       SVH Handler
*  \param       none
*  \exception   none
*  \return      none
***********************************************************************/
void SVC_Handler(void){
}

/***********************************************************************
*! \fn          void DebugMon_Handler(void)
*  \brief       Debug Monitor
*  \param       none
*  \exception   none
*  \return      none
***********************************************************************/
void DebugMon_Handler(void){
}

/***********************************************************************
*! \fn          void PendSV_Handler(void)
*  \brief       PendSV Handler
*  \param       none
*  \exception   none
*  \return      none
***********************************************************************/
void PendSV_Handler(void){
}