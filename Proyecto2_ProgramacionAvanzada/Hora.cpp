#include "pch.h"
#include "Hora.h"
#include <string>
#include <sstream>
#include <iomanip>

Hora::Hora()
{
}
Hora::~Hora()
{
}

string Hora::horaActual() {
	time_t tiempo = time(NULL);
	return fechaParaHora(ctime(&tiempo));
}

string Hora::fechaParaHora(string fecha) {

	stringstream ss(fecha);
	string token;

	int i = 0;
	string hora;

	while (getline(ss, token, ' '))
	{
		//contar cantidad de espacios en el String de fecha devuelto po ctime
		//se toma la hora,miutos,seg y se ignora lo demas

		if (i==4)
		{
			hora = token;
		}
		i++;
	}
	return hora;
}

string Hora::tiempoEnCola(string hora1, string hora2) {
	int horas, minutos, segundos;
	string tiempo = "";

	horas = (obtenerHoras(hora1) - obtenerHoras(hora2));
	minutos = (obtenerMinutos(hora1) - obtenerMinutos(hora2));
	segundos = (obtenerSegundos(hora1) - obtenerSegundos(hora2));

	if (segundos < 0)
	{
		segundos *= -1;
	}
	if (minutos < 0)
	{
		minutos *= -1;
	}
	if (horas < 0) {
		horas *= -1;
	}
	if (horas != 0) {
		tiempo += (to_string(horas) + "h ");
	}
	if (minutos != 0) {
		tiempo += (to_string(minutos) + "m ");
	}
	if (segundos != 0) {
		tiempo += (to_string(segundos) + "s");
	}
	return tiempo;
}

int Hora::obtenerHoras(string hora) {
	return dividirString(hora, 0);
}
int Hora::obtenerMinutos(string hora) {
	return dividirString(hora, 1);
}
int Hora::obtenerSegundos(string hora) {
	return dividirString(hora, 2);
}

int Hora::dividirString(string cadena, int posicion) {

	stringstream ss(cadena);
	string token;

	int i = 0;
	int valor = 0;

	while (getline(ss, token, ':'))
	{
		if (i == posicion)
		{
			valor = stoi(token);
		}
		i++;
	}
	return valor;
}
