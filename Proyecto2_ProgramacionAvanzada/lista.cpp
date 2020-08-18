#include "pch.h"
#include "lista.h"
#include "persona.h"
#include "Hora.h"

#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

nodo::nodo() 
{
	this->siguiente = NULL;
}

nodo::~nodo()
{
}

lista::lista()
{
	cabeza = NULL;
}

lista::~lista()
{
}

void lista::push(persona nuevo){

	nodo* tmp = new nodo;
	tmp->info = nuevo;

	if (cabeza == NULL)
	{
		cabeza = tmp;
	}
	else
	{
		nodo* tmp2 = cabeza;

		while (tmp2 != NULL)
		{
			if (tmp2->siguiente == NULL)
			{
				tmp2->siguiente = tmp;
				break;
			}
			else
			{
				tmp2 = tmp2->siguiente;
			}
		}
	}
}

void lista::pop(string numCajero) {

	nodo* tmp = this->cabeza;

	if (tmp != NULL)
	{
		while (tmp!=NULL)
		{
			if (tmp->info.atendido == false)
			{
				//El cliente no ha sido atendido aun

				tmp->info.agente = numCajero;
				tmp->info.atendido = true;
				tmp->info.egreso = Hora::horaActual();
				tmp->info.tiempo = Hora::tiempoEnCola(tmp->info.ingreso, tmp->info.egreso);

				if (numCajero != "N/A")
				{
					cout << "El cliente " << tmp->info.nombre << " ha ingresado con el agente " << numCajero << " y ha permanecido " << tmp->info.tiempo << " en cola...\n";
				}
				else 
				{
					cout << "El cliente " << tmp->info.nombre << " se ha retirado de la cola " << " y ha permanecido " << tmp->info.tiempo << " en cola...\n";
				}

				break;
			}
			else
			{
			    //El cliente fue atendido
				tmp = tmp->siguiente;

				if (tmp == NULL)
				{
					cout << "\nNo hay clientes en cola\n";
				}
			}
		}
	}
	else
	{
		cout << "\nNo hay clientes en cola\n";
	}

}

void lista::mostrar() {

	nodo* cliente = this->cabeza;

	if (cliente == NULL)
	{
		cout << "No hay clientes en cola\n";
	}
	else
	{
		cout << "CLIENTES EN COLA: \n";
		cout<< "NOMBRE//HORA DE INGRESO//SERVICIO\n";
		while (cliente != NULL)

		{
			if (cliente->info.atendido == false)
			{
				cout << cliente->info.nombre << "//" << cliente->info.ingreso << "//" << cliente->info.servicio << "\n";
			}
			cliente = cliente->siguiente;
		}
	}
}

void lista::historial() {

	nodo* cliente = this->cabeza;

	if (cliente == NULL)
	{
		cout << "No han ingresado clientes en la cola\n";
	}
	else
	{
		cout << "CLIENTES QUE HAN PASADO EN COLA: \n";
		while (cliente != NULL)
		{
			if (cliente->info.atendido == true)
			{
				cout << "Nombre: " << cliente->info.nombre << ", Ingreso: " << cliente->info.ingreso << ", Egreso: " << cliente->info.egreso << ", Tiempo: " << cliente->info.tiempo << ", Servicio: " << cliente->info.servicio << ", Agente: " << cliente->info.agente << "\n\n";
			}
			cliente = cliente->siguiente;
		}
	}
}

void lista::buscar(string nombre) {

	nodo* cliente = this->cabeza;

	if (cliente == NULL)
	{
		cout << "No hay clientes en cola\n";
	}
	else
	{
		while (cliente != NULL){
			if (cliente->info.atendido == false && cliente->info.nombre == nombre)
			{
				cout << "Cliente encontrado:\n";
				cout << "Nombre: " << cliente->info.nombre << " // Entrada: " << cliente->info.ingreso << " // Servicio: " << cliente->info.servicio << "\n";
				break;
			}
			cliente = cliente->siguiente;
			if (cliente == NULL)
			{
				cout << "El cliente no fue encontrado...\n";
			}
		}
	}
}