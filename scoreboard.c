/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1
 * Full Name      : Drew Nuttall-Smith
 * Student Number : s3545039
 * Course Code    : COSC1076
 * Program Code   : BP096
 * Start up code provided by Paul Miller
 **********************************************************************/

#include "scoreboard.h"

/**
 * initalise the scoreboard so that the scores for each element of the array
 * is set to 0.
 **/
void init_scoreboard(score scores[MAX_SCORES]) {

	/* Variables */
	int i;

	/* Set each score in scores to 0 */
	for (i = 0; i < MAX_SCORES; i++) {
		scores[i]->score = 0;
	}

}


/**
 * insert the top scorer from the last game played in sorted order according
 * to their score
 **/
BOOLEAN add_to_scoreboard(score scores[MAX_SCORES], struct player * winner)
{

	/* Variables */
	int i; /* Iterator for outer loop */
	int j; /* Iterator for inner loop */

	/* Loop over each element in the scores array */
	for (i = 0; i < MAX_SCORES; i++) {

		/* Compare the last winning score against the current array element */
		if (winner->score > scores[i]->score) {

			/* Move each score lower than the last winner's down one
			place in the order */
			for (j = (MAX_SCORES - 1); j > i; j--) {
				scores[j] = scores[j - 1];
			}

			/* Add the last winner to the array in the correct order */
			scores[i] = *winner;

			break;

		}

	}

	return TRUE;

}

/**
 * display the scores in the scoreboard according to their order. Your output
 * should match that provided in the assignment specification.
 **/
void display_scores(score scores[MAX_SCORES])
{

	/* Variables */
	int i;
	int j;

	printf("Reversi - Top Scores\n");
	printf("====================\n");
	printf("----------------------------\n");
	printf("Name                 | Score\n");
	printf("----------------------------\n");

	for (i = 0; i < MAX_SCORES; i++) {

		if (scores[i]->score == 0) continue;

		printf("%s", scores[i]->name);

		for (j = 0; j < (NAMELEN - strlen(scores[i]->name)); j++) {
				printf(" ");
		}

		printf("| %d", scores[i]->score);

	}

	printf("----------------------------\n");

}
