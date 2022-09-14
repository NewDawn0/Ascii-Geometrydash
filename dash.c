/*
@author NewDawn0 (Tom)
An ascii-based Geometry Dash knock-off intended to be run in a console

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

typedef struct player {
  int t; //Time since last space press
} player;
typedef struct obstacle {
  int height;
} obstacle;

// Typedefs
typedef unsigned int uint;

// Variables
const char DEATHMSG[9] = "You Died";
const char STARTMSG[21] = "Press <Enter> to play";
const float GRAVITY = 0.05; //Gravity
const float V0 = -0.5; // Initial velocity
const int WIN_ROWS = 24; // Window columns
const int WIN_COLS = 80; // Window columuns
const float FPS = 24; // FPS
const float SPASH_TIME = 3; // Amount of time the splash screen is visible
const float PROG_BAR_LEN = 70; // Splash screen progress bar length
const int PROG_BAR_ROW = 22; // Height of progressbar
const int SCORE_COL = 62;
unsigned int frame = 0; //Frame number
uint score = 0; // Number of secons survived
uint digits = 1; // Number of digits in score
uint best = 0; // Highscore
uint bdigits = 1; // Number of digits in highscore
obstacle t1, t2; // Towers as obstacles

//Functions
void splashScreen(char message[]) {
  int i;
  int r = WIN_ROWS/2-6;
  int c = WIN_COLS/2-35;
  mvprintw(r, c, "  ____                           _                ____            _");
  mvprintw(r+1, c, " / ___| ___  ___  _ __ ___   ___| |_ _ __ _   _  |  _ \\  __ _ ___| |__");
  mvprintw(r+2, c, "| |  _ / _ \\/ _ \\| '_ ` _ \\ / _ \\ __| '__| | | | | | | |/ _` / __| '_ \\");
  mvprintw(r+3, c, "| |_| |  __/ (_) | | | | | |  __/ |_| |  | |_| | | |_| | (_| \\__ \\ | | |");
  mvprintw(r+4, c, " \\____|\\___|\\___/|_| |_| |_|\\___|\\__|_|   \\__, | |____/ \\__,_|___/_| |_|");
  mvprintw(r+5, c, "                                          |___/             By NewDawn0");
  mvprintw(WIN_ROWS/2+1, WIN_COLS/2-10, message);
  mvprintw(PROG_BAR_ROW, WIN_COLS/2-PROG_BAR_LEN/2-1, "[");
  mvprintw(PROG_BAR_ROW, WIN_COLS/2+PROG_BAR_LEN/2, "]");
  refresh();
  
  // Progress bar
	mvprintw(PROG_BAR_ROW, WIN_COLS / 2 - PROG_BAR_LEN / 2 - 1, "[");
	mvprintw(PROG_BAR_ROW, WIN_COLS / 2 + PROG_BAR_LEN / 2, "]");
	refresh();
	for(i = 0; i < PROG_BAR_LEN; i++) {
		usleep(1000000 * SPASH_TIME / (float) PROG_BAR_LEN);
		mvprintw(PROG_BAR_ROW, WIN_COLS / 2 - PROG_BAR_LEN / 2 + i, "=");
		refresh();
	}
  usleep(1000000 * 0.5);
}
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
