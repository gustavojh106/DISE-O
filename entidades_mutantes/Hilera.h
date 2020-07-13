//#pragma once
//#include <string>
#include <sstream>
using namespace std;
#include "ObtAsg.h"



class Hilera : public ObtAsg< string >{
public:
	Hilera();
	Hilera(string v);
	virtual ~Hilera();

	virtual void asg(string o) override;
	virtual string obt() const override;
	virtual tipo::tipo_atributo obtTipo() const override;
	virtual string toString() const override;

private:
	string valor;
};

Hilera::Hilera(){ //CONSTRUCTOR SIN PARAM
	
}

Hilera::Hilera(string v) : valor(v){

}

Hilera::~Hilera(){
	
}

void Hilera::asg(string o){//SET DE VALOR 
	valor = o;
}

string Hilera::obt() const{
	return valor;
}

tipo::tipo_atributo Hilera::obtTipo() const{
	return tipo::tipo_atributo::Hilera;
}

string Hilera::toString() const{
	ostringstream o;
	o << valor;
	return o.str();
}