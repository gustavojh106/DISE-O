//#pragma once

#include <sstream>
using namespace std;
#include "ObtAsg.h"

class Booleano : public ObtAsg< bool >{
public:
	Booleano();
	Booleano(bool v);
	virtual ~Booleano();

	virtual void asg(bool o) override;
	virtual bool obt() const override;
	virtual tipo::tipo_atributo obtTipo() const override;
	virtual string toString() const override;

private:
	bool valor;
};

Booleano::Booleano()
{
}

Booleano::Booleano(bool v) : valor(v)
{
}

Booleano::~Booleano()
{
}

void Booleano::asg(bool o)
{
	valor = o;
}

bool Booleano::obt() const
{
	return valor;
}

tipo::tipo_atributo Booleano::obtTipo() const
{
	return tipo::tipo_atributo::Booleano;
}

string Booleano::toString() const
{
	ostringstream o;
	o << valor;
	return o.str();
}