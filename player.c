/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1
 * Full Name        : Drew Nuttall-Smith
 * Student Number   : s3545039
 * Course Code      : COSC1076
 * Program Code     : BP096
 * Start up code provided by Paul Miller
 **********************************************************************/
#include "player.h"
#include "game.h"

/**
 * These two functions initialise the player structure at the beginning of the
 * game. In both cases, you should initialise the whole structure to known safe
 * values and then prompt the user for their name. In the init_first_player()
 * function you should then select a color at random for this player using the
 * rand() function. This token should be assigned to the first player's token and
 * also returned via the token pointer. In init_second_player() you should just
 * test the value of token and assign the opposite color to the second player.
 **/
BOOLEAN init_first_player(struct player* first, enum cell * token) {

	/* Variables */
	char buffer[NAMELEN + EXTRACHARS];
	int bufferLength = NAMELEN + EXTRACHARS;

	/* Initialise to known safe values */
	strcpy(first->name, "player1");
	first->token = RED;
	first->score = 0;

	/* Prompt user and get input */
	printf("Please enter the first player's name: ");
	fgets(buffer, bufferLength, stdin);

	/* Check input */
	if (checkBuffer(buffer, bufferLength) == FALSE) {
		fprintf(stderr, "Invalid input\n");
		return init_first_player(first, token);
	}

	/* Assign name*/
	strcpy(first->name, buffer);

	/* Assign token */
	if (rand() % NUM_COLORS == 0) {
		*token = RED;
	} else {
		*token = BLUE;
	}
	first->token = *token;

	return TRUE;

}

BOOLEAN init_second_player(struct player * second, enum cell token) {

	/*Variables*/
	char buffer[NAMELEN + EXTRACHARS];
	int bufferLength = NAMELEN + EXTRACHARS;

	/* Initialise to known safe values */
	strcpy(second->name, "player2");
	second->token = BLUE;
	second->score = 0;

	/* Prompt user and get input */
	printf("Please enter the second player's name: ");
	fgets(buffer, bufferLength, stdin);

	/* Check input */
	if (checkBuffer(buffer, bufferLength) == FALSE) {
		fprintf(stderr, "Error: Invalid input\n");
		return init_second_player(second, token);
	}

	/* Assign name*/
	strcpy(second->name, buffer);

	/* Assign token */
	second->token = (token == 1) ? 2 : 1;

	return TRUE;

}

/**
 * prompts the user for a comma-separate pair of coordinates for a move in the
 * game. Each move, if valid, must capture at least one enemy piece by
 * surrounding a sequence of one or more enemy pieces with two pieces of our
 * own: one being the new piece to be placed and the other a piece already
 * on the board. This function then validates that a valid move has been entered
 * calls the apply_move function to do the actual work of capturing pieces.
 **/
BOOLEAN make_move(struct player * human, game_board board) {

	/* Variables */
	char buffer[5];
	int bufferLength = 5;
	char* line;
	char* ptr;
	char delim[2] = ",";
	char* token;
	unsigned x;
	unsigned y;

	printf("Please enter x and y coordinates separated by a comma for the piece you wish to place: ");

	/* Get user input from stdin */
	line = fgets(buffer, bufferLength, stdin);

	/* Check if user quit game */
	if (line == NULL || *buffer == NEWLINE) return FALSE;

	if (checkBuffer(buffer, bufferLength) == FALSE) {
		fprintf(stderr, "Error: the move you attempted was not valid.\n");
		return make_move(human, board);
	}

	/* Get x coordinate */
	token = strtok(buffer, delim);
	if (!(strlen(token) == 1) || (int)token[0] > MAX_CHAR || (int)token[0] < MIN_CHAR) {
		fprintf(stderr, "Error: the move you attempted was not valid.\n");
		return make_move(human, board);
	}
	x = strtol(token, &ptr, 10) - 1;

	/* Get y coordinate */
	token = strtok(NULL, delim);
	if (!(strlen(token) == 1) || (int)token[0] > MAX_CHAR || (int)token[0] < MIN_CHAR) {
		fprintf(stderr, "Error: the move you attempted was not valid.\n");
		return make_move(human, board);
	}
	y = strtol(token, &ptr, 10) - 1;

	if (apply_move(board, y, x, human->token) == FALSE) {
		fprintf(stderr, "Error: the move you attempted was not valid.\n");
		return make_move(human, board);
	} else {
		return TRUE;
	}

}

