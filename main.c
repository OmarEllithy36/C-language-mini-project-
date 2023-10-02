#include <stdio.h>
#include <stdlib.h>
#include"data_types.h"
#include "func.h"

int main(void)
{
    uint8 mainOption,quit1=0,menuOption,quit2=0;


    while(quit1==0)
    {
        system("cls");
        displayVehicleState();
        mainOption = systemWindowDisplay();

        switch(mainOption)
        {
            case 'a':
                system("cls");
                eng_Status = eng_ON;
                while(quit2==0)
                {
                    system("cls");
                    displayVehicleState();
                    menuOption = sensorsSetMenu();
                    switch(menuOption)
                    {
                        case 'a': quit2=1; break;
                        case 'b': trafficLightColor(); break;
                        case 'c': AC(); break;
                        case 'd': engineTempSensor(); break;
                        case 'e': quit2=1; break;
                    }
                    if(vehicleSpeed == 30){
                        ifSpeed30();
                    }
                }
                quit2 = 0;
                break;

            case 'b': eng_Status = eng_OFF; break;

            case 'c': quit1=1; break;
        }

        if(vehicleSpeed == 30){
            ifSpeed30();
        }
    }


    return 0;
}
