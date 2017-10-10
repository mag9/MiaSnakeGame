#include <stdio.h>
#include "CursesSetup.h"
#include <math.h>

void playGame();

int main(void)
{
	char userName[100];		
	int intVar = 0;			   
	int menu = 0;
	int test = 0;

	printf("Please enter your name: ");
	scanf("%s", &userName[0]);

    SetupAndClearCursesWindow();

	int x_cord = 0, y_cord = 0, wall_counter = 0; 

	menu = 1;
    
	while (getch() != 'q' && menu == 1)
	{

		mvprintw(60, 40, "Press Q to exit");
		mvprintw(3, 30, "Welcome, %s.", userName);
		mvprintw(4, 31, "Let's Play.");

		mvprintw(23, 12, "####### ##    ##     ###    ##    ## ########");
		mvprintw(24, 12, "##   ## ###   ##    ## ##   ##   ##  ##");
		mvprintw(25, 12, "##      ####  ##   ##   ##  ##  ##   ##");
		mvprintw(26, 12, "####### ## ## ##  ##     ## #####    ######");
		mvprintw(27, 12, "     ## ##  ####  ######### ##  ##   ##");
		mvprintw(28, 12, "##   ## ##   ###  ##     ## ##   ##  ##");
		mvprintw(29, 12, "####### ##    ##  ##     ## ##    ## ########");

		mvprintw(10, 1, "$                ");
		mvprintw(11, 1, "$$              $$              ");
		mvprintw(12, 1, "$$$            $$$$            $$           ");
		mvprintw(13, 1, " $$$          $$$$$$          $$$$         $$          ");
		mvprintw(14, 1, "  $$$        $$$  $$$        $$$$$$       $$$$        $$        ");
		mvprintw(15, 1, "   $$$      $$$    $$$      $$$ $$$      $$$$$$      $$$$      $$$$ ");
		mvprintw(16, 1, "    $$$    $$$      $$$    $$$   $$$    $$$  $$$   $$$ $$$    $$  $$");
		mvprintw(17, 1, "      $$$$$$         $$$  $$$     $$$  $$$    $$$ $$$   $$$  $$$  $$$");
		mvprintw(18, 1, "       $$$$           $$$$$$       $$$$$$      $$$$$$    $$$$$$    $$$");
		mvprintw(19, 1, "                                                                  $$$$$");
		mvprintw(20, 1, "                                                                 $$$$$$$");
		mvprintw(21, 1, "                                                                  $$ $$");
		mvprintw(22, 1, "                                                                   $ $");

		mvprintw(0, 0, "###############################################################################");
		while (wall_counter < 59)
		{
			mvprintw(y_cord, x_cord, "#");
			y_cord++;
			wall_counter++;
		}

		int x_cord2 = 79, y_cord2 = 0, wall_counter2 = 0;

		while (wall_counter2 < 59)
		{
			mvprintw(y_cord2, x_cord2, "#");
			y_cord2++;
			wall_counter2++;
		}

		int x_cord3 = 0, y_cord3 = 59, wall_counter3 = 0;


		while (wall_counter3 < 79)
		{
			mvprintw(y_cord3, x_cord3, "#");
			x_cord3++;
			wall_counter3++;

		}

		if (getch() == 'p')
		{
			playGame();
		}

	}
	endwin();
	return 0;
}

void playGame() {

	//Local declarations
	char userInput = 'x';
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