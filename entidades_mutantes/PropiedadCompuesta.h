#pragma once
#include <sstream>
#include <vector>
#include "Valor.h"
using namespace std;

class PropiedadCompuesta : public Valor{
public:
	PropiedadCompuesta();
	PropiedadCompuesta(vector<Valor*> v);
	void agregarValores(Valor * v);
	virtual ~PropiedadCompuesta();
	virtual tipo::tipo_atributo obtTipo() const override;
	virtual string toString() const override;

private:
	vector<Valor*> valores;
};

void PropiedadCompuesta::agregarValores(Valor * v){
	valores.push_back(v);
}

PropiedadCompuesta::PropiedadCompuesta(){
	
}

PropiedadCompuesta::PropiedadCompuesta(vector<Valor*> v) : valores(v){
	
}

PropiedadCompuesta::~PropiedadCompuesta(){
	
}

tipo::tipo_atributo PropiedadCompuesta::obtTipo() const
{
	return tipo::tipo_atributo::PropiedadCompuesta;
}

string PropiedadCompuesta::toString() const{
	string temp = "";
	int size = valores.size();
	for(int i = 0; i< size; ++i){
		temp += valores[i]->toString();
		temp += " ";
	}
	return temp;
}