 #include <iostream>
#include "Valikko.h"
#include "Jakaja.h"
#include "common_defs.h"
/*Tämän pelin sääntöjen mukaan jakajan kortteja ei näytetä, vasta kuin lopuksi.*/
void Jakaja::tulostaKasi() {
	int indeksi = haeVapaaIndeksi();
	cout <<"	" << haeNimi() << "n kortit:\n";
	apuPrintti("	\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF  ", indeksi);
	apuPrintti("	\xB3++++++++\xB3  ", indeksi);
	apuPrintti("	\xB3++    ++\xB3  ", indeksi);		
	apuPrintti("	\xB3++    ++\xB3  ", indeksi);
	apuPrintti("	\xB3++    ++\xB3  ", indeksi);
	apuPrintti("	\xB3++++++++\xB3  ", indeksi);
	apuPrintti("	\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9  ", indeksi);
	
	cout << endl;
}
