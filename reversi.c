/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1
 * Full Name      : Drew Nuttall-Smith
 * Student Number : s3545039
 * Course Code    : COSC1076
 * Program Code   : BP096
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

	/* in a loop: display the main menu */
	printMenu();

	/* get the user's selection from the main menu */
	switch(getSelection()) {

		case 1:

			winner = play_game(&human, &computer);

			break;

		case 2:

			break;

		case 3:

			exit(EXIT_SUCCESS);

			break;

	}

	/* perform the requested task */
			/* play a game and add the winner to the scoreboard */

			/* display scores */
			/* quit the program */
	return EXIT_SUCCESS;
}

/**
 * Print the main menu
 */
void printMenu() {

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
int getSelection() {

	/* Variables */
	char buffer[3];
	int bufferLength = 3;
	char *ptr;
	int selection;

	/* Get user input from stdin */
	fgets(buffer, bufferLength, stdin);

	/* Read value from buffer as number */
	selection = strtol(buffer, &ptr, 10);

	return selection;

}

