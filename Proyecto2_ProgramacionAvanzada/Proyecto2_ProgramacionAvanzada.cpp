// Proyecto2_ProgramacionAvanzada.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>

#include <iomanip>
#include <string>
#include <stdlib.h>

#include "lista.h"
#include "persona.h"
#include "agente.h"
#include "archivo.h"

using namespace std;

int main()
{
	bool salir = false;
	string cadenaOpcion;
	int opcion = 0;

	string servicio = "";

	agente agentes[5];
	{
		agentes[0].numero = "1";
		agentes[1].numero = "2";
		agentes[2].numero = "3";
		agentes[3].numero = "4";
		agentes[4].numero = "5";
	}

	archivo arch;

	arch.crear();
	lista cola = arch.leer();
	arch.limpiar();

	//Inicia Menu Prncipal

	cout << "SISTEMA DE CONTROL DE PERSONAS EN ESPERA\n";
	cout << "Creado por Jose Giron, 104718\n";
	system("pause");

	do
	{
		arch.escribir(cola);
		cola = arch.leer();

		system("CLS");
		cout << "MENU PRINCIPAL\n";
		cout << "Elige una opcion:\n";

		cout << "1. Ingresar cliente a la cola\n";
		cout << "2. Retirar primera persona de la cola\n";
		cout << "3. Desocupar agente\n";
		cout << "4. Asignar cliente a un agente\n";
		cout << "5. Mostrar clientes en cola\n";
		cout << "6. Buscar un cliente en la cola\n";
		cout << "7. Historial de clientes\n";
		cout << "8. Salir\n";

		try
		{
			cin >> opcion;

			system("CLS");

			switch (opcion)
			{
			case 1:
			{
				{
					system("CLS");
					cout << "Ingrese el nombre del cliente: ";
					cin >> cadenaOpcion;

					cout << "\nIngrese el servicio requerido: \n";
					cout << "1. Nuevo Servicio\n";
					cout << "2. Modificar Servicio\n";
					cout << "3. Falla en Servicio\n";
					cout << "4. Reclamos\n";
					cout << "5. Terminar Contrato\n";
				}
				try
				{
					cin >> opcion;

					switch (opcion)
					{
					case 1:
						servicio = "Nuevo Servicio";
						break;
					case 2:
						servicio = "Modificar Servicio";
						break;
					case 3:
						servicio = "Falla en Servicio";
						break;
					case 4:
						servicio = "Reclamos";
						break;
					case 5:
						servicio = "Terminar contrato";
						break;
					default:
						cout << "Valor invalido: No se ha podido ingresar al cliente.";
						break;
					}

					if (opcion > 0 && opcion < 6)
					{
						persona nuevo(cadenaOpcion, servicio);
						cola.push(nuevo);
						cout << "Cliente ingresado exitosamente\n";
					}
				}
				catch (const std::exception&)
				{
					cout << "Valor invalido: No se ha podido ingresar al cliente.";
				}
			}
			break;
			case 2:
			{
				cola.pop("N/A");
				cout << "\nSe ha retirado la primera persona en cola...\n";
			}
				break;
			case 3:
			{
				cout << "Elige el agente a desocupar: \n";
				cout << "1. Agente 1\n";
				cout << "2. Agente 2\n";
				cout << "3. Agente 3\n";
				cout << "4. Agente 4\n";
				cout << "5. Agente 5\n";

				try
				{
					cin >> opcion;

					if (opcion > 0 && opcion < 6)
					{
						agentes[opcion - 1].desocupar();
						cout << "\n Se ha desocupado el agente...";
					}
					else
					{
						cout << "\n Ha ingresado un valor invalido...";
					}
				}
				catch (const std::exception&)
				{
					cout << "\n Ha ingresado un valor invalido...";
				}
				cout << "\n";
			}
			break;
			case 4:
			{
				cout << "Elige el agente a ocupar: \n";
				cout << "1. Agente 1\n";
				cout << "2. Agente 2\n";
				cout << "3. Agente 3\n";
				cout << "4. Agente 4\n";
				cout << "5. Agente 5\n";

				try
				{
					cin >> opcion;

					if (opcion > 0 && opcion < 6)
					{
						if (agentes[opcion - 1].ocupado == false)
						{
							agentes[opcion - 1].ocupar();
							cola.pop(to_string(opcion));
						}
						else
						{
							cout << "\nEl agente seleccionado se encuentra ocupado...\n";
						}
					}
					else
					{
						cout << "\n Ha ingresado un valor invalido...";
					}
				}
				catch (const std::exception&)
				{
					cout << "\nHa ingresado un valor invalido...";
				}
				cout << "\n";
			}
				break;
			case 5:
			{
				cola.mostrar();
				cout << "\n";
			}
				break;
			case 6:
			{
				cout << "Ingrese el nombre de la perosna al buscar: ";
				cin >> cadenaOpcion;
				cout << "\n";
				cola.buscar(cadenaOpcion);
				cout << "\n";
			}
				break;
			case 7:
				cola.historial();
				break;
			case 8:
				salir = true;
				break;
			default:
				cout << "\nHa ingresado un valor invalido...\n";
				break;
				}
				system("pause");
			}
			catch (const std::exception&)
			{
				cout << "\nHa ingresado un valor invalido...\n";
			}

			arch.limpiar();
		} while (!salir);

		//Termina Menu Principal


		//Resumen

		cout << "\n";
		for (int i = 0; i < 5; i++)
		{
			agentes[i].mostrar();
			cout << "\n";
		}

		//Escribir archivo
		arch.escribir(cola);
		system("pause");
	}