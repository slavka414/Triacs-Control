extern USBD_HandleTypeDef hUsbDeviceFS;
uint8_t dataToSend[5];
uint8_t btn_stat = 0;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim3) {
	//uint16_t temp;
	if(btn_stat==0)	{dataToSend[0]=6;	dataToSend[1]=1;}
	else if(btn_stat==1)	{dataToSend[0]=6;	dataToSend[1]=0;}
	else if(btn_stat==2)	{dataToSend[0]=5;	dataToSend[1]=1;}
	else if(btn_stat==3)	{dataToSend[0]=5;	dataToSend[1]=0;}
	/*dataToSend[2]='H';
	dataToSend[3]='I';
	dataToSend[4]='D';*/
	
	/*temp = current;
	dataToSend[0] = temp/1;
	temp = current;
	dataToSend[1] = temp/10;
	temp = current;
	dataToSend[2] = temp/100;
	temp = current;
	dataToSend[3] = temp/1000;
	temp = current;
	dataToSend[4] = temp/10000;*/
	
	dataToSend[2] = true_current;
	dataToSend[3] = true_current_after_dot;
	
	USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, dataToSend, 5);
	btn_stat++;
	if (btn_stat > 3) btn_stat = 0;
}
