#pragma once
#include <string>
#include "persona.h"

using namespace std;

struct nodo
{
	nodo* siguiente;
	persona info;

	nodo();
	~nodo();
};

struct lista
{
	nodo* cabeza;

	void push(persona nuevo);
	void pop(string  numCajero);
	void mostrar();
	void historial();
	void buscar(string nombre);

	lista();
	~lista();
};

