#pragma once
#include <string>

using namespace std;

class Hora
{
public:
	static string horaActual();
	static string tiempoEnCola(string hora1, string hora2);

private:
	static string fechaParaHora(string fecha);
	static int dividirString(string cadena, int posicion);
	static int obtenerHoras(string hora);
	static int obtenerMinutos(string hora);
	static int obtenerSegundos(string hora);

	Hora();
	~Hora();
};

