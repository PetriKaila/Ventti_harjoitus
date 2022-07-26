#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "common_defs.h"
#include <string>
#include "Valikko.h"
#include "Peli.h"
#include "Lista.h"
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <ctime>
#include <algorithm>
//#include <chrono>

bool tutorial = false;
using namespace std;

/* Valikossa kehykset tehty heksadesimaaleilla*/
int Valikko::Menu() {
	char valikko;
		while (true) {
		system("CLS");
		cout << R"( 
 __      ________ _   _ _______ _______ _____ 
 \ \    / /  ____| \ | |__   __|__   __|_   _|
  \ \  / /| |__  |  \| |  | |     | |    | |  
   \ \/ / |  __| | . ` |  | |     | |    | |  
    \  /  | |____| |\  |  | |     | |   _| |_ 
     \/   |______|_| \_|  |_|     |_|  |_____|
)" << '\n';

		std::time_t result = std::time(nullptr);
		cout << "          " << std::ctime(&result);
		cout << "	 \xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n";
		cout << "	 \xB3   0. Tutustu peliin   \xB3\n";
		cout << "	 \xB3   1. Aloita Peli      \xB3\n";
		cout << "	 \xB3   2. Vaihda pelaajaa  \xB3\n";
		cout << "	 \xB3   3. Toplista         \xB3\n";
		cout << "	 \xB3   4. Nollaa Toplista  \xB3\n";
		cout << "	 \xB3   5. Lopeta Peli      \xB3\n";
	    cout << "	 \xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n\n";
		if (nimi != "") {
			cout << "	  PELAAJA: " << nimi << endl;
		}
		valikko = _getch();
		system("CLS");
		if (valikko == '0') {
			tutorial = true;
	        Peli peli;
			peli.uusiPeli("Tutoriaali");

		}
		else if (valikko == '1') {
			tutorial = false;
			if (nimi == "") {
				cout << "	Hei, anna nimesi: ";
				this_thread::sleep_for(chrono::milliseconds(1500));
				getline(cin, nimi);
				replace(nimi.begin(), nimi.end(), ' ', '_');
		}		
			while (true) {
				Peli* peli = new Peli();
				peli->uusiPeli(nimi);
				delete peli;
				cout << "Haluatko pelata uudelleen? (K/e)" << endl;
				char uusiPeli = 0;
				fflush(stdin);
				uusiPeli = _getch();
				if (uusiPeli != 'K' && uusiPeli != 'k') {
					break;
				}
			}
		}
		else if (valikko == '2') {
			cout << "	 Anna uuden pelaajan nimi: ";			
			getline(cin, nimi);
			replace(nimi.begin(), nimi.end(), ' ', '_');
			cout << "Hei, tervetuloa pelaamaan " << nimi;

		}
		else if (valikko == '3') {
			Lista voittajaLista;
			voittajaLista.enitenVoittoja();
		}
		else if (valikko == '4') {
			Lista tyhjenna;
			tyhjenna.tyhjennaLista();
		}
		else if (valikko == '5') {
			cout << "	Kiitos, ja n\x84kemiin. :-)\n\n\n";

			exit(0);
		}
		else {
			cout << "	Virheellinen valinta!" << endl;
		}
	}
}


	