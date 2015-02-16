text_editor
===========
@author: German R. Gomez Urbina.
@date: 15 February, 2015.

Text Editor with C.

notes:

-> The GUI will be built using the ncurses library.
   The textViewer class will deal with all the changes that will be visible
   to the user. 
   All functions from the textViewer class will be called in main.cpp
   which will integrate all the parts of the text editor.

@date: 8 February, 2015.

-> After much consideration the following diagram describes how the program will
   be setup:

   Screen <- GUI-Prog <-> Text Prog <-> File/Memory Manager <-> File
                  ^          ^
                  |          |
                  ------------- Keyboard Reader <-> Keyboard

 -> The arrows indicate the direction of data. This may change.

@date: 15 February, 2015.

-> Decided to progress with C.

-> The Keyboard and Screen implentation have been put together into one program
   for ease of development. The program is called sk_manager (Screen/Keyboard).

-> Responsible to determine the input and thus the overall behaviour of the
   program.

