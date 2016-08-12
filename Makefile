all:
	gcc -ansi -Wall -pedantic gameboard.c game.c player.c reversi.c scoreboard.c utility.c -o reversi.exe

clean:
	rm reversi.exe
