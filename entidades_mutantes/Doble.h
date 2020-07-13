//#pragma once

#include <sstream>
using namespace std;

#include "ObtAsg.h"

class Doble : public ObtAsg< double >
{
public:
	Doble();
	Doble(double d);
	virtual ~Doble();

	virtual void asg(double o) override;
	virtual double obt() const override;
	virtual tipo::tipo_atributo obtTipo() const override;
	virtual string toString() const override;

private:
	double valor;
};

Doble::Doble()
{
}

Doble::Doble(double d) : valor(d)
{
}

Doble::~Doble()
{
}

void Doble::asg(double o)
{
	valor = o;
}

double Doble::obt() const
{
	return valor;
}

tipo::tipo_atributo Doble::obtTipo() const
{
	return tipo::tipo_atributo::Doble;
}

string Doble::toString() const
{
	ostringstream o;
	o << valor;
	return o.str();
}