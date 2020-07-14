#pragma once
#include "Criatura.h"

class Hormiga : public Criatura{
public:
	Hormiga();
	~Hormiga();

};

Hormiga::Hormiga(){
	this->nombre = nombreCriatura()+" Hormiga";
}