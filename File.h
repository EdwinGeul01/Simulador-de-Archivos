#pragma once

#ifndef FILE_H
#define FILE_H

#include "FileEntry.h"
#include <string.h>
#include<iostream>
class File : public FileEntry
{


public:
	FileType type = FILEE;
	//char* nombre;
	double tamano;
	File(char* name, const char* extension) {
		char* temp = (char*)"asd";
		this->nombre = new char[sizeof(name)];
		//std::cout << strlen(name)  << " " << sizeof(name);
		strcpy_s(this->nombre, sizeof(name) + 1, name);
		//std::cout << strlen(nombre) << " " << sizeof(nombre);

		strcat_s(nombre, sizeof(nombre)+sizeof(extension), extension);

	}
	File() {}

	FileType get_type() {
		return type;
	}


};

#endif