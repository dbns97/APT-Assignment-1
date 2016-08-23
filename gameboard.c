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
				board[j][i] = RED; /* Set two of the four centre squares to RED */
			} else if ((i == 3 && j == 4) || (i == 4 && j == 3)) {
				board[j][i] = BLUE; /* Set two of the four centre squares to BLUE */
			} else {
				board[j][i] = BLANK; /* Set all other squares to BLANK */
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

	/* Variables */
	int i;
	int j;

	printf("================================================================================\n");
	printf("Player One's Details\n");
	printf("--------------------\n");
	printf("Name: %s ", first->name);
	printf("Score: %d ", first->score);
	printf("Token Color: %s0%s \n", (first->token == RED) ? COLOR_RED : COLOR_BLUE, COLOR_RESET);
	printf("--------------------------------------------------------------------------------\n");
	printf("Player Two's Details\n");
	printf("--------------------\n");
	printf("Name: %s ", second->name);
	printf("Score: %d ", second->score);
	printf("Token Color: %s0%s \n", (second->token == RED) ? COLOR_RED : COLOR_BLUE, COLOR_RESET);
	printf("--------------------------------------------------------------------------------\n");

	/* Print top line with column numbers */
	printf("   ");
	for (i = 1; i <= BOARD_WIDTH; i++) {
		printf(" %d  ", i);
	}
	printf("\n");

	printf("====================================\n");

	/* Print rows */
	for (i = 0; i < BOARD_HEIGHT; i++) {

		printf(" %d |", (i + 1));

		for (j = 0; j < BOARD_WIDTH; j++) {

			if (board[j][i] == RED) printf(" %s0%s |", COLOR_RED, COLOR_RESET);
			if (board[j][i] == BLUE) printf(" %s0%s |", COLOR_BLUE, COLOR_RESET);
			if (board[j][i] == BLANK) printf("   |");

		}

		printf("\n");

		printf("------------------------------------\n");

	}

	printf("====================================\n");

}

