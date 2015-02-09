text_editor
===========
@author: German R. Gomez Urbina.
@date: 12 October, 2014.

Text Editor with C++

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