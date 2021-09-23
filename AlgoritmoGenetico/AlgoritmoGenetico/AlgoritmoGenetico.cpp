// AlgoritmoGenetico.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <string>
#include<iostream>
#include "Cromosoma.h"
#include "Poblacion.h"

using namespace std;

void experimento(float Prob1, float Prob2)
{

	Poblacion poblacionInicial(100);
	poblacionInicial.crearCromosomasRandom();

	Cromosoma* nuevocr1 = new Cromosoma;
	Cromosoma* nuevocr2 = new Cromosoma;
	for (int i = 0; i < 20; i++)
	{
		Poblacion poblacionFinal(100);
		while (poblacionFinal.getInd() < 100)
		{
			poblacionInicial.generarNuevosCromosomas(nuevocr1, nuevocr2, Prob1, Prob2);
			poblacionFinal.registrarCromosoma(nuevocr1);
			poblacionFinal.registrarCromosoma(nuevocr2);
		}
		cout << "Generacion " << i;
		cout << "cromosoma mas fuerte:" << poblacionFinal.cromosomaMasFuerte()->obtenerFuerza();
		cout << "fuerza total: " << poblacionFinal.calcularFuerzaTotal();
		cout << "\n";
		poblacionInicial = poblacionFinal;

	}
}
int main()
{
	string op;
	float Prob1;
	float Prob2;
	do {
		cout << "a.experimento 1" << endl;
		cout << "b.experimento 2" << endl;
		cout << "c.experimento 3" << endl;
		cout << "c.experimento 4" << endl;

		cin >> op;

		if (op == "a")
		{
			Prob1 = 0.7;
			Prob2 = 0.001;
			cout << "Experimento 1";
			experimento(Prob1, Prob2);
		}
		if (op == "b")
		{
			Prob1 = 0;
			Prob2 = 0.001;
			cout << "Experimento 2";
			experimento(Prob1, Prob2);
		}
		if (op == "c")
		{
			Prob1 = 0.7;
			Prob2 = 0;
			cout << "Experimento 3";
			experimento(Prob1, Prob2);
		}
		if (op == "d")
		{
			Prob1 = 0.9;
			Prob2 = 0.001;
			cout << "Experimento 4";
			experimento(Prob1, Prob2);
		}

	} while (op != "s");

	return 0;
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln