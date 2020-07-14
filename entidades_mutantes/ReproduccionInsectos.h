#pragma once
#include "ReproduccionEspecie.h"

class ReproduccionInsectos: public ReproduccionEspecie{
	public:
		ReproduccionInsectos(){
			this->especie = "INSECTO";
		}
		void reproducir(string nombre){
			cout<<"La: "<<nombre<<" se reproduce con: "<<this->especie<<endl;
		}
};