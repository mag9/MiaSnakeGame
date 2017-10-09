#include "CursesSetup.h"

//Setup the Curses window and clear the screen
void SetupAndClearCursesWindow(void){
	SetupWindows();
	clear();
}

//Curses library window setup
WINDOW* SetupWindows(void) {

	//Local declarations
	WINDOW* win = NULL;

	//Resize the window - note many terminals have a minimum number of columns 
	// (ie. 80), so if you set less than that there is no guaratee that it will work.
	resizeWindow_crossPlatform(TERMINAL_NUM_ROWS, TERMINAL_NUM_COLS);

	//Initialize the screen
	win = initscr();
	nodelay(win, TRUE);
	noecho();
	curs_set(FALSE);

	return win;
}

//Function to provide cross platform sleep functionality.
void sleep_crossPlatform(int sleepMs) {

	//If in unix, use usleep.
#ifdef UNIX
	usleep(sleepMs * 1000);
#endif

	//If in windows, use Sleep.
#ifdef WINDOWS
	Sleep(sleepMs);
#endif

}

//Function to automatically resize the window to a certain number of rows and columns
void resizeWindow_crossPlatform(int rows, int cols) {

#ifdef UNIX

	//NOTE - this seems to work on Debian based systems, but may not be extremely portable.  
	// Your mileage may vary.

	//Local declarations
	char tempStr[1000];
	int rowPix = 0;
	int colPix = 0;
	int vertPixPerChar = 16; //This number is based on the font in the terminal
	int horzPixPerChar = 8;  //As is this...  So they may need to be updated in the future.

							 //Convert from characters to pixels
	rowPix = (rows + 2) * vertPixPerChar;
	colPix = (cols + 2) * horzPixPerChar;

	//Create the command to issue to resize the window. 
	// NOTE - this requires the wmctrl package be installed, and
	//  that the current window is not already maximized.
	sprintf(tempStr, "wmctrl -r :ACTIVE: -e 0,-1,-1,%d,%d", colPix, rowPix);

	//Issue the system command to resize the window.
	system(tempStr);

#endif

#ifdef WINDOWS

	//Local declarations
	char tempStr[1000];
	int err = 0;

	//Create the command string
	sprintf(tempStr, "mode con lines=%d cols=%d", rows, cols);

	//Issue the system command to resize the window
	err = system(tempStr);

#endif

}

