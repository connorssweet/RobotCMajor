#include "EV3_FileIO.c"
const int MAX_SIZE = 75;
int chordPositionX[MAX_SIZE];
int chordPositionY[MAX_SIZE];
int timings [MAX_SIZE];
const int positionX[12] = {60, 80, 0, 20, 40, 60, 80, 0, 20, 0, 20, 40};
const int positionY[12] = {-90, -90, 0, 0, 0, 0, 0, 90, 90, -90, -90, -90};

/*
Function 1: chordNum
Receives a character that represents a guitar chord and returns an integer value to the character to be used by the EV3 robot.
pre: char from the chord array that was filled by the song text file.
post: returns the integer value required for the EV3 to correctly play the chord.
*/
int chordNum(char chordLetter)
{
    switch (chordLetter)
    {
        case 'a':
            return 0;
        case 'A':
            return 1;
        case 'b':
            return 2;
        case 'B':
            return 3;
        case 'C':
            return 4;
        case 'd':
            return 5;
        case 'D':
            return 6;
        case 'e':
            return 7;
        case 'E':
            return 8;
        case 'F':
            return 9;
        case 'g':
            return 10;
        case 'G':
            return 11;
    }
    return 0;
}

/*
Function 2: Get Integer Time Value
Determines strum time value based on symbol read from file.
pre: current time symbol read from file.
post: returns Integer correspoding to time value in accordance to symbol.
*/
int getTimeValue(char timeSymbol)
{
	switch(timeSymbol)
	{
		case '_':
			return 400;
		case ':':
			return 300;
		case '/':
			return 200;
		case '.':
			return 100;
		case ',':
			return 50;
	};
	return 0;
}

/*
Function 3: readFile
Reads chord and strum files into two parallel arrays and assigns chord
positions and strum times to indices of their corresponding arrays in accordance
to the values returned from the 'getChordPosValue' and the 'getStrumTimeValue'
functions.
pre: TFileHandle, names of chord and strum files, arrays for chords and strums.
post: Returns the total number of indices in each array and populates arrays
with chords and strum times respectively.
*/
int readFile(TFileHandle & fin, int* chordsPositionX, int* chordsPositionY, int* timings)
{
	//instantiate chord counter
	int count = 0;
	char currentChord;
	char timingSymbol;

	while(readCharPC(fin, currentChord) && readCharPC(fin, timingSymbol))
	{
		chordsPositionX[count] = positionX[chordNum(currentChord)];
		chordsPositionY[count] = positionY[chordNum(currentChord)];
		timings[count] = getTimeValue(timingSymbol);

		count++;
	}
	return count;
}

/*
DRIVER:
Test Function by running the code of the function through a task main.
Reads and outputs file on the EV3 display.
*/
task main()
{
	TFileHandle fin;

	if(!openReadPC(fin, "testRead.txt"))
	{
		displayString(0, "Error reading file");
		wait1Msec(10000);
		stopAllTasks();
	}

	for (int count = 0; count < MAX_SIZE; count++)
	{
		chordPositionX[count] = 0;
		chordPositionY[count] = 0;
		timings[count] = 0;
	}

	int numberChords = readFile (fin, chordPositionX, chordPositionY, timings);

    displayString(0, "%i", numberChords);
    for (int index = 0; index < numberChords; index++)
		displayString(index+1, "(%i, %i, %f)", chordPositionX[index], chordPositionY[index], timings[index]);

		wait1Msec(10000);
	closeFilePC(fin);
}

/*
testRead contents:
 G_ C_ E_ D_
 A. A. A. A.
 OO OO OO OO

 12
 (40, -90, 400)
 (40, 0, 400)
 (20, 90, 400)
 (80, 0, 400)
 (80, -90, 100)
 (80, -90, 100)
 (80, -90, 100)
 (80, -90, 100)
 (60, -90, 0)
 (60, -90, 0)
 (60, -90, 0)
 (60, -90, 0)
 */
