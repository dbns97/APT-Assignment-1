/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1
 * Full Name      : Drew Nuttall-Smith
 * Student Number : s3545039
 * Course Code    : COSC1076
 * Program Code   : BP096
 * Start up code provided by Paul Miller
 **********************************************************************/

#include "utility.h"

/**
 * function required to be used when clearing the buffer. It simply reads
 * each char from the buffer until the buffer is empty again. Please refer
 * to the materials on string and buffer handling in the course for more
 * information.
 **/
void read_rest_of_line(void)
{
    int ch;
    while(ch = getc(stdin), ch != EOF && ch != NEWLINE)
        ;
    clearerr(stdin);
}
