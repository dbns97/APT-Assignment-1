/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1
 * Full Name        : Drew Nuttall-Smith
 * Student Number   : s3545039
 * Course Code      : COSC1076
 * Program Code     : BP096
 * Start up code provided by Paul Miller
 **********************************************************************/
#include "game.h"

/**
 * The heart of the game itself. You should do ALL initialisation required
 * for the game in here or call function required for that purpose. For example
 * both players should be initialised from here, you should seed the random
 * number generator, that kind of thing.
 *
 * Next, you should set the initial player - the initial player is the player
 * whose token was set by initialisation to RED.
 *
 * Next, you will need to manage the game loop in here. In each loop of the
 * game, you should display the game board, including player scores
 * display whose turn it is, etc in the format specified in the assignment
 * specification. Finally at the end of each turn you will calculate the score
 * for each player you will calculate their score and store it and then you
 * will need to swap the current player and other player
 * using the swap_player() function.
 *
 * A game will end when either player presses enter or ctrl-d on a newline.
 *
 * When you detect a request to end the game, you should do a final calculation
 * of the scores for the two players and return the player with the highest
 * score.
 **/
struct player * play_game(struct player * first, struct player * second) {

	/* Variables */
	game_board board;
	enum cell token;
	struct player * current, *other, *winner;

	/* Seed random number generator */
	srand(time(0));

	/* Initialise both players */
	init_first_player(first, &token);
	init_second_player(second, token);

	/* Set the current and other player pointers */
	if (first->token == RED) {
		current = first;
		other = second;
	} else {
		current = second;
		other = first;
	}

	/* Initialise the game board */
	init_game_board(board);

	/* Game loop */
	while(TRUE) {

		/* Display the game board */
		display_board(board, first, second);

		printf("It is %s's turn.\n", current->name);

		if (make_move(current, board) == FALSE) {
			break;
		} else {
			swap_players(&current, &other);
			first->score = game_score(board, first->token);
			second->score = game_score(board, second->token);
		}

	}

	return winner;

}

/**
 * does the work of applying the move requested by the user to the game board.
 * It iterates over all the directions from the coordinate specified to see
 * whether there are any pieces that can be captured. If there are no pieces
 * that can be captured in any direction, it is an invalid move.
 **/
BOOLEAN apply_move(game_board board, unsigned y, unsigned x, enum cell player_token) {

	enum direction dir;
	unsigned captured_pieces = 0;
	int translations[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {-1,1}, {1,-1}, {-1,-1}};
	enum cell opponent_token = (player_token == RED) ? BLUE : RED;
	struct coordinate next;
	int dirCaptureCount;

	/* Check if the chosen square is empty */
	if (board[x][y] != BLANK) return FALSE;

	/* Check if any pieces can be taken in any of the cardinal directions */
	for (dir = NORTH; dir <= SOUTH_WEST; dir++) {

		dirCaptureCount = 0;

		next.x = x + translations[dir][0];
		next.y = y + translations[dir][1];

		while (board[next.x][next.y] == opponent_token) {
			dirCaptureCount++;
			next.x += translations[dir][0];
			next.y += translations[dir][1];
		}

		if (board[next.x][next.y] == player_token) {

			captured_pieces += dirCaptureCount;

			next.x -= translations[dir][0];
			next.y -= translations[dir][1];

			while (next.x != x || next.y != y) {
				board[next.x][next.y] = player_token;
				next.x -= translations[dir][0];
				next.y -= translations[dir][1];
			}

		}

	}

	if (captured_pieces == 0) {
		return FALSE;
	} else {
		board[x][y] = player_token;
		return TRUE;
	}

}

/**
 * simply count up how many locations contain the player_token
 * specified on the game_board.
 **/
unsigned game_score(game_board board, enum cell player_token) {

	int i;
	int j;
	int score = 0;

	for (i = 0; i < BOARD_HEIGHT; i++) {
		for (j = 0; j < BOARD_WIDTH; j++) {
			if (board[i][j] == player_token) score++;
		}
	}

	return score;

}

/**
 * swap the two player pointers passed in so that first points to the player
 * pointer that originally contained the second player and vice versa.
 **/
void swap_players(struct player ** first, struct player ** second) {

	/* Variables */
	struct player* swp;

	/* Swap the two player pointers */
	swp = *first;
	*first = *second;
	*second = swp;

}

