#include <iostream>
#include <map>
#include <utility>
using namespace std;

#include "tipo.h"
#include "Criatura.h"
#include "ConstructorSerializadorXML.h"
#include "ConstructorSerializadorJSON.h"


int main()
{
	Criatura c0;
	cout << "atributos de la criatura 0: " << endl;
	cout << c0.obtEdad() << endl;
	cout << c0.obtEnergia() << endl;

	Criatura c1(7, 4.5);
	cout << "atributos de la criatura 1: " << endl;
	cout << c1.obtEdad() << endl;
	cout << c1.obtEnergia() << endl;

	c1.asgEdad(6);
	c1.asgEnergia(3.5);
	cout << "atributos de la criatura 1 modificada: " << endl;
	cout << c1.obtEdad() << endl;
	cout << c1.obtEnergia() << endl;

	cout << "Ahora usando el serializador XML: " << endl;
	ConstructorSerializadorAbstracto* cs;
	cs = new ConstructorSerializadorJSON(); // se crea el serializador
	vector< pair< string, Valor* > >  vv;
	c0.obtAtributos(vv); // se obtiene el vector de atributos
	cs->inicioObjeto(string("Criatura"));
	for (auto v : vv)
		switch (v.second->obtTipo()) 
		{
			case tipo::Entero: cs->serializarEntero(v);
				break;
			case tipo::Doble: cs->serializarDoble(v);
				break;
		}
	cs->finObjeto();
	cout << cs->obtSerializacion() << endl;
	cin.ignore();
}