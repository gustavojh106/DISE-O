//#pragma once

#include "Valor.h"

template < typename T >
class ObtAsg : public Valor
{
public:

	ObtAsg() {};
	virtual ~ObtAsg() {};
		
	virtual void asg(T o) = 0;
	virtual T obt() const = 0;
};
