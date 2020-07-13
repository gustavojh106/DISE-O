#include "Criatura.h"
#include <vector>

template < typename T >
class Enjambre{

private:
	vector<T*> enjambre;
	
public:
		void agregarCriatura(Criatura* c){
			T * criatura = dynamic_cast<T *>(c);
			if(criatura){
				enjambre.push_back(c);
			}	
		}
		
		vector<T*> getEnjambre(){			
			return enjambre;
		}

};

