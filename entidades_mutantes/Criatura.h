#pragma once

#include <unordered_map>
#include <memory>
#include <utility>
#include <vector>
using namespace std;

#include "Valor.h"
#include "Entero.h"
#include "Doble.h"


class Criatura{
public:
	Criatura();
	Criatura(int edad, double energia);
	~Criatura();

	static string nombre();

	/* OBTENEDORES CONVENCIONALES */
	int obtEdad() const;
	double obtEnergia() const;

	/* ASIGNADORES CONVENCIONALES */
	void asgEdad(int ne);
	void asgEnergia(double ne);

	/* VECTOR DE ATRIBUTOS */
	void obtAtributos(vector< pair< string, Valor* > >& vectorValores);

private:
	typedef unordered_map< string, Valor* > t_map_atributos;
	typedef unordered_map< string, Valor* >::const_iterator t_atributos_const_iterador;

	t_map_atributos atributos;
	vector< Valor* > vectorValores;
};

// inicializa atributos con la cantidad exacta requerida de cubetas, una por cada atributo
Criatura::Criatura() : atributos(2)
{
	Entero* vedad_p = new Entero(0);
	Doble* venergia_p = new Doble(5.5);
	atributos["edad"] = vedad_p;
	atributos["energia"] = venergia_p;
}

// inicializa atributos con la cantidad exacta requerida de cubetas, una por cada atributo
Criatura::Criatura(int edad, double energia) : atributos(2)
{
	Entero* vedad_p = new Entero(edad);
	Doble* venergia_p = new Doble(energia);
	atributos["edad"] = vedad_p;
	atributos["energia"] = venergia_p;
}

Criatura::~Criatura()
{ // se debe liberar la memoria de todos los atributos, de lo contrario queda una fuga
	for (auto a : atributos)
		a.second->~Valor(); // enlace dinámico de destructores!!!
}

string Criatura::nombre()
{
	return "Criatura";
}

int Criatura::obtEdad() const
{
	return static_cast< Entero* >(atributos.at("edad"))->obt();
}

double Criatura::obtEnergia() const
{
	return static_cast< Doble* >(atributos.at("energia"))->obt();
}

void Criatura::asgEdad(int ne)
{
	static_cast<Entero*>(atributos.at("edad"))->asg(ne);
}

void Criatura::asgEnergia(double ne)
{
	static_cast<Doble*>(atributos.at("energia"))->asg(ne);
}

void Criatura::obtAtributos(vector< pair< string, Valor* > >& vectorValores)
{
	int tamanyo = atributos.size();
	vectorValores.resize(tamanyo);
	int j = 0;
	for (auto i : atributos)
	{
		vectorValores[j] = i;
		j++;
	}
}