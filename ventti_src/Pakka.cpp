#include "Pakka.h"
#include <iostream>
#include "common_defs.h"

using namespace std;

Pakka::Pakka() {
	seuraavaKortti = 0; //aluksi seuraavaKortti on 0, eli pinon p‰‰llimm‰inen. Kun kortteja nostetaan, seuraavaKortti:a kasvatetaan, eli se kertoo aina seuraavan ei-nostetun kortin indeksin pakassa
	alusta();
	sekoita();
}

void Pakka::alusta() {
	int p = 0;

	for (int maa = 1; maa <= MAIDEN_MAARA; maa++) {

     	for (int l = 1; l <= KORTIN_NUMEROT; l++) {				
				pakka[p].arvo = l;
				pakka[p].maa = MAIDEN_NIMET[maa];
				p++;
			}
		}
}

void Pakka::sekoita() {
	
	for (int i = 0; i < KORTTIPAKKA; i++) {
		int r = i + (rand() % (KORTTIPAKKA - i));

		swap(pakka[i].arvo, pakka[r].arvo);
		swap(pakka[i].maa, pakka[r].maa);
		
	}
}

Kortti* Pakka::nostaKortti() {
	Kortti* palautettavaKortti = &pakka[seuraavaKortti];
	palautettavaKortti->nostettu = true;
	seuraavaKortti++;
	return palautettavaKortti;
}

void Pakka::tulostaPakka() {

	for (int i = 0; i < KORTTIPAKKA; i++)
	{
		if (pakka[i].nostettu == false) {
			cout << pakka[i].maa << pakka[i].arvo << endl;
		}
	}
}

