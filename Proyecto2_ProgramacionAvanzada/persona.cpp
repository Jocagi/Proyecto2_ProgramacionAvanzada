#include "pch.h"
#include "persona.h"
#include <string>
#include "Hora.h"

persona::persona()
{
	nombre = "";
	ingreso = "0:00:00";
	egreso = "0:00:00";
	agente = "N/A";
	tiempo = "0";
	servicio = "No encontrado";
	atendido = false;
}

persona::persona(std::string nombre, std::string servicio)
{
	this->nombre = nombre;
	ingreso = Hora::horaActual();
	egreso = "0:00:00";
	agente = "N/A";
	tiempo = "0";
	this->servicio = servicio;
	atendido = false;
}

persona::~persona()
{
}
