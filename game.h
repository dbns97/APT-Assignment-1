/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1
 * Full Name        : Drew Nuttall-Smith
 * Student Number   : s3545039
 * Course Code      : COSC1076
 * Program Code     : BP096
 * Start up code provided by Paul Miller
 **********************************************************************/
#include <time.h>
#include "shared.h"
#include "player.h"
#include "gameboard.h"


#ifndef GAME_H
#define GAME_H

struct player * play_game(struct player * human, struct player * computer);
BOOLEAN apply_move(game_board board, unsigned y, unsigned x,
                   enum cell player_token);
unsigned game_score(game_board board, enum cell player_token);
void swap_players(struct player ** first, struct player ** second);
void endGame(struct player ** first, struct player ** second, struct player ** winner);

#endif /* ifndef GAME_H */
