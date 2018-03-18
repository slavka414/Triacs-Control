#include "variable.h"
#include "adc.c"
#include "math.h"

TIM_HandleTypeDef htim4;

void soft_start (void) {
///////////////////////////////////////////////////  
/**********Delay before open triacs***************/
///////////////////////////////////////////////////  
  if(delay > 1) {
    delay=delay-10;
  }
  for(step = 0; step < delay; step++) {
      HAL_TIM_Base_Start_IT(&htim4);
  }
//////////////////////////////////////////////////////////////  
/********************Signals for open triacs*****************/
//////////////////////////////////////////////////////////////  
  for(number = 0; number < 4; number++){
  TRIAC_1_OPEN
  for(step = 0; step < 100; step++) {
    HAL_TIM_Base_Start_IT(&htim4);
  }
  
  TRIAC_1_CLOSE
  for(step = 0; step < 100; step++) {
    HAL_TIM_Base_Start_IT(&htim4);
  }
  }
  
  HAL_TIM_Base_Stop_IT(&htim4);
  
  if(regulator > delay) {
          delay = regulator;
        }
//////////////////////////////////////////
/********Open triac*********************/
//////////////////////////////////////////
  if (HAL_GPIO_ReadPin(PLUS_GPIO_Port, PLUS_Pin) == RESET) {
        for(step = 0; step < 100; step++) {
              HAL_TIM_Base_Start_IT(&htim4);
          }
        if(delay > 11) {
          regulator-=10;
        }
        if(regulator != delay) {
          delay = regulator;
        }
    }
  
//////////////////////////////////////////
/********Close triac**********************/
//////////////////////////////////////////
		
  if (HAL_GPIO_ReadPin(MINUS_GPIO_Port, MINUS_Pin) == RESET) {
        for(step = 0; step < 100; step++) {
            HAL_TIM_Base_Start_IT(&htim4);
        }
        if(delay < 10000) {
          regulator+=10;
        }
      if(regulator != delay) {
        delay = regulator;
      }
    }
  
 //////////////////////////////////////
 /*****Current acs712****************/
 /////////////////////////////////////
  if (delay < 1000) {
    for(step = 0; step < 200; step++) {
      HAL_TIM_Base_Start_IT(&htim4);
    }
  
  TRIAC_1_OPEN
  for(step = 0; step < 100; step++) {
    HAL_TIM_Base_Start_IT(&htim4);
  }
  TRIAC_1_CLOSE
	
  time = 360;
 current_res();
  
  TRIAC_1_OPEN
  for(step = 0; step < 100; step++) {
    HAL_TIM_Base_Start_IT(&htim4);
  }
  TRIAC_1_CLOSE
    
  }
  
  /**************************************/
  
  if ((delay < 2000) && (delay >= 1000)) {
    for(step = 0; step < 200; step++) {
      HAL_TIM_Base_Start_IT(&htim4);
    }
  
  TRIAC_1_OPEN
  for(step = 0; step < 100; step++) {
    HAL_TIM_Base_Start_IT(&htim4);
  }
  TRIAC_1_CLOSE
  
   time = 320;
	current_res();
  
  TRIAC_1_OPEN
  for(step = 0; step < 100; step++) {
    HAL_TIM_Base_Start_IT(&htim4);
  }
  TRIAC_1_CLOSE
    
  }

  /**************************************/
  
  if ((delay < 3000) && (delay >= 2000)) {
    for(step = 0; step < 200; step++) {
      HAL_TIM_Base_Start_IT(&htim4);
    }
  
  TRIAC_1_OPEN
  for(step = 0; step < 100; step++) {
    HAL_TIM_Base_Start_IT(&htim4);
  }
  TRIAC_1_CLOSE
  
   time = 280;
	current_res();
  
  TRIAC_1_OPEN
  for(step = 0; step < 100; step++) {
    HAL_TIM_Base_Start_IT(&htim4);
  }
  TRIAC_1_CLOSE

  }  
  
  /**************************************/
  
  if ((delay < 4000) && (delay >= 3000)) {
    for(step = 0; step < 100; step++) {
      HAL_TIM_Base_Start_IT(&htim4);
    }
  
  TRIAC_1_OPEN
  for(step = 0; step < 100; step++) {
    HAL_TIM_Base_Start_IT(&htim4);
  }
  TRIAC_1_CLOSE
  
   time = 240;			//250
	current_res();
  
  TRIAC_1_OPEN
  for(step = 0; step < 100; step++) {
    HAL_TIM_Base_Start_IT(&htim4);
  }
  TRIAC_1_CLOSE

  }
	
  /**************************************/
  
  if ((delay < 5000) && (delay >= 4000)) {
    for(step = 0; step < 50; step++) {
      HAL_TIM_Base_Start_IT(&htim4);
    }
  
  TRIAC_1_OPEN
  for(step = 0; step < 100; step++) {
    HAL_TIM_Base_Start_IT(&htim4);
  }
  TRIAC_1_CLOSE
  
   time = 200;			//210
	current_res();
  
  TRIAC_1_OPEN
  for(step = 0; step < 100; step++) {
    HAL_TIM_Base_Start_IT(&htim4);
  }
  TRIAC_1_CLOSE

  }
	
  /**************************************/
  
  if ((delay < 6000) && (delay >= 5000)) {
    for(step = 0; step < 50; step++) {
      HAL_TIM_Base_Start_IT(&htim4);
    }
  
  TRIAC_1_OPEN
  for(step = 0; step < 100; step++) {
    HAL_TIM_Base_Start_IT(&htim4);
  }
  TRIAC_1_CLOSE
  
   time = 160;			//170
	current_res();
  
  TRIAC_1_OPEN
  for(step = 0; step < 100; step++) {
    HAL_TIM_Base_Start_IT(&htim4);
  }
  TRIAC_1_CLOSE

  }
	
  /**************************************/
  
  if ((delay < 7000) && (delay >= 6000)) {
    for(step = 0; step < 10; step++) {
      HAL_TIM_Base_Start_IT(&htim4);
    }
  
  TRIAC_1_OPEN
  for(step = 0; step < 100; step++) {
    HAL_TIM_Base_Start_IT(&htim4);
  }
  TRIAC_1_CLOSE
  
   time = 110;			//120
	current_res();
  
  TRIAC_1_OPEN
  for(step = 0; step < 100; step++) {
    HAL_TIM_Base_Start_IT(&htim4);
  }
  TRIAC_1_CLOSE

  }
	
  /**************************************/
  
  if ((delay < 8000) && (delay >= 7000)) {
    for(step = 0; step < 10; step++) {
      HAL_TIM_Base_Start_IT(&htim4);
    }
  
  TRIAC_1_OPEN
  for(step = 0; step < 100; step++) {
    HAL_TIM_Base_Start_IT(&htim4);
  }
  TRIAC_1_CLOSE
  
   time = 80;			//90
	current_res();
  
  TRIAC_1_OPEN
  for(step = 0; step < 100; step++) {
    HAL_TIM_Base_Start_IT(&htim4);
  }
  TRIAC_1_CLOSE

  }
	
  /**************************************/
  
  if ((delay < 9000) && (delay >= 8000)) {
    for(step = 0; step < 10; step++) {
      HAL_TIM_Base_Start_IT(&htim4);
    }
  
  TRIAC_1_OPEN
  for(step = 0; step < 100; step++) {
    HAL_TIM_Base_Start_IT(&htim4);
  }
  TRIAC_1_CLOSE
  
   time = 50;			//60
	current_res();
  
  TRIAC_1_OPEN
  for(step = 0; step < 100; step++) {
    HAL_TIM_Base_Start_IT(&htim4);
  }
  TRIAC_1_CLOSE

  }
	
  /**************************************/
  
  if ((delay < 10000) && (delay >= 9000)) {
    for(step = 0; step < 10; step++) {
      HAL_TIM_Base_Start_IT(&htim4);
    }
  
  TRIAC_1_OPEN
  for(step = 0; step < 100; step++) {
    HAL_TIM_Base_Start_IT(&htim4);
  }
  TRIAC_1_CLOSE
  
   time = 15;			//20
	current_res();
  
  TRIAC_1_OPEN
  for(step = 0; step < 100; step++) {
    HAL_TIM_Base_Start_IT(&htim4);
  }
  TRIAC_1_CLOSE

  }


	
	
	if (cycle == 10) {
		current = sqrtf(data / (cycle * 50)) * 10;
		true_current = (float)current / 45;
		true_current_after_dot = (10 / (current % 45)) *10;
		data = 0;
		cycle = 0;
		//adc_max = 0;
  }
	
	/*if (cycle == 10) {
		current = data / (cycle * 50);
		true_current = (float)current / 21;
		true_current_after_dot = (10 / (current % 21)) *10;
		data = 0;
		cycle = 0;
		//adc_max = 0;
  }*/
	
	/*if (current > 13) {		//200
		error++;
		if (error > 100) {
			second++;
			error = 0;
			if (second > 3) {
				TRIAC_1_CLOSE
				while(1);
			}
		}
	}
	else {
		error = 0;
		second = 0;
	}*/
}

/////////////////////////////////////////////
/*************Timer interupt****************/
/////////////////////////////////////////////
/*void TIM4_IRQHandler(void)      {
  HAL_TIM_IRQHandler(&htim4);  
}*/

////////////////////////////////////////////
/***********Externall interrupt************/
////////////////////////////////////////////

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
  
  if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == SET) {
      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);
      HAL_TIM_Base_Start(&htim4);
      for(step = 0; step < 100; step++) {
          HAL_TIM_Base_Start_IT(&htim4);
      }
      
      soft_start();
  }


}
