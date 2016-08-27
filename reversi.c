/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1
 * Full Name        : Drew Nuttall-Smith
 * Student Number   : s3545039
 * Course Code      : COSC1076
 * Program Code     : BP096
 * Start up code provided by Paul Miller
 **********************************************************************/

#include "reversi.h"

/**
 * the head of the program. The main() function in particular should
 * manage the main menu for the program.
 **/
int main(void)
{
	score scrboard[MAX_SCORES];
	struct player human, computer, *winner = NULL;

	/* initialise the scoreboard */
	init_scoreboard(scrboard);

	/* Present the main menu in a loop until program ends */
	while (TRUE) {

		/* Display the main menu */
		print_menu();

		/* Get the user's selection and perform task */
		switch(get_selection()) {

			case PLAY_GAME:
				winner = play_game(&human, &computer);
				/* add winner to the scoreboard */
				if (winner != NULL) add_to_scoreboard(scrboard, winner);
				break;

			case DISPLAY_SCORES:
				/* Display high scores */
				display_scores(scrboard);
				break;

			case EXIT_GAME:
				/* Exit the program */
				exit(EXIT_SUCCESS);
				break;

			default:
				fprintf(stderr, "Error: Invalid selection!\n");

		}

	}

	return EXIT_SUCCESS;
}

/**
 * Print the main menu
 */
void print_menu() {

	printf("Welcome to Reversi!\n");
	printf("===================\n");
	printf("Select an option:\n");
	printf("1. Play a game\n");
	printf("2. Display High Scores\n");
	printf("3. Quit the program\n");
	printf("Please enter your choice: ");

}

/**
 * Get the user's menu selection
 *
 * @return: the selection as an integer
*/
int get_selection() {

	/* Variables */
	char buffer[1 + EXTRACHARS];
	int bufferLength = 1 + EXTRACHARS;
	char *ptr = NULL;
	int selection;

	/* Get user input from stdin */
	fgets(buffer, bufferLength, stdin);

	if (checkBuffer(buffer, bufferLength) == FALSE) return FALSE;

	/* Read value from buffer as number */
	selection = strtol(buffer, &ptr, 10);

	return selection;

}

