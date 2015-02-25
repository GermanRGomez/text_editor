#include <stdlib.h>
#include <curses.h>
#include <signal.h>
#include "sk_manager.h"

/* 
 * sk_manager stands for "Screen and Keyboard manager". This program is 
 * responsible for input from the keyboard and outputting to the screen.
 * This is implemented using the ncurses library.
 */

void init()
{
  signal(SIGINT, end);
  
  initscr();             /* Initialize the ncurses library */
  keypad(stdscr, TRUE);  /* Enable keyboard mapping */
  cbreak();              /* Take input one character at a time */
  noecho();
}

static void end(int sig)
{
  endwin();
  exit(0);
}

int main(int argc, char ** argv)
{
  int ch, x, y;
  
  init();
  
  printw("EdIt v1.0 - Ctrl + C to close...\n");
  refresh();
  
  for(;;)
  {
	ch = getch();
	getyx(stdscr, y, x);	
     	refresh();
   	
	/*
	 * Functions to add:
	 * Shift
	 * Delete
	 * Directional buttons
	 * Buttons that change state (TBD).
	 */
	switch(ch)
	{
		case KEY_ENTER:
			printw("\n");
			break;
		case KEY_BACKSPACE:
			BACKSPACE_KEY(y, x);
			break;
		default: 
			printw("%c", ch); 
	}			 
    }
}
      
/*
 * BACKSPACE_KEY 
 * 
 * This function describe the behaviour of 
 * of the backspace function.
 * 
 * The special case is when the cursor is at the start of
 * the line and it needs to return to the line above.
 * 
 * NOTE: This function needs to be modified to accept information
 * from buffer data structures to determine where it will be located
 * when returning to the line above.
 *
 */
void BACKSPACE_KEY(int y, int x)
{
	/* 
	 * Keep in mind that this function will need information from 
	 * the buffer data structures. i.e: line size. 
  	 * In order to predict where the cursor will have to move.
	 */
	if (x)
	{
		move(y, x - 1);
		printw(" ");
		move(y, x - 1);
	} else 
	{
		move(y - 1, x); 
	}
}

		
