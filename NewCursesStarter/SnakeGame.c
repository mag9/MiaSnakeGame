

#include <stdio.h>
#include "CursesSetup.h"


int main(void){

    
	char userName[100];		
	int intVar = 0;			
	char input_ch = 0;		
    
	
	printf("Please enter your name: ");
	scanf("%s", &userName[0]);

    SetupAndClearCursesWindow();

	int x_cord = 0, y_cord = 0, wall_counter = 0; 

    
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
		mvprintw(y_cord3,x_cord3, "#");
		x_cord3++;
		wall_counter3++;

	}

	while (getch() != 'q');

	

    endwin();

   
    return 0;
}