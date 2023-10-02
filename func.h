#ifndef _FUNC_H
#define _FUNC_H

extern uint16 vehicleSpeed;
extern uint8 eng_Status;

#define eng_ON 1
#define eng_OFF 0

#define AC_ON 1
#define AC_OFF 0

#define engTempControl_ON 1 
#define engTempControl_OFF 0 

uint8 systemWindowDisplay(void);
uint8 sensorsSetMenu(void);
void trafficLightColor(void);
void AC(void);
void engineTempSensor(void);
void ifSpeed30(void);
void displayVehicleState(void);


#endif