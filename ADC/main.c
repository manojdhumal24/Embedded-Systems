#include "stm32f3xx.h"                  // Device header


/* 1. Enable the clock for the ADC & -> GPIO RCC_APB2ENR <36 MHz*/
/* 2. set GPIO pin to analog Mode */
/* 3. The ADC is powered on by setting the ADON bit in the ADC_CR2 register*/
/* 4. Conversion starts when either the SWSTART or the JSWSTART bit is set*/
/* 5. L[3:0] bits in the ADC_SQR1 register total number of conversion.*/
/* 6. Regular channels and their order in the conversion sequence must be selected in the ADC_SQRx registers.*/


volatile  uint32_t adc_val ;

void ADC_IRQHandler(void)
{

adc_val = ADC1->DR ;
ADC1->CR |= (1<<30) ;
}

int main (void)
{


RCC->AHBENR |= (1<<17) ;
RCC->AHBENR |= (1<<18) ;

GPIOA->MODER |= (1<<0) | (1<<8);

ADC1->SQR1 &= ~(0x0Fu << 20);
ADC1->SQR3 = 0X05 ;

ADC1->CR  |= (1<<5) ;
NVIC_EnableIRQ(ADC1_2_IRQn);

ADC1->CR |= (1<<0) ;
ADC1->CR |= (1<<28);

while(1)
{

}


}