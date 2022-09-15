/*
 * @author NewDawn0 (Tom)
 * File containing global Variables
*/
#pragma once

///// Structs
typedef struct player {
  int t; //Time since last space press
} player;
typedef struct obstacle {
  int height;
} obstacle;

///// Typedefs
typedef unsigned int uint;

///// Constants
const float GRAVITY = 0.05; //Gravity
const float V0 = -0.5; // Initial velocity
const int WIN_ROWS = 24; // Window columns
const int WIN_COLS = 80; // Window columuns
const float FPS = 24; // FPS
const float SPASH_TIME = 3; // Amount of time the splash screen is visible
const float PROG_BAR_LEN = 70; // Splash screen progress bar length
const int PROG_BAR_ROW = 22; // Height of progressbar
const int SCORE_COL = 62;

///// Variables
unsigned int frame = 0; //Frame number
uint score = 0; // Number of secons survived
uint digits = 1; // Number of digits in score
uint best = 0; // Highscore
uint bdigits = 1; // Number of digits in highscore
obstacle t1, t2; // Towers as obstacles
char DEATHMSG[9] = "You Died"; // Death message
char STARTMSG[21] = "Press <Enter> to play"; // Start message
