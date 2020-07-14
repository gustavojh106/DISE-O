#pragma once
#include <string>
#include <iostream>
using namespace std;

class ReproduccionEspecie{
	public:
		string especie;
	public:
		virtual void reproducir(string)=0;
};