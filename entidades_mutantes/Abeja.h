#include "Criatura.h"

class Abeja : public Criatura{
public:
	Abeja();
	~Abeja();

};

Abeja::Abeja(){
	this->nombre = nombreCriatura()+" Abeja";
}