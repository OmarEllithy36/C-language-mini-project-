#include <stdio.h>
#include <stdlib.h>
#include "data_types.h"
#include "func.h"

uint16 vehicleSpeed = 0;
uint8 eng_Status = 0;
uint8 AC_Status = 0;
sint32 roomTemp = 0;
uint32 engTemp = 0;
uint8 engTempControl_Status = 0;


uint8 systemWindowDisplay(void)
{
	/* This function display main system window*/

	uint8 mainInput;

	printf("Main Control System\n\n");
	printf("a: Turn on the vehicle engine\n");
	printf("b: Turn off the vehicle engine\n");
	printf("c: Quit the system\n");

	/*get input from user*/
	printf("Chose Task To do: ");
	scanf(" %c", &mainInput);

	/*Check if the user entered invalid input*/
	while(!(mainInput=='a' || mainInput=='b' || mainInput=='c')){
		printf("\n\nInvalid Input,Please Enter Valid Option: ");
		scanf(" %c", &mainInput);
	}

	return mainInput; //return the chosen input
}

uint8 sensorsSetMenu(void)
{
	/* This function display Sensors set menu window*/

	uint8 sensorInput;

	printf("Sensors Set Menu\n\n");
	printf("a: Turn Off The Engine\n");
	printf("b: Set The Traffic Light Color\n");
	printf("c: Set The Room Temperature\n");
	printf("d: Set The Engine Temperature\n");
	printf("e: Go Back To Main window\n");

	/*get input from user*/
	printf("Chose Task To do: ");
	scanf(" %c", &sensorInput);

	if(sensorInput == 'a'){
        eng_Status = eng_OFF;
	}

	/*Check if the user entered invalid input*/
	while(!(sensorInput=='a' || sensorInput=='b' || sensorInput=='c' || sensorInput=='d' || sensorInput=='e')){
		printf("\n\nInvalid Input,Please Enter Valid Option: ");
		scanf(" %c", &sensorInput);
	}

	return sensorInput; //return the chosen input
}

void trafficLightColor(void)
{
	/* This function control vehicle speed by traffic light color*/

	system("cls");

	uint8 lightColor;

	/* read traffic light data from the sensor*/
	printf("\n\nTraffic Light Color is: ");
	scanf(" %c", &lightColor);

	/*Check if the sensor red invalid input*/
	while(!(lightColor=='G' || lightColor=='O' || lightColor=='R')){
		printf("\n\nInvalid Input,Read form sensor again: ");
		scanf(" %c", &lightColor);
	}

	/* change vehicle speed based on input from the sensor*/
	switch(lightColor)
	{
		case 'G': vehicleSpeed = 100; break;
		case 'O': vehicleSpeed = 30; break;
		case 'R': vehicleSpeed = 0; break;
    }
}

void AC(void)
{
	/*This function control The AC */

	system("cls");

	/* read traffic light data from the sensor*/
	printf("\n\nRoom Temperature is: ");
	scanf(" %d", &roomTemp);

	/* Set AC status and room temperature*/
	if(roomTemp < 10){
		AC_Status = AC_ON;
		roomTemp = 20;
	}else if(roomTemp > 30){
		AC_Status = AC_ON;
		roomTemp = 20;
	}else{
		AC_Status = AC_OFF;
	}
}

void engineTempSensor(void)
{
	/*This function control The AC */

	system("cls");

	/* read traffic light data from the sensor*/
	printf("\n\nEngine Temperature is: ");
	scanf(" %d", &engTemp);

	/* Set Engine Temperature Controller status and control and engine temperature*/
	if(engTemp < 100){
		engTempControl_Status = engTempControl_ON;
		engTemp = 125;
	}else if(engTemp > 150){
		engTempControl_Status = engTempControl_ON;
		engTemp = 125;
	}else{
		engTempControl_Status = engTempControl_OFF;
	}
}

void ifSpeed30(void)
{
    system("cls");

    printf("The speed now is 30 Km\h there will be some changes\n\n");

	/* turn AC on and change room temperature*/
	if(AC_Status == AC_OFF){
		printf("Room Temperature is: ");
		scanf(" %d", &roomTemp);

		AC_Status = AC_ON;
		roomTemp = roomTemp * (5/4) + 1;
	}

	/* turn Engine Temperature Controller on and change engine temperature*/
	if(engTempControl_Status == engTempControl_OFF){
		printf("\n\nEngine Temperature is: ");
		scanf(" %d", &engTemp);

		engTempControl_Status = engTempControl_ON;
		engTemp = engTemp * (5/4) + 1;
	}
}

void displayVehicleState(void)
{
	printf("Vehicle Status: \n\n");

	if(eng_Status == eng_ON){
		printf("Engine is On\n");
	}else if(eng_Status == eng_OFF){
		printf("Engine is Off\n");
	}

	if(AC_Status == AC_ON){
		printf("AC is On\n");
	}else if(AC_Status == AC_OFF){
		printf("AC is Off\n");
	}

	printf("Vehicle Speed is %d\n",vehicleSpeed);
	printf("Room Temperature is %d\n",roomTemp);

	if(engTempControl_Status == engTempControl_ON){
		printf("Engine Temperature Controller State is On\n");
	}else if(engTempControl_Status == engTempControl_OFF){
		printf("Engine Temperature Controller State is Off\n");
	}


	printf("Engine Temperature is %d\n\n",engTemp);

}


