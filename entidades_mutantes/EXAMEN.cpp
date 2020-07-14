#include "Enjambre.h"
#include "Abeja.h"
#include "Hormiga.h"
#include "CriaturaCompuesta.h"


int main(){
	
	//PUNTO 1: AGREGAR PROPIEDADES ENTERO, DOBLE, BOOL, HILERAS O VECTORES COMPUESTOS DE TODOS LOS ANTERIORES
	//---------------------------------------------------//
		//SE CREAN LOS ATRIBUTOS PARA UNA CRIATURA
		printf("\n");
		printf("PUNTO 1\n");
		int edad = 17;
		double energia = 2.3;
		string nombre_propio = "LUCAS";
		bool carnivoro = true;
		ReproduccionEspecie * especie = new ReproduccionMamiferos();
		string s;
		
		
		vector<Valor*> vectorCompuesto;
		vectorCompuesto.push_back(new Hilera("PERRO"));
		vectorCompuesto.push_back(new Entero(2));
		//SE CREA UNA CRIATURA SIN PARAMETROS:
		Criatura * hormiga = new Hormiga();
		printf("SE CREO UNA %s con especie: %s\n",hormiga->getNombre().c_str(),hormiga->getEspecie().c_str() );
		if(hormiga->obtCarnivoro()){
			s = "TRUE";
		}
		else{
			s = "FALSE";
		}
		printf(" edad: %d energia: %lf nombre_Propio: %s \n\n", hormiga->obtEdad(), hormiga->obtEnergia(), hormiga->obtNombrePropio().c_str());
		
		//SE CREA UNA CRIATURA CON PARAMETROS:
		Criatura * abeja = new Abeja();
		abeja->setAtributos(edad, energia, nombre_propio, carnivoro, especie, vectorCompuesto);
		printf("SE CREO UNA %s con especie: %s\n",abeja->getNombre().c_str(),abeja->getEspecie().c_str() );
		if(abeja->obtCarnivoro()){
			s = "TRUE";
		}
		else{
			s = "FALSE";
		}
		printf(" edad: %d energia: %lf nombre_Propio: %s \n\n", abeja->obtEdad(), abeja->obtEnergia(), abeja->obtNombrePropio().c_str());
		
		
		
		
	//---------------------------------------------------//
	
	
	//PUNTO 2: CREAR CRIATURAS COMPUESTAS POR OTRAS CRIATURAS
	//---------------------------------------------------//
		printf("\n");
		printf("PUNTO 2\n");
		CriaturaCompuesta * criaturaCompuesta = new CriaturaCompuesta();
		printf("SE CREO UNA %s con especie: %s\n",criaturaCompuesta->getNombre().c_str(),criaturaCompuesta->getEspecie().c_str() );
		if(criaturaCompuesta->obtCarnivoro()){
			s = "TRUE";
		}
		else{
			s = "FALSE";
		}
		printf(" edad: %d energia: %lf nombre_Propio: %s \n\n", criaturaCompuesta->obtEdad(), criaturaCompuesta->obtEnergia(), criaturaCompuesta->obtNombrePropio().c_str());
		
		
		criaturaCompuesta->agregarCriatura(hormiga); //CRIATURACOMPUESTA ESTA FORMADA POR HORMIGA Y ABEJA
		criaturaCompuesta->agregarCriatura(abeja);
	//---------------------------------------------------//
	
	//PUNTO 3: CREAR ENJAMBRE CON CRIATURAS IGUALES, NO PERMITE CRIATURAS DIFERENTES
	//---------------------------------------------------//
		printf("\n");
		printf("PUNTO 3\n");
		Enjambre<Abeja> enjambre;
		enjambre.agregarCriatura(abeja); //SI DEJA QUE SE AGREGUE UNA ABEJA, PORQUE ES DE TIPO ABEJA
		
		enjambre.agregarCriatura(hormiga); //NO DEJA QUE SE AGREGUE UNA HORMIGA
	//---------------------------------------------------//
	
	//PUNTO 4: LAS CRIATURAS PERTENECEN A UNA ESPECIE Y SE REPRODUCEN SEGUN SU ESPECIE
	//---------------------------------------------------//
		printf("\n");
		printf("PUNTO 4\n");
		int edad2 = 21;
		double energia2 = 5.2;
		string nombre_propio2 = "DAVID";
		bool carnivoro2 = false;
		ReproduccionEspecie * especie2 = new ReproduccionInsectos();
		vector<Valor*> vectorCompuesto2;
		vectorCompuesto2.push_back(new Hilera("PAJARO"));
		vectorCompuesto2.push_back(new Entero(7));
		Criatura * abeja2 = new Abeja();
		printf("SE CREO UNA %s con especie: %s\n",abeja2->getNombre().c_str(),abeja2->getEspecie().c_str() );
		abeja2->setAtributos(edad2, energia2, nombre_propio2, carnivoro2, especie2, vectorCompuesto2);
		if(abeja2->obtCarnivoro()){
			s = "TRUE";
		}
		else{
			s = "FALSE";
		}
		printf(" edad: %d energia: %lf nombre_Propio: %s \n\n", abeja2->obtEdad(), abeja2->obtEnergia(), abeja2->obtNombrePropio().c_str());
		//LA ABEJA 2 SE REPRODUCE DE ACUERDO A SU ESPECIE:
		
		abeja2->reproducirse();
	
	//---------------------------------------------------//
	
	
	return 0;
}