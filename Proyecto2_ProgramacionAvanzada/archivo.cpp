#include "pch.h"
#include "archivo.h"
#include "persona.h"
#include "lista.h"

#include <string>
#include <iostream>
#include <fstream>

#include <sstream> //string stream


using namespace std;

void archivo::crear() {
	ofstream(nombreArchivo);
}

void archivo::limpiar() {
	archivo a;
	std::ofstream ofs;
	ofs.open(a.nombreArchivo, std::ofstream::out | std::ofstream::trunc);
	ofs.close();
}

void archivo::escribir(lista list) {
	archivo a;
	ofstream fichero;
	fichero.open(a.nombreArchivo, std::ios::app);

	lista cola = list;
	string cliente;
	
	while ((cola.cabeza) != NULL)
	{
		cliente = convertirPersonaACadena(cola.cabeza->info);
		//linea a colocar.
		fichero << cliente << endl;

		//recorrer lista
		cola.cabeza = cola.cabeza->siguiente;
	}

	fichero.close();
}

lista archivo::leer() {

	archivo a;

	fstream fichero;

	string texto;
	lista cola;

	fichero.open(a.nombreArchivo, std::ios::in);
	if (fichero.is_open())
	{
		while (!fichero.eof())
		{
			getline(fichero, texto);//recorrer linea por linea el archivo

			if (texto != "")
			{
				cola.push(convertirCadenaAPersona(texto)); //separar palabras y anadir a lista
			}
		}

		fichero.close();
	}
	else
	{
		cout << "Fichero inexistente" << endl;
	}

	return cola;
}

persona archivo::convertirCadenaAPersona(string cadena) {
	//"nombre,ingreso,egreso,agente,tiempo,servicio,atendido"
	//"string,string,string,string,string,string,bool"
	
	persona cliente;
	stringstream ss(cadena);
	string token;
	int contador = 0;

	while (getline(ss, token, ','))
	{
		switch (contador)
		{
		case 0:
			cliente.nombre = token;
			break;
		case 1:
			cliente.ingreso = token;
			break;
		case 2:
			cliente.egreso = token;
			break;
		case 3:
			cliente.agente = token;
			break;
		case 4:
			cliente.tiempo = token;
			break;
		case 5:
			cliente.servicio = token;
			break;
		case 6:
			if (token == "true" || token == "1")
			{
				cliente.atendido = true;
			}
			else
			{
				cliente.atendido = false;
			}
			break;
		default:
			break;
		}

		contador++;
	}

	return cliente;
}

string archivo::convertirPersonaACadena(persona cliente) {
	return (cliente.nombre + "," + cliente.ingreso + "," + cliente.egreso + "," + cliente.agente + "," +  cliente.tiempo + "," +  cliente.servicio + "," +  to_string(cliente.atendido));
}

void archivo::splitString(string cadena) {

	stringstream ss(cadena);
	string tmp;

	while (getline(ss, tmp, ','))
	{
		cout << tmp << endl;
	}
}

archivo::archivo()
{
	this->nombreArchivo = "informacion.txt";
}
archivo::archivo(string nombre)
{
	this->nombreArchivo = nombre + ".txt";
}

archivo::~archivo()
{
}
