#include <stdio.h>
#include "CursesSetup.h"
#include <math.h>

int main(void)
{
	char userName[100];
	int intVar = 0;
	int menu = 0;
	int game = 0;
	int test = 0;
	int x;
	int snakeRow = 15;
	int snakeCol = 15;
	char userChar = 0; //determines when to exit game
	int direction;
	int colOffset = 1;
	int rowOffset = 1;

	printf("Please enter your name: ");
	scanf("%s", &userName[0]);
	
		SetupAndClearCursesWindow();

		int x_cord = 0, y_cord = 0, wall_counter = 0;

		menu = 1;
		game = 1;

	SPLASH_SCREEN: while (getch() != 'q' && menu == 1)
	{
		mvprintw(60, 40, "Press Q to exit");
				   mvprintw(3, 30, "Welcome, %s.", userName);
				   mvprintw(4, 31, "Let's Play.");
				   mvprintw(9, 25, "Press 'p' to play.");
				   mvprintw(8, 25, "Press 'q' to quit.");

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
					   clear();
					   goto GAME;
				   }
				   
				   if (getch() == 'q')
				   {
					   endwin();
					   return 0;
				   }
	}

	GAME: while (game == 1)
	{
		//Set the variable we are using to a known good value
		intVar = 0;

		char w;
		char a;
		char s;
		char d;

			//Clear the screen
			clear();

			mvprintw(4, 30, "Player: %s \n", userName);
			mvprintw(5, 25, "HOLD w-UP, a-LEFT, s-DOWN, d-RIGHT");
			mvprintw(6, 30, "Press q to exit");


			//BORDER
			for (int x = 0; x < 80; x++) {
				mvprintw(0, 0 + x, "%s", "#");
				mvprintw(59, 1 + x, "%s", "#");
			}
			for (int x = 0; x < 59; x++) {
				mvprintw(1 + x, 0, "%s", "#");
				mvprintw(1 + x, 79, "%s", "#");
			}

			mvprintw((snakeRow), (snakeCol), "*");

			//snakeCol = snakeCol + colOffset;
			//snakeRow = snakeRow + rowOffset;
			//USER INPUT
			userChar = getch();
			if (userChar == 's' || snakeRow == 1)
			{
				direction = 's';
			}
			else if (userChar == 'w' || snakeRow == 1)
			{
				direction = 'w';
			}
			else if (userChar == 'a' || snakeCol == 1)
			{
				direction = 'a';
			}
			else if (userChar == 'd' || snakeCol == 1)
			{
				direction = 'd';
			}

			switch (direction)
			{
			case 'w':
				snakeRow--;
				break;
			case 's':
				snakeRow++;
				break;
			case 'a':
				snakeCol--;
				break;
			case 'd':
				snakeCol++;
				break;
			}
			refresh();

			//Border bounce
			/* if (snakeCol <= 0) {
			colOffset = 2;
			}
			else if (snakeCol >= 76) {
			colOffset = -2;
			}
			if (snakeRow <= 2) {
			rowOffset = 2;
			}
			else if (snakeRow >= 57) {
			rowOffset = -2;
			}
			*/

			//Refresh what is shown on the screen
			refresh();

			//Wait a bit
			sleep_crossPlatform(100);

			if (getch() == 'q')
			{
				clear();
				goto SPLASH_SCREEN;
			}

	}

}