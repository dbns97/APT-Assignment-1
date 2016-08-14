/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1
 * Full Name        : Drew Nuttall-Smith
 * Student Number   : s3545039
 * Course Code      : COSC1076
 * Program Code     : BP096
 * Start up code provided by Paul Miller
 **********************************************************************/
#include "gameboard.h"
#include "player.h"

/**
 * initialise the game board to be consistent with the screenshot provided
 * in your assignment specification.
 *
 * All squares should be initialised to be blank other than the four
 * squares in the middle of the board. In that case they are initialised to
 * appropriate colored tokens
 **/
void init_game_board(game_board board) {

	/* Variables */
	int i;
	int j;

	/* Loop over each row */
	for (i = 0; i < BOARD_HEIGHT; i++) {

		/* Loop over each cell in the current row */
		for (j = 0; j < BOARD_WIDTH; j++) {

			if ((i == 3 || i == 4) && (j == i)) {
				board[i][j] = RED; /* Set two of the four centre squares to RED */
			} else if ((i == 4 && j == 5) || (i == 5 && j == 4)) {
				board[i][j] = BLUE; /* Set two of the four centre squares to BLUE */
			} else {
				board[i][j] = BLANK; /* Set all other squares to BLANK */
			}

		}

	}

}

/**
 * display the board as specified in the assignment specification. You should
 * make every effort to create a board consistent with the screenshots in the
 * assignment specification.
 **/
void display_board(game_board board, struct player * first, struct player * second) {

}

