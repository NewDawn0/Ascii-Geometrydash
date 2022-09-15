/*
 * @author NewDawn0 (Tom)
 * File containing various screens
 */

#include <ncurses.h>
#include <unistd.h>
#include "globals.h"

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
