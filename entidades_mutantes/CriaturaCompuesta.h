#include <vector>
#include "Criatura.h"
class CriaturaCompuesta : public Criatura{
public:
	CriaturaCompuesta();
	~CriaturaCompuesta();
	agregarCriatura(Criatura*);
	
private:
	vector<Criatura *> criaturas;

};

CriaturaCompuesta::CriaturaCompuesta(){
	this->nombre = nombreCriatura()+" CriaturaCompuesta";
}

CriaturaCompuesta::agregarCriatura(Criatura* c){
	
	criaturas.push_back(c);
}