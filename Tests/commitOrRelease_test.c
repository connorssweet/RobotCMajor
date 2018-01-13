const int ENC_LIM_Z = -200;
const int COMMIT_POWER = 100;

/*
Function 5: commitOrRelease
Toggles position of the Z motor in order to apply pressure to strings in chord
formation.
pre: port for Z motor.
post: The Z motor will either be lifted or lowered depending on its prior
position. If the motor was elevated, it will now be lowered, and vice-versa.
*/
void commitOrRelease(bool isUp)
{
	//raise Z
	if(!isUp)
	{
		motor[motorC] = COMMIT_POWER;
		while(nMotorEncoder[motorC] < 0){}
	}

	//lower z
	else
	{
		motor[motorC] = -COMMIT_POWER;
		while(nMotorEncoder[motorC] > ENC_LIM_Z){}
	}
	motor[motorC]=  0;
}

/*
DRIVER:
Test Function by running the code of the function through a task main.
Raise and lower the Z axis multiple concurrent times to test response and durability of hardware.
*/
task main()
{
	//Assume z-axis begins at maximum elevation
	bool isUp = true;
	int count = 0;
	while(count < 5)
	{
	commitOrRelease(isUp);
	isUp = false;
	commitOrRelease(isUp);
	isUp = true;
	count++;
	}
}
