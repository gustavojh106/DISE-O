#pragma once
#include "ReproduccionEspecie.h"

class ReproduccionMamiferos: public ReproduccionEspecie{
	public:
		ReproduccionMamiferos(){
			this->especie = "MAMIFEROS";
		}
		void reproducir(string nombre){
			cout<<"La: "<<nombre<<" se reproduce con: "<<this->especie<<endl;
		}
};