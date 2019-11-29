#pragma once
#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "FileEntry.h"
#include <string.h>
class Directory : public FileEntry
{
public:
	//char* nombre = 0;
	FileEntry** hijos ;
	int Canthijos = 0;

	Directory(char* name) {
		strcpy_s(nombre,strlen(name), name);

	}
	Directory() {
		
	}

	FileType get_type() {
		return t;
	}


};

#endif