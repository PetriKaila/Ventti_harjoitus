#pragma once

#include "common_defs.h"
#include "Kortti.h"


class Pelaaja
{
public:
	Pelaaja() 
	{
		nimi = "";
		vapaaIndeksi = 0;	
	}
	void asetaNimi(string nimi);
	string haeNimi();	
	int haeVapaaIndeksi();
	void tulostaKasi();
	int laskeKasi();
	void tallennaKortti(Kortti* kortti);
	
protected:
	void apuPrintti(string mjono, int a);

private:
	Kortti* kortit[KORTIN_NUMEROT];
	int tarkistaArvo();
	Kortti* haeAssa();

	int vapaaIndeksi;
	string nimi;
};


