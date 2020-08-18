#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "persona.h"
#include "lista.h"

using namespace std;

class archivo
{
public:
	string nombreArchivo;

	static void crear();
	static void limpiar();

	static void escribir(lista list);
	static lista leer();

	static void splitString(string cadena);
	static persona convertirCadenaAPersona(string cadena);
	static string convertirPersonaACadena(persona cliente);

	archivo();
	archivo(string nombre);
	~archivo();
};

