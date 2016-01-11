#include <stdlib.h>
#include <curses.h>
#include <signal.h>
#include "sk_manager.h"

/*
 * Entry point for editor porgram.
 */
int main(int argc, char * argv[])
{
	int command;
	int y;
	int x;
	
	init();
	printw("Started EdIt v1.0 - Press Ctrl + C to end program.\n");
	
	for(;;)
	{
		command = getch();
		getyx(stdscr, y, x);
		get_command(command, y, x);
	}
	return 0;
}
	
	
	
