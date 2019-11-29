#include "File.h"
#include "Directory.h"
#include <iostream>
#include "FileSystem.h"

using namespace std;

int main()
{
	 int opt = 0;
	 FileSystem Fs;

	do
	 {
		cout << "\n";
	 cout << "------------MENU----------------\n";
	 cout << "1. Agregar Archivo\n";
	 cout << "2. Agregar Directorio \n";
	 cout << "3. Ver tamaño del directorio o archivo \n";
	 cout << "4. Imprimir \n";
	 cout << "5. Salir \n";
	 cout << "Ingrese la opcion a usar: " ;
	 cin >> opt;


	if (opt == 1)
	 {
		char* nombre = new char(20);
		char* extension = new char(10);
		double tamaño = 0;
		char* carpeta_Guardar = new char (20);
		cout << "ingrese nombre del archivo : ";
		cin >> nombre;
		cout << "ingrese extension del archivo : ";
		cin >> extension;
		cout << "ingrese tamaño del archivo : ";
		cin >> tamaño;
		cout << "ingrese carpeta donde se guardara del archivo : ";
		cin >> carpeta_Guardar;

		Fs.AgregarArchivo(nombre, extension, tamaño, carpeta_Guardar);
		Fs.imprimir();
	}
	else if (opt == 2)
	{
		char* nombre = new char(20);
		char* carpeta_Guardar = new char(20);
		cout << "ingrese nombre de la carpeta : ";
		cin >> nombre;
		cout << "ingrese carpeta donde se guardara la carpeta o 0 si es la raiz : ";
		cin >> carpeta_Guardar;
		Fs.AgregarCarpeta(nombre, carpeta_Guardar);

		Fs.imprimir();


	}
	else if (opt == 3)
	{

		char* nombre = new char(20);
		cout << "ingrese nombre de la carpeta : ";
		cin >> nombre;

		cout << "El tamaño es : " << Fs.ObtenerTamano(nombre);





	}
	else if (opt == 4)
	{

		Fs.imprimir();

	}




	 }while (opt != 5);





}