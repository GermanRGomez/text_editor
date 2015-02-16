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
  char ch;
  init();
  
  printw("EdIt v1.0 - Ctrl + C to close...\n");
  refresh();
  
  for(;;)
    {
      ch = getch();
      printw("%c", ch);
    }
}
      
  
