#include "EV3Servo-lib-UW.c"
const int STRUM_POSITION = 45;

/*
Function 6: strum
Moves the strumming arm in a two dimensional plane as to simulate strumming a guitar.
pre: boolean passed by reference to keep track of position, time measure float, and base tempo integer.
post: strumming arm is moved in accordace to the strum position angle.
*/
void strum(bool & isRight, float timeMeasure, int baseTempo)
{
	while(time1[T1] < timeMeasure * baseTempo){}

	if (isRight)
	{
		setServoPosition(S1, 1, STRUM_POSITION);
		isRight = false;
	}
	else
	{
		setServoPosition(S1, 1, -STRUM_POSITION);
		isRight = true;
	}
}

/*
DRIVER:
Test Function by running the code of the function through a task main.
Calls for movement of the strumming arm in both directions.
*/
task main()
{
	SensorType[S1]=sensorI2CCustom9V;
	bool position = true;
	float timeMeasure = 2000; //2 seconds
	float baseTempo = 0.5; // half tempo
	int counter = 0;

   //Each strum in this test case takes 1 second (1000ms), because the tempo of 0.5 halves the time of 2 seconds

	while(counter < 2)
	{
	strum(position, timeMeasure, baseTempo);
	counter++;
    }
}
/*
Strummer tested with times of:

Test set 1:

timeMeasure: 1 seconds
baseTempo: 1

timeMeasure: 1 seconds
baseTempo: 0.75

timeMeasure: 1 seconds
baseTempo: 0.5

timeMeasure: 1 seconds
baseTempo: 0.4

Test set 2:

timeMeasure: 2 seconds
baseTempo: 1

timeMeasure: 2 seconds
baseTempo: 0.75

timeMeasure: 2 seconds
baseTempo: 0.5

timeMeasure: 2 seconds
baseTempo: 0.4

Test set 3:

timeMeasure: 3 seconds
baseTempo: 1

timeMeasure: 3 seconds
baseTempo: 0.75

timeMeasure: 3 seconds
baseTempo: 0.5

timeMeasure: 3 seconds
baseTempo: 0.4

Test set 4:

timeMeasure: 4 seconds
baseTempo: 1

timeMeasure: 4 seconds
baseTempo: 0.75

timeMeasure: 4 seconds
baseTempo: 0.5

timeMeasure: 4 seconds
baseTempo: 0.4

*/
