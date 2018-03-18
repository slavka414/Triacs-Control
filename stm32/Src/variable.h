#ifndef VARIABLE_H_
#define VARIABLE_H_

uint16_t delay = 11000;
uint16_t step;
uint16_t regulator = 0;

uint8_t cycle = 0;
uint16_t current = 0;

uint16_t time = 3;

uint8_t error = 0;

uint8_t second = 0;

uint8_t number;


uint8_t true_current = 0;
uint8_t true_current_after_dot = 0;

#define TRIAC_1_CLOSE       HAL_GPIO_WritePin(TRIAC_OPEN_GPIO_Port, TRIAC_OPEN_Pin, GPIO_PIN_RESET);
#define TRIAC_1_OPEN       HAL_GPIO_WritePin(TRIAC_OPEN_GPIO_Port, TRIAC_OPEN_Pin, GPIO_PIN_SET);

#endif 
