//#pragma once

#include <sstream>
using namespace std;

#include "ObtAsg.h"
class Entero : public ObtAsg< int >{
public:
	Entero();
	Entero(int v);
	virtual ~Entero();

	virtual void asg(int o) override;
	virtual int obt() const override;
	virtual tipo::tipo_atributo obtTipo() const override;
	virtual string toString() const override;

private:
	int valor;
};

Entero::Entero()
{
}

Entero::Entero(int v) : valor(v)
{
}

Entero::~Entero()
{
}

void Entero::asg(int o)
{
	valor = o;
}

int Entero::obt() const
{
	return valor;
}

tipo::tipo_atributo Entero::obtTipo() const
{
	return tipo::tipo_atributo::Entero;
}

string Entero::toString() const
{
	ostringstream o;
	o << valor;
	return o.str();
}