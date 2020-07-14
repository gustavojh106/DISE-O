#pragma once

#include <unordered_map>
#include <memory>
#include <utility>
#include <vector>
using namespace std;
#include <iostream>
//#include "Valor.h"
#include "Entero.h"
#include "Doble.h"
#include "Hilera.h"
#include "Booleano.h"
#include "PropiedadCompuesta.h"

#include "ReproduccionEspecie.h"
#include "ReproduccionInsectos.h"
#include "ReproduccionMamiferos.h"

class Criatura{
public:
	Criatura();
	//Criatura(int edad, double energia, string nombre_propio, bool carnivoro, ReproduccionEspecie * e, vector<Valor*> vectorCompuesto);
	void setAtributos(int edad, double energia, string nombre_propio, bool carnivoro, ReproduccionEspecie * e, vector<Valor*> vectorCompuesto);
	~Criatura();

	string nombreCriatura();
	string getNombre();
	string getEspecie();
	/* OBTENEDORES CONVENCIONALES */
	int obtEdad() const;
	double obtEnergia() const;
	string obtNombrePropio() const;
	bool obtCarnivoro() const;

	/* ASIGNADORES CONVENCIONALES */
	void asgEdad(int ne);
	void asgEnergia(double ne);

	/* VECTOR DE ATRIBUTOS */
	void obtAtributos(vector< pair< string, Valor* > >& vectorValores);
	void setEspecie(ReproduccionEspecie * e);
	void reproducirse();
	

protected:
		string nombre;
		ReproduccionEspecie * especie;
	
private:
	typedef unordered_map< string, Valor* > t_map_atributos;
	typedef unordered_map< string, Valor* >::const_iterator t_atributos_const_iterador;

	t_map_atributos atributos;
	vector< Valor* > vectorValores;
	
};

// inicializa atributos con la cantidad exacta requerida de cubetas, una por cada atributo
Criatura::Criatura() : atributos(5)
{
	Entero* vedad_p = new Entero(0);
	Doble* venergia_p = new Doble(5.5);
	Booleano * vcarnivoro_p = new Booleano(true);
	Hilera * vnombrepropio_p = new Hilera("LUIS");
	vector<Valor*> vectorCompuesto;
	vectorCompuesto.push_back(new Hilera("JUAN"));
	vectorCompuesto.push_back(new Booleano(false));
	
	PropiedadCompuesta * compuesta = new PropiedadCompuesta(vectorCompuesto);
	
	atributos["edad"] = vedad_p;
	atributos["energia"] = venergia_p;
	atributos["carnivoro"] = vcarnivoro_p;
	atributos["nombre_propio"] = vnombrepropio_p;
	atributos["compuesto"] = compuesta;
	
	//UNA CRIATURA SIEMPRE TIENE UNA ESPECIE
	ReproduccionEspecie * e = new ReproduccionInsectos();
	setEspecie(e);
	
	
}

void Criatura::setEspecie(ReproduccionEspecie * e){
	this->especie = e;
}
string Criatura::getEspecie(){
	return this->especie->especie;
}
void Criatura::reproducirse(){
	especie->reproducir(this->nombre);
}
string Criatura::nombreCriatura(){
	return "Criatura";
}

string Criatura::getNombre(){	
	//cout<<this->nombre;
	return nombre;
}

// inicializa atributos con la cantidad exacta requerida de cubetas, una por cada atributo
void Criatura::setAtributos(int edad, double energia, string nombre, bool carnivoro, ReproduccionEspecie * e, vector<Valor*> vectorCompuesto){
	Entero* vedad_p = new Entero(edad);
	Doble* venergia_p = new Doble(energia);
	Booleano * vcarnivoro_p = new Booleano(carnivoro);
	Hilera * vnombrepropio_p = new Hilera(nombre);
	PropiedadCompuesta * compuesta = new PropiedadCompuesta(vectorCompuesto);
	
	atributos["edad"] = vedad_p;
	atributos["energia"] = venergia_p;
	atributos["carnivoro"] = vcarnivoro_p;
	atributos["nombre_propio"] = vnombrepropio_p;
	atributos["compuesto"] = compuesta;
	
	setEspecie(e);	
	
}

Criatura::~Criatura()
{ // se debe liberar la memoria de todos los atributos, de lo contrario queda una fuga
	for (auto a : atributos)
		a.second->~Valor(); // enlace dinámico de destructores!!!
}


int Criatura::obtEdad() const
{
	return static_cast< Entero* >(atributos.at("edad"))->obt();
}

double Criatura::obtEnergia() const
{
	return static_cast< Doble* >(atributos.at("energia"))->obt();
}

string Criatura::obtNombrePropio() const{
	
	return static_cast< Hilera* >(atributos.at("nombre_propio"))->obt();
	
}

bool Criatura::obtCarnivoro() const{
	
	return static_cast< Booleano* >(atributos.at("carnivoro"))->obt();
	
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