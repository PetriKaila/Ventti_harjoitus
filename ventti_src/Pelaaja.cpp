#include "Pelaaja.h"
#include <iostream>
#include "Valikko.h"
#include "common_defs.h"
#include "Pakka.h"
using namespace std;

void Pelaaja::tallennaKortti(Kortti* kortti) {
	kortit[vapaaIndeksi] = kortti;
	vapaaIndeksi++;

	// ässäkortti 1:n käsittely
	if (kortti->arvo == 1) {
		int assan_arvo = tarkistaArvo();
		kortti->muutaAssa(assan_arvo);
	}
	/* kun käden yhteisarvo on yli 21, tarkistetaan, onko kädessä 14 - arvoisia ässiä
	 ja mikäli on, muunnetaan ne 1:ksi */
	else if (laskeKasi() > 21) {
		Kortti* assakortti = haeAssa();
		if (assakortti != NULL) {
			assakortti->muutaAssa(1);
		}
	}
}

/* Tarkistetaan, pitääkö ässä käsitellä 1:na vai 14:a */
int Pelaaja::tarkistaArvo() {

	if (laskeKasi() <= 7) {
		return 14;
	}
	else {
		return 1;
	}
}

/* Haetaan pelaajan korteista, onko siellä ässäkorttia, joka on arvoltaan 14, 
   joka pitäisi muuttaa arvoltaan 1:ksi */
Kortti* Pelaaja::haeAssa() {
	for (int i = 0; i < vapaaIndeksi; i++) {
		if (kortit[i]->arvo == 14) {
			return kortit[i];
		}
	}
	return nullptr;
}

/* Tämä metodi on helpottamassa korttipakan reunusten tekemisessä */
void Pelaaja::apuPrintti(string mjono, int a) {
	for (int i = 0; i < a; i++)	{
		cout << mjono;						
	}
	cout << endl;
}

void Pelaaja::tulostaKasi() {
	std::cout <<"	Pelaajan " <<  nimi << " kortit:\n";

	apuPrintti("	\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF  ", vapaaIndeksi);
	for (int i = 0; i < vapaaIndeksi; i++) {
		printf("	\xB3 ");
		printf("% -6s \xB3  ", kortit[i]->maa.c_str());
	}
	cout << endl;
	
	apuPrintti("	\xB3        \xB3", vapaaIndeksi);
	for (int i = 0; i < vapaaIndeksi; i++) {
		printf("	\xB3   ");
		printf("%-2d   \xB3  ", kortit[i]->arvo);
	}
	cout << endl;

	apuPrintti("	\xB3        \xB3  ", vapaaIndeksi);
	for (int i = 0; i < vapaaIndeksi; i++) {
		printf("	\xB3     ");
		printf(" %-2s\xB3 ", kortit[i]->maa.c_str());
	}
	cout << endl;

	apuPrintti("	\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9  ", vapaaIndeksi);

	cout << "	Korttien summa: " << laskeKasi() << "\n\n";
}

int Pelaaja::laskeKasi()
{
	int yht = 0;
	for (int i = 0; i < vapaaIndeksi; i++) {						
		yht +=kortit[i]->arvo;
	}
	
	return yht;
}

void Pelaaja::asetaNimi(string aNimi) {
	nimi = aNimi;
}
string Pelaaja::haeNimi() {
	return nimi;
}
int Pelaaja::haeVapaaIndeksi() {
	return vapaaIndeksi;
}
