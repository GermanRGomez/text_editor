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
      refresh();
      /* Make this into a switch statement */
      /* Consider making a function for each case */ 
      if (ch == KEY_ENTER)
	{
	  printw("\n");
	} else if(ch == KEY_BACKSPACE)
	{
	  /*
	   * Make a function for this case, it must move cursor, the add blank
	   * and move back.
	   * Deal with special case of going to the line above if original line
	   * is already empty.
	   */
	  getyx(stdscr, y, x);
	  move(y,x - 1);
	  printw(" ");
	  move(y,x - 1);
	} else 
	{
	  printw("%c", ch);
	}
    }
}
      
  
