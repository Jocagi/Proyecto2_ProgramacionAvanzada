#pragma once
#include <string>

struct persona
{
	std::string nombre;
	std::string ingreso;
	std::string egreso;
	std::string agente;
	std::string tiempo;
	std::string servicio;
	bool atendido;

	persona();
	persona(std::string nombre, std::string servicio);
	~persona();
};

