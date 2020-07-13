#pragma once
//#include <string>
#include "tipo.h"

class Valor
{
public:
	Valor() {};
	virtual ~Valor() {};
	virtual tipo::tipo_atributo obtTipo() const = 0;
	virtual string toString() const = 0;
};
