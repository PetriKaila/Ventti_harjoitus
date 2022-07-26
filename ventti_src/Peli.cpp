#define _CRT_SECURE_NO_WARNINGS //koska VS:n k‰‰nt‰j‰ valittaa muuten ett‰ ctime depracated
#include <string>
#include "Peli.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <chrono>
#include <thread>
#include "Lista.h"
#include <conio.h>
#include "common_defs.h"
using namespace std;

void Peli::uusiPeli(string aNimi) {
		//pakka.tulostaPakka(); //vain debuggaukseen
		pelaaja.asetaNimi(aNimi);
		pelaaja.tallennaKortti(pakka.nostaKortti());
		jakaja.tallennaKortti(pakka.nostaKortti());

		system("CLS");
		printtaaTutoriaali("Ventiss\x84 tavoittelet ventti\x84, eli korttien arvojen summaa 21.");
		cout << "	*** Jaetaan ensimm\x84iset kortit... ***" << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));
		jakaja.tulostaKasi();
		printtaaTutoriaali("Jakajan kortit n\x84kyv\x84t aluksi nurinp\x84in.");

		pelaaja.tulostaKasi();
		printtaaTutoriaali("Peli laskee puolestasi k\x84tesi kortit, jotta sinun ei tarvitse vaivata p\x84\x84t\x84si.");

		bool jakajaValmis = false;
		bool pelaajaValmis = false;	
		
		while (!jakajaValmis || !pelaajaValmis) {
			string nostaUusi = " ";
			if (pelaajaValmis == false)	{

				printtaaTutoriaali("Painamalla 'K' nostat uuden kortin. 'E' lopettaa pelin sinun osaltasi.");
				cout << "	Haluatko nostaa kortin? paina (K/e) ja Enter. " <<endl;
				
				getline(cin, nostaUusi);
				system("CLS");

				if (nostaUusi == "K" || nostaUusi == "k") {
					pelaaja.tallennaKortti(pakka.nostaKortti());
					jakaja.tulostaKasi();
					pelaaja.tulostaKasi();
					if (pelaaja.laskeKasi() > 21) {
						printtaaJaOdota("	Peli p\x84\x84ttyy, koska korttiesi summa on yli 21");
						tallennaTiedostoon(jakaja.haeNimi()); // Jakaja voitti
						return;
					}
					this_thread::sleep_for(chrono::milliseconds(1500));

					//printtaaJaOdota();
					system("CLS");
				}
				else if (nostaUusi == "E" || nostaUusi == "e") {
					pelaajaValmis = true;
				}
				else { 
					cout << "	Virheellinen valinta!" << endl;
					pelaaja.tulostaKasi();
					continue;	
				}
			}
			printtaaTutoriaali("Jakaja nostaa uuden kortin niin kauan kuin se on tarpeellista, yritt\x84\x84kseen voittaa.");
			if (jakaja.laskeKasi() <= 17) {
				
				cout << "	** Jakaja nosti kortin! **" << endl;
				this_thread::sleep_for(chrono::milliseconds(1200));
				jakaja.tallennaKortti(pakka.nostaKortti());
			}

			else {
				jakajaValmis = true;
			}
			if (!pelaajaValmis) {
				jakaja.tulostaKasi();
				pelaaja.tulostaKasi();
			}
		}
		system("CLS");
		cout << "	*** Katsotaan kortit ***\n\n";
		jakaja.Pelaaja::tulostaKasi();
		pelaaja.tulostaKasi();
	    tallennaTiedostoon();
		printtaaTutoriaali("Peli p\x84\x84ttyi, palataan valikkoon.", true);
}
	
string Peli::tulostaVoittaja() {
	string voittaja = "";
	if (pelaaja.laskeKasi() > 21) {
		cout << "	K\x84tesi on yli 21. H\x84visit!\n\n";
		voittaja = jakaja.haeNimi();
	}
	else if (pelaaja.laskeKasi() == 21) {
		cout << "	Ventti, olet voittaja!\n\n";
		voittaja = pelaaja.haeNimi();
	}
	else if (jakaja.laskeKasi() > 21) {
		cout << "	Jakajan k\x84si on yli 21, sin\x84 voitit!\n\n";
		voittaja = pelaaja.haeNimi();
	}
	else if (jakaja.laskeKasi() == 21) {
		cout << "	Jakaja sai Ventin, h\x84visit!\n\n";
		voittaja = jakaja.haeNimi();
	}
	else if (pelaaja.laskeKasi() > jakaja.laskeKasi()) {
		cout << "	Sinulla on suurempi k\x84si kuin jakajalla, sin\x84 voitit!\n\n";
		voittaja = pelaaja.haeNimi();
	}
	else if (pelaaja.laskeKasi() == jakaja.laskeKasi()) {
		cout << "	Tasapeli!\n\n";
		voittaja = "**Tasapeli**";
	}
	else {
		cout << "	Jakajan k\x84si on suurempi, jakaja voitti!\n\n"; 
		voittaja = jakaja.haeNimi();

	}
	return voittaja;
} 

/* T‰m‰ metodi tallentaa alekkain kunkin pelin voittajan tiedostoon toplista.txt,
   joka lˆytyy kyseisen reposition hakemistosta. Jos tiedostoa ei ole, sellainen luodaan.
   Tiedostossa on myˆs p‰iv‰m‰‰r‰t mahdollista myˆhemp‰‰ tarvetta varten.*/
int Peli::tallennaTiedostoon(string voittaja) {
	if (voittaja == ""){
		voittaja = tulostaVoittaja();
	}
	std::time_t result = std::time(nullptr);
	ofstream lista;
	lista.open("toplista.txt", fstream::in | fstream::out | fstream::app);
	if (!lista) { 
		cout << "	Error: tiedostoa ei voitu avata." << endl;
		exit(1);
	}	
	lista << (std::ctime(&result)) << " " << voittaja << endl;
	lista.close();
	return 0;
}
