/*
Function 2: Get Float Time Value
Determines strum time value based on symbol read from file.
pre: current time symbol read from file.
post: returns float correspoding to time value in accordance to symbol.
*/
int getTimeValue(char timeSymbol)
{
	switch(timeSymbol)
	{
		case '_':
			return 4.0;
		case ':':
			return 3.0;
		case '/':
			return 2.0;
		case '.':
			return 1.0;
		case ',':
			return 0.5;
	}
	return 0;
}

/*
DRIVER:
Test Function by running the code of the function through a task main.
Run through every return case within the switch statement and print the values returned to the screen.
*/
task main()
{
	displayString(0,"Time value: %f", getTimeValue('_'));
	displayString(1,"Time value: %f", getTimeValue(':'));
	displayString(2,"Time value: %f", getTimeValue('/'));
	displayString(3,"Time value: %f", getTimeValue('.'));
	displayString(4,"Time value: %f", getTimeValue(','));
	displayString(5,"Time value: %f", getTimeValue('@'));

	wait1Msec(10000);
}

/*
Code Output:

Time value: 4.000000
Time value: 3.000000
Time value: 2.000000
Time value: 1.000000
Time value: 0.500000
Time value: 0.000000
*/
