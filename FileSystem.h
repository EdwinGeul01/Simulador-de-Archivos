#pragma once
#include "FileEntry.h"
#include "Directory.h"
#include "File.h"
#include <iostream>

class FileSystem
{
public:
	Directory* raiz = 0;

	FileEntry* Buscar(char* const name )
	{
		if (raiz == 0)
		{
			return 0;
		}

		if (strcmp(raiz->nombre, name) == 0)
		{
			return raiz;
		}


		for (size_t i = 0; i < raiz->Canthijos; i++)
		{
			FileEntry* tmp = raiz->hijos[i];
			if (tmp->t == DIRECTORY)
			{
				Directory* tempdir = (Directory*)tmp;
				return Buscar(name, tempdir);
			}



		}

		return 0;


	}

	FileEntry* Buscar(char* const name, Directory* raiz)
	{
		if (raiz == 0)
		{
			return 0;
		}

		if (strcmp(raiz->nombre, name) == 0)
		{
			return raiz;
		}


		for (size_t i = 0; i < raiz->Canthijos; i++)
		{
			FileEntry* tmp = raiz->hijos[i];
			if (tmp->t == DIRECTORY)
			{
				Directory* tempdir = (Directory*)tmp;
				return Buscar(name, tempdir);
			}



		}

		return 0;


	}


	double ObtenerTamano(char* const name)
	{

		FileEntry* tmp = Buscar(name);

		if (tmp->t == DIRECTORY)
		{
			Directory* DirTemp =(Directory*) tmp;
			return ContadordeTamano(DirTemp);
		}

		//empezando a recorrer el arbol


		return 0;

	}


	double ContadordeTamano(Directory* raiz)
	{

		double tamano = 0;
		if (raiz == 0)
		{
			return 0;
		}




		for (size_t i = 0; i < raiz->Canthijos; i++)
		{
			FileEntry* tmp = raiz->hijos[i];
			if (tmp->t == DIRECTORY)
			{
				Directory* dirtemp = new Directory(tmp->nombre);
				tamano += ContadordeTamano(dirtemp);


			}
			else {
				File file_temp = *(File*)tmp;
				tamano += file_temp.tamano;

			}



		}

		return tamano;



	}


	void AgregarCarpeta( char* nombre, char* carpeta_donde_Agregar)
	{
		Directory* tmp = new Directory();
		tmp->nombre = nombre;
		tmp->t = DIRECTORY;
		if (strcmp(carpeta_donde_Agregar,"0")==0)
		{
			if (raiz == 0)
			{
				raiz = (Directory*)tmp;

			}
			else
			{

				std::cout << "Directorio raiz ocupado";

			}




		}
		else
		{
			Directory* carpeta_Guardar = (Directory*)Buscar(carpeta_donde_Agregar);
			FileEntry** hijosCpy = new FileEntry*[carpeta_Guardar->Canthijos + 1];

			for (size_t i = 0; i < carpeta_Guardar->Canthijos; i++)
			{
				hijosCpy[i] = carpeta_Guardar->hijos[i];
			}

			if (carpeta_Guardar->Canthijos != 0)
				delete carpeta_Guardar->hijos;

			hijosCpy[carpeta_Guardar->Canthijos] = tmp;
			carpeta_Guardar->Canthijos++;
			carpeta_Guardar->hijos = hijosCpy;


		}



	}


	void AgregarArchivo(char* nombre,char* extension,double tamano , char* carpeta_donde_Agregar)
	{
		File* tmp = new File(nombre,extension);
		tmp->t = FILEE;
		tmp->tamano = tamano;
	
			Directory* carpeta_Guardar = (Directory*)Buscar(carpeta_donde_Agregar);
			if (carpeta_Guardar != 0)
			{

			FileEntry** hijosCpy = new FileEntry * [carpeta_Guardar->Canthijos + 1];

			for (size_t i = 0; i < carpeta_Guardar->Canthijos; i++)
			{
				hijosCpy[i] = carpeta_Guardar->hijos[i];
			}

			if (carpeta_Guardar->Canthijos != 0)
				delete carpeta_Guardar->hijos;

			hijosCpy[carpeta_Guardar->Canthijos] = tmp;
			carpeta_Guardar->Canthijos++;
			carpeta_Guardar->hijos = hijosCpy;

			}
			else {

				std::cout << "error carpeta no encontrada";
			}

		



	}



	void imprimir()
	{
		char* espacio = (char*)" ";
		std::cout << "--Carpeta: " << raiz->nombre << "\n";

		for (size_t i = 0; i < raiz->Canthijos; i++)
		{
			if (raiz->hijos[i]->t == FILEE)
			{
				std::cout << espacio << "Archivo: " << raiz->hijos[i]->nombre << "\n";

			}
		}

		for (size_t i = 0; i < raiz->Canthijos; i++)
		{
			if (raiz->hijos[i]->t == DIRECTORY)
			{
				imprimir((Directory*)raiz->hijos[i], espacio);

			}

		}




	}

	void imprimir(Directory* raiz , char* espacio)
	{

		std::cout << "--Carpeta: " << raiz->nombre << "\n";

		for (size_t i = 0; i < raiz->Canthijos; i++)
		{
			if (raiz->hijos[i]->t == FILEE)
			{
				std::cout << espacio << "Archivo: " << raiz->hijos[i]->nombre<< "\n";

			}
		}

		for (size_t i = 0; i < raiz->Canthijos; i++)
		{
			if (raiz->hijos[i]->t == DIRECTORY)
			{
				imprimir((Directory*)raiz->hijos[i], espacio);

			}

		}




	}

};



