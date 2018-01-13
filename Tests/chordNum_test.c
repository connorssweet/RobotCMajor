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
DRIVER:
Test Function by running the code of the function through a task main.
Run through every return case within the switch statement and print the values returned to the screen.
*/
task main()
{
	displayString(0, "Chord Number a(Ab): %d", chordNum('a'));
	displayString(1, "Chord Number A: %d", chordNum('A'));
	displayString(2, "Chord Number b(Bb): %d", chordNum('b'));
	displayString(3, "Chord Number B: %d", chordNum('B'));
	displayString(4, "Chord Number C: %d", chordNum('C'));
	displayString(5, "Chord Number d (Db): %d", chordNum('d'));
	displayString(6, "Chord Number D: %d", chordNum('D'));
	displayString(7, "Chord Number e (Eb): %d", chordNum('e'));
	displayString(8, "Chord Number E: %d", chordNum('E'));
	displayString(9, "Chord Number F: %d", chordNum('F'));
	displayString(10, "Chord Number g (Gb): %d", chordNum('g'));
	displayString(11, "Chord Number G: %d", chordNum('G'));
	displayString(12, "Chord Number Non-valid: %d", chordNum('O'));

	wait1Msec(10000);
}

/*
Code Output:

Chord Number a(Ab): 0
Chord Number A: 1
Chord Number b(Bb): 2
Chord Number B: 3
Chord Number C: 4
Chord Number d (Db): 5
Chord Number D: 6
Chord Number e (Eb): 7
Chord Number E: 8
Chord Number F: 9
Chord Number g (Gb): 10
Chord Number G: 11
Chord Number Non-valid: 0
*/
