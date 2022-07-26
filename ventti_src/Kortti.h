#pragma once
#include <string>
#include "common_defs.h"

using namespace std;

class Kortti
{
public:
	Kortti();

	int arvo;
	string maa;
	bool nostettu; 
	int Tulostus();
	void muutaAssa(int aArvo);

	void HaeAssa();
	
	

};

