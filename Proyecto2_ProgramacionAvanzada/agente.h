#pragma once
#include <string>

class agente
{
public:
	std::string numero;
	int contador;

	bool ocupado;


	void ocupar();
	void desocupar();

	void mostrar();

	agente();
	~agente();

};

