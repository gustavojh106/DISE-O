#pragma once
#include "Criatura.h"
#include <vector>
#include <typeinfo>

template < typename T >
class Enjambre{

private:
	vector<T*> enjambre;
	
public:
		void agregarCriatura(Criatura* c){
			T * criatura = new T();
			if(criatura->getNombre() == c->getNombre()){
				enjambre.push_back((T*)c);
				printf("Se unio una: %s al enjambre\n",c->getNombre().c_str());
			}
			else{
				printf("Se trato de unir una: %s al enjambre, pero el enjambre no acepta a ese tipo de criatura\n", c->getNombre().c_str());
			}
		}
		
		vector<T*> getEnjambre(){			
			return enjambre;
		}

};


//