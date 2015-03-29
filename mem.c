/*
 * Program responsible to implement file, and memory management.
 * Here will be implemented the piece table algorithm responsible to 
 * make the text editor work.
 * All the buffers, file pointers/descriptors, and saves/deletes will be done
 * here.
 */

#include <stdlib.h>
#include <stdio.h>
#include "mem.h"

#define CHUNK 1024

typedef enum {ADD, ORIGINAL} BufferType;

/* 
 * readFile - Read contents of a file into a buffer.
 */
int readFile(FILE *fp, char **buf)
{
	int bufSize, fileSize, itemsRead;
	char * buffer, * tempBuffer;

	fileSize = CHUNK;
	bufSize = fileSize;
	itemsRead = 0;
	
	buffer = malloc(sizeof(char) * fileSize);
	
	if(buffer == NULL)
		return -1; // Error
	
	while((itemsRead = fread(buffer, sizeof(char), CHUNK, fp)) > 0)
	{
		fileSize += itemsRead;
		
		if((bufSize - fileSize) < CHUNK)
		{
			bufSize *= 2;
			tempBuffer = malloc(bufSize * sizeof(char));
			
			if(tempBuffer == NULL)
				return -1; // Error
			
			free(buffer);
			buffer = realloc(tempBuffer, fileSize * sizeof(char));

			if(buffer == NULL)
				return -1; // Error\\
			
			free(tempBuffer);	
		}
	}
	
	* buf = buffer;
	free(buffer);

	return fileSize;
}


	
	

