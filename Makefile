# Makefile for text editor program - Name pending.
# German R. Gomez Urbina\
# 26 October 2014.

sk_manager: sk_manager.o
	gcc sk_manager.o -Wall -lncurses -o sk_manager

sk_manager.o: sk_manager.c
	gcc -c sk_manager.c 

clean:
	rm -rf *~ *.o sk_manager
