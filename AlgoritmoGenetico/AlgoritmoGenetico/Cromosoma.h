#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
using namespace std;
#define TAM 20

class Cromosoma
{
private:
	int genes[TAM];
	int fuerza;
public:
	Cromosoma();
	~Cromosoma();
	void mostrarGenes();
	void crearCromosomaRandom();
	int calcularfuerza();
	void modificarGen(int pos, int val);
	int obtenerGen(int pos);
	int obtenerFuerza();
	void intercambiarGen(int pos);
};

Cromosoma::Cromosoma()
{
	fuerza = calcularfuerza();
}
Cromosoma::~Cromosoma()
{

}
void Cromosoma::mostrarGenes()
{
	for (int i = 0; i < TAM; i++)
	{
		cout << genes[i] << " ";
	}
}
void Cromosoma::crearCromosomaRandom()
{
	srand(time(NULL));
	for (int i = 0; i < TAM; i++)
	{
	     genes[i]=rand()%2; 
	}
}
int Cromosoma::calcularfuerza()
{
	int contador = 0;
	for (int i = 0; i < TAM; i++)
	{
		if (genes[i] == 1)
		{
			contador++;
		}
	}
	return contador;
}
void Cromosoma::modificarGen(int pos, int val)
{
	genes[pos] = val;
}
int Cromosoma::obtenerGen(int pos)
{
	return genes[pos];
}
int Cromosoma::obtenerFuerza()
{
	return fuerza;
}
void Cromosoma::intercambiarGen(int pos)
{
	if (genes[pos] == 0)
	{
		genes[pos] = 1;
	}
	else
	{
		genes[pos] = 0;
	}
}

