#pragma once
#include "Cromosoma.h"
class Poblacion
{
private:
	Cromosoma** cromosomas;
	int ind;
	int tamMax;
public:
	Poblacion(int tamMax);
	~Poblacion();
	void crearCromosomasRandom();
	void mostrarCromosomas();
	int calcularFuerzaTotal();
	void generarNuevosCromosomas(Cromosoma* cr1, Cromosoma* cr2, float Prob1, float Prob2);
	Cromosoma* seleccionarCromosoma();
	Cromosoma* crossover(Cromosoma* cr1, Cromosoma* cr2, int n);
	Cromosoma* mutacion(Cromosoma* cr1);
	Cromosoma* cromosomaMasFuerte();
	void registrarCromosoma(Cromosoma* cr1);

	int getInd();

};

Poblacion::Poblacion(int tamMax)
{
	this->tamMax = tamMax;
	ind = 0;
	cromosomas = new Cromosoma * [tamMax];
}
Poblacion::~Poblacion()
{

}

void Poblacion::crearCromosomasRandom()
{
	while (ind < tamMax)
	{
		cromosomas[ind] = new Cromosoma;
		cromosomas[ind]->crearCromosomaRandom();
		ind++;
	}
}
void Poblacion::mostrarCromosomas()
{
	for (int i = 0; i < tamMax; i++)
	{
		cout << i << ":  ";
		cromosomas[i]->mostrarGenes();
		cout << "\n";
	}

}
int Poblacion::calcularFuerzaTotal()
{
	int contador = 0;
	for (int i = 0; i < tamMax; i++)
	{
		contador = contador + cromosomas[i]->obtenerFuerza();
	}
	return contador;
}
void Poblacion::generarNuevosCromosomas(Cromosoma* nuevocr1, Cromosoma* nuevocr2, float Prob1, float Prob2)
{
	Cromosoma* cr1 = seleccionarCromosoma();
	Cromosoma* cr2 = seleccionarCromosoma();
	float r = (rand() % 10) / 10;
	if (r < Prob1)
	{
		nuevocr1 = crossover(cr1, cr2, rand() % 20);
		nuevocr2 = crossover(cr2, cr1, rand() % 20);
	}
	else
	{
		nuevocr1 = cr1;
		nuevocr2 = cr2;
	}
	r = (rand() % 10) / 10;
	if (r < Prob2)
	{
		nuevocr1 = mutacion(nuevocr1);
		nuevocr2 = mutacion(nuevocr2);
	}

}
Cromosoma* Poblacion::seleccionarCromosoma()
{
	int r = rand() % tamMax;
	return cromosomas[r];
}
Cromosoma* Poblacion::crossover(Cromosoma* cr1, Cromosoma* cr2, int n)
{
	Cromosoma* nuevoCromosoma = new Cromosoma;

	for (int i = 0; i < 20; i++)
	{
		if (i < n)
		{
			nuevoCromosoma->modificarGen(i, cr1->obtenerGen(i));
		}
		else
		{
			nuevoCromosoma->modificarGen(i, cr2->obtenerGen(i));
		}
	}
	return nuevoCromosoma;
}
Cromosoma* Poblacion::mutacion(Cromosoma* cr1)
{
	int n = rand() % 20;
	cr1->intercambiarGen(n);
	return cr1;
}
Cromosoma* Poblacion::cromosomaMasFuerte()
{
	Cromosoma* cromosomaFuerte = cromosomas[0];
	for (int i = 1; i < tamMax; i++)
	{
		if (cromosomaFuerte->obtenerFuerza() < cromosomas[i]->obtenerFuerza())
		{
			cromosomaFuerte = cromosomas[i];
		}
	}
	return cromosomaFuerte;

}
void Poblacion::registrarCromosoma(Cromosoma* cr1)
{
	while (ind < tamMax)
	{
		cromosomas[ind] = cr1;
		ind++;
	}
}

int Poblacion::getInd()
{
	return ind;
}