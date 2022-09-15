/*
@author NewDawn0 (Tom)
An ascii-based Geometry Dash knock-off intended to be run in a console

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>
#include "screens.h"
#include "globals.h"

//Functions
//// Main Function
int main() {
	// Initialize ncurses
	initscr();
	raw();					// Disable line buffering
	keypad(stdscr, TRUE);
	noecho();				// Don't echo() for getch
	curs_set(0);
	timeout(0);
  splashScreen(STARTMSG); // Start screen
  //splashScreen(DEATHMSG); // Death screen
  return 0;
}
