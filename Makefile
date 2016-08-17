all:
	gcc -ansi -Wall -pedantic *.c -o reversi.exe

clean:
	rm reversi.exe
