#pragma once
#include <vector>
#include "Criatura.h"
class CriaturaCompuesta : public Criatura{
public:
	CriaturaCompuesta();
	~CriaturaCompuesta();
	void agregarCriatura(Criatura*);
	
private:
	vector<Criatura *> criaturas;

};

CriaturaCompuesta::CriaturaCompuesta(){
	this->nombre = nombreCriatura()+" CriaturaCompuesta";
}

void CriaturaCompuesta::agregarCriatura(Criatura* c){
	cout<<"CRIATURA COMPUESTA AHORA TAMBIEN ESTA COMPUESTA POR UNA: "<<c->getNombre()<<endl;
	criaturas.push_back(c);
}