#include "pch.h"
#include "agente.h"
#include <string>
#include <iostream>

using namespace std;

agente::agente()
{
	numero = "";
	ocupado = false;
	contador = 0;
}
agente::~agente()
{
}

void agente::ocupar() {
	this->ocupado = true;
	contador++;
}

void agente::desocupar() {
	this->ocupado = false;
}

void agente::mostrar() {
	cout << "AGENTE " << numero << ": " << to_string(contador);
}
