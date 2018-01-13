#include "EV3Servo-lib-UW.c"

const int POSITION_X[12] = {-340, -450, 0, -105, -210, -340, -450, 0, -105, 0, -105, -210};
const int POSITION_Y[12] = {30, 30, 0, 0, 0, 0, 0, 85, 85, 30, 30, 30};
const int POWER_X = 75;

/*
Function 4: setGantryPos
Adjust motors controlling X and Y direction of gantry planes to set chord
formation to proper position in accordance to the encoder limits gathered from
the 'chordPosDist' function.
pre: current index of int chord array, ports for X and Y motors.
post: runs motors until gantry is adjusted to intended position.
*/
void setGantryPos(int chordPositionX, int chordPositionY, int lastPositionX)
{
	int distanceX = chordPositionX - lastPositionX;

	if (distanceX < 0)
	{
		motor[motorA] = motor[motorB] = -POWER_X;
		while(nMotorEncoder[motorA] > chordPositionX){}
	}
	else
	{
		motor[motorA] = motor[motorB] = POWER_X;
		while(nMotorEncoder[motorA] < chordPositionX){}
	}
	motor[motorA] = motor[motorB] = 0;

	setServoPosition(S1, 1, chordPositionY);
	setServoPosition(S1, 2, -chordPositionY);
}
/*
DRIVER:
Test Function by running the code of the function through a task main.
Go to every fret and string according to encoder values.
*/
task main()
{
	SensorType[S1] = sensorI2CCustom9V;
	//Assume initial position at first fret, standard Y servo position
	setGantryPos(POSITION_X[0], POSITION_Y[0], 0);
	wait1Msec(500);
	for(int index = 1; index < 12; index++)
	{
		setGantryPos(POSITION_X[index], POSITION_Y[index], POSITION_X[index-1]);
		wait1Msec(500);
	}

	for(int index = 11; index > 0; --index)
	{
		setGantryPos(POSITION_X[index], POSITION_Y[index], POSITION_X[index-1]);
		wait1Msec(500);
	}
	setGantryPos(POSITION_X[0], POSITION_Y[0], 0);
	wait1Msec(500);

}
