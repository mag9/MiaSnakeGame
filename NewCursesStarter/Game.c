
#include <stdio.h>
#include "CursesSetup.h"
#include <math.h>

#define MAX_ROWS 40
#define SCALING_FACTOR 100

void game() {

	//Local declarations
	char userInput;
	int charX;
	int charY;

	//General setup and clear curse window
	SetupAndClearCursesWindow();

	//Do the main loop
	while (userInput != 'q') {

			//Clear the entire window
			clear();

			//Display the default info
			mvprintw(0, 1, "Press Q to exit");

			//Make sure the screen updates
			refresh();

			//Get the user input
			userInput = getch();

			//TODO - some more stuff to handle user input here
			if (userInput == 'w') {
				charY--;
			}
			else if (userInput == 'a') {
				charX--;
			}
			else if (userInput == 's') {
				charY++;
			}
			else if (userInput == 'd')
			{
				charX++;
			}
			else if (userInput == 'q')
			{
				endwin();
			}

			//Sleep
			sleep_crossPlatform(50);
		}

	return 0;
}