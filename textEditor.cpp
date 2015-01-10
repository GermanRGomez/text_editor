/*
 * @author: German R. Gomez Urbina
 * @date: 25 October 2014.
 *
 * textEditor - This class is responsible of storing the text file into 
 * memory, initialize the line buffer, manipulate the text file, and save.
 * 
 * Based on: http://www.catch22.net/tuts/loading-text-file 
 */

#include "textEditor.h"
#include <iostream>
#include <fstream>

bool textEditor::init(char *filename)
{

  fstream file;
  file = 
