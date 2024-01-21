/*
 ============================================================================
 Name        : Omar Salah El Din
 Examiner      :Mohamed Tarek
 Version     : 3
 Date        : 7/9/2021
 Description : Project 1 Embedded course by Mohamed Tarek
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/*-----------------------------------------------------------------------
 * defined a bool to check on the while loop and Exit from it in case 'c' and some states
 *-----------------------------------------*/

#define true 1
#define false 0
typedef unsigned char bool;
bool engine_Status=false,Vechile_status=false,boolen=true,Engine_Temperature_State=false,AC=false;

/*------------------------------------------------------------------------
 * Prototype function
 * -----------------------------------------------------------------------*/

void turn_off_Engin(int *speed);
void traffic(unsigned char color,int *speed);
int room_temperature_data(int room);
int based_on_engine_temperature(int engine_temperature);
void display(int speed ,int room,int engine_temperature);
void speed_Test(int *speed,int *room,int *engine_temp);

/*------------------------------------------------------------------------
 * Main function
 *------------------------------------------------------------------------*/

int main(void) {
	/*
	 * line 42 &43 for the bug in eclipse to take the input in when make print()
	 */
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);
	/*
	 * Variables declared
	 */
	unsigned char input,traffic_light;
	int speed,room_temperature=25,Engine_Temperature=90;//Assume that the initial room temperature is 25 degree and engine temperature 110

		while(boolen)
		{
			printf(" Menu\n-----------------\n a.Turn on the vehicle engine\n-----------------\n b.Turn off the vehicle engine \n");
			printf("-----------------\n c. Quit the system\n....\n");
		   scanf(" %c",&input);
		   /*
		    * Check if the choice isn't correct will Enter that message and return to the while loop till the user enter the right choice
		    */
		   	   switch(input)
		   	     {
		   	   case 'a':

		   		   Vechile_status=true;
		   		   engine_Status=true;
		   		   printf("You choose turn on the vehicle\n.....\n");
		   		   printf("Sensors Set Menu\n-----------------\n a)Turn off the engine \n -----------------\n b)Set the traffic light color\n-----------------\n");
		   		   printf(" c)Set the room temperature \n-----------------\n d)Set the engine temperature\n-----------------\n");
		   		   scanf(" %c",&input);
		   		   switch(input)
		   		   {
		   		   case'a':
		   			turn_off_Engin(&speed);//The temperature of engine should be zero when we turn it off
		   			break;
		   		   case'b':
		   			printf("please enter the current traffic color G  O  R\n");
		   				scanf(" %c",&traffic_light);
		   			   traffic(traffic_light,&speed);
		   			   break;
		   		   case'c':
		   			printf("please enter the current room temperature\n");
		   				scanf(" %d",&room_temperature);
		   				room_temperature=room_temperature_data(room_temperature);
		   			   break;
		   		   case'd':
		   			printf("please enter the current Engine Temperature\n");
		   				scanf(" %d",&Engine_Temperature);
		   				Engine_Temperature=based_on_engine_temperature(Engine_Temperature);
		   			   break;
		   		   default:
	   		   		   printf("Please check the character you entered\n....\n");
	   		   		   break;
		   		   }
		   		  /*
		   		   * Speed test change the AC state ,room temperature and engine temperature.
		   		   */
		   		   speed_Test(&speed,&room_temperature,&Engine_Temperature);
		   		   /*
		   		    * After the speed test will check the room temperature conditions and engine temperature
		   		    */

		   		   /*
		   		    * Display function is activate only when the user choose turn on Vehicle even if the engine is turn off
		   		    */
		   		   display(speed,room_temperature,Engine_Temperature);
		   	    	/*------------Menu 1 case 'a' break-------------*/
		   		   break;
		   		   /*
		   		    * Case 'b' to turn off the vehicle and return to the loop ask about first Menu again
		   		    */
		   	   case'b':
		   		   printf("You choose turn off the vehicle\n....\n");
		   		   Vechile_status=false;
		   		   break;
		   		   /*
		   		    * Case 'c' turn off the program
		   		    */
		   	   case'c':
		   		   printf("You choose to quit the program\n....\n Have nice day Mohamed Tarek\n.....\n");
		   		   boolen=false;
		   		   break;
		   	   default:
				   printf("Please check the character you entered\n....\n");
		   		   break;

		   	     }
		   	   }

		   	return 0;
		   }

/*------------------------------------------------------------------------
 * Declaration function
 * -----------------------------------------------------------------------*/

/*------------------------------------------------------------------------
 * Function to turn off the engine
 *-----------------------------------------------------------------------*/

void turn_off_Engin(int *speed)
{
	printf("You choose to turn off the engine\n....\n");
	engine_Status=false;
	*speed=0;
}

/*------------------------------------------------------------------------
 * Function Traffic color data
 *-----------------------------------------------------------------------*/

void traffic(unsigned char color,int *speed)
{

	if(color=='G'||color=='g')
   {
	      *speed=100;
   }
	else if(color=='O'||color=='o')
   {
         *speed=30;
   }
	else if(color=='R'||color=='r')
    {
    	*speed=0;
    }
	else
	{
		printf("WRONG char!\n");
	}
}

/*------------------------------------------------------------------------
 * Function To activate the AC and change room temperature
 *-----------------------------------------------------------------------*/

int room_temperature_data(int room)
{
	if(10>room)
	{
		AC=true;
		room=20;
	}
	else if(30<room)
	{
		AC=true;
		room=20;
	}
	else
		AC=false;
	return room;
}

/*------------------------------------------------------------------------
 * Function Engine temperature data
 *-----------------------------------------------------------------------*/

int based_on_engine_temperature(int engine_temperature)
{
	if(engine_temperature<100)
	{
		Engine_Temperature_State=true;//Turn on Engine_Temperature_State_controll
		engine_temperature=125;
	}
	else if(engine_temperature>150)
		{
		Engine_Temperature_State=true;// Turn on Engine_Temperature_State_controll
			engine_temperature=125;
		}
	else
	{
		Engine_Temperature_State=false;//Turn off Engine_Temperature_State_controll

	}
	return engine_temperature;

}
/*------------------------------------------------------------------------
 * Function To test the speed if (speed==30)
 *-----------------------------------------------------------------------*/
void speed_Test(int *speed,int *room,int *engine_temp)
{
	if(30==*speed)
		{
		AC=1;
		*room=((*room)*1.25)+1;
		Engine_Temperature_State=true;
		*engine_temp=((*engine_temp)*1.25)+1;
		}
}
/*------------------------------------------------------------------------
 * Function To display all contents(Engine states,AC states,Speed,Room Temperature,Engine controll states).
 *-----------------------------------------------------------------------*/
void display(int speed ,int room,int engine_temperature)
{
	if( Vechile_status==true)
			{
				printf("1-The vehicle is on \n");
			}
			else
			{
				printf("1-The vehicle is off \n");

			}
	if( engine_Status==true)
				{
					printf("2-The Engine is on \n");
				}
				else
				{
					printf("2-The Engine is off \n");

				}
		if(AC==true)
			{
				printf("3-The AC is on \n");
			}
			else
			{
				printf("3-The AC is off \n");

			}
		printf("4-The current speed is %d \n",speed);
		printf("5-The current room temperature is %d \n",room);
		if(Engine_Temperature_State==true)
				{
					printf("6-The engine temperature controller is on \n");
				}
				else
				{
					printf("6-The engine temperature controller is off \n");

				}
		printf("7-The current engine temperature is %d \n",engine_temperature);
}
