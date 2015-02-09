#include <iostream> 
#include <ncurses.h> 

/*
 * Responsible for initializing and outputting everything to the screen.
 */

using namespace std;

int main (int argc, char * argv[])
{
  wchar_t key = 0; /* In theory this will be a function from the keyboard
		    * library 
		    */
  //setlocale(LC_ALL, "");
  initscr();
  keypad(stdscr, true);
  
  printw("Text Editor [name pending] v1.0 by German R. Gomez Urbina\n");
  getch();
  
  do
    {
      clear();
      key = getch();
      printw("%d", key);
    } while(key != KEY_ENTER);
 
  endwin();

  return 0;
}
