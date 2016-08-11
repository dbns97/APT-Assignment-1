/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1
 * Full Name        : Drew Nuttall-Smith
 * Student Number   : s3545039
 * Course Code      : COSC1076
 * Program Code     : BP096
 * Start up code provided by Paul Miller
 **********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <time.h>

#ifndef SHARED_H
#define SHARED_H

/* definition of the boolean type */
typedef enum
{
        FALSE, TRUE
} BOOLEAN;

/* how many colors are their in the game? required by the random number
 * generation
 */
#define NUM_COLORS 2

/* what values could be contained in a cell on the board? */
enum cell
{
        BLANK, RED, BLUE
};

/* color codes required to display the tokens on the board */
#define COLOR_RED     "\33[31m"
#define COLOR_BLUE    "\33[34m"
#define COLOR_RESET   "\33[0m"
#endif /* defined SHARED_H */
