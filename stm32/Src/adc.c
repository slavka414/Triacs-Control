#include "stm32f1xx_hal_adc.h"
#include "adc.h"

uint16_t adc = 0;
uint16_t i = 0;
uint64_t data = 0;
uint16_t adc_max;

ADC_HandleTypeDef hadc1;
TIM_HandleTypeDef htim4;


void acs_result(void) {
  HAL_ADC_Start(&hadc1);
  HAL_ADC_PollForConversion(&hadc1, 100);
	if ((uint32_t) HAL_ADC_GetValue(&hadc1) > adc) {
		adc_max = (uint32_t) HAL_ADC_GetValue(&hadc1);
	}
  adc = (uint32_t) HAL_ADC_GetValue(&hadc1);
  HAL_ADC_Stop(&hadc1);
}


/*void current_res (void) {
	for (i=0; i < 50; i++) {
		acs_result();
		if (adc > 1950) {			//1940
			i++;
      data = ((adc - 1950) * (adc - 1950) / 100) + data;
    }
		else break;
    for(step = 0; step < time; step++) {
      HAL_TIM_Base_Start_IT(&htim4);
    }
  }
  cycle++;
}*/

void current_res (void) {
	for (i=0; i < 50; i++) {
		acs_result();
		i++;
		if (adc > 1950) {			//1940
			
      data = (adc - 1950) + data;
    }
    for(step = 0; step < time; step++) {
      HAL_TIM_Base_Start_IT(&htim4);
    }
  }
  cycle++;
}
