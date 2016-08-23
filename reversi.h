/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1
 * Full Name        : Drew Nuttall-Smith
 * Student Number   : s3545039
 * Course Code      : COSC1076
 * Program Code     : BP096
 * Start up code provided by Paul Miller
 **********************************************************************/
#include "shared.h"
#include "player.h"
#include "game.h"
#include "scoreboard.h"
#include "utility.h"

#ifndef REVERSI_H
#define REVERSI_H

/* Main menu selections */
#define PLAY_GAME 1
#define DISPLAY_SCORES 2
#define EXIT_GAME 3

void print_menu();
int get_selection();

#endif
