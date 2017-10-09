//define the platform
#define WINDOWS

#ifdef UNIX
#include "ncurses.h"
#include "unistd.h"
#endif

#ifdef WINDOWS
#include "curses.h"
#include "windows.h"
#include "time.h"
#endif

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define TERMINAL_NUM_ROWS 60
#define TERMINAL_NUM_COLS 80

//Function prototypes
void SetupAndClearCursesWindow(void);
WINDOW* SetupWindows(void);
void sleep_crossPlatform(int sleepMs);
void resizeWindow_crossPlatform(int rows, int cols);