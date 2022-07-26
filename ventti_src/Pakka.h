#pragma once
#include "common_defs.h"
#include "Kortti.h"

class Pakka
{
public:
	Pakka();
	void alusta();
	void sekoita();
	void tulostaPakka();
	Kortti* nostaKortti();

private:
	
	Kortti pakka[KORTTIPAKKA];
	int seuraavaKortti;
};

