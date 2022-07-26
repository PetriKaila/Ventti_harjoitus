#pragma once
#include <iostream>
#include <string>
#include "Pakka.h"
#include "Valikko.h"
#include "Pelaaja.h"
#include "Jakaja.h"
#include <iostream>
#include <conio.h>

using namespace std;
class Peli
{
public:
    void uusiPeli(string aNimi);
	string tulostaVoittaja();
	int tallennaTiedostoon(string voittaja = "");
	
private:
	Pakka pakka;
	Pelaaja pelaaja;
    Jakaja jakaja;

};

