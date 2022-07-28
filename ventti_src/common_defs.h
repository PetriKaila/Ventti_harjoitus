#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>
extern bool tutorial;


const std::string MAIDEN_NIMET[] = { "maarittelematon", "\x03", "\x04", "\x06", "\x05" };
const int KORTTIPAKKA = 52;
const int MAIDEN_MAARA = 4;
const int KORTIN_NUMEROT = 13;
/*Apuprintit enterin painallukselle johon voi halutessaan lisätä tekstiä ja toinen tutoriaalin printtaukseen, johon voi myös halutessaan lisätä enterin painalluksen.*/
inline void printtaaJaOdota(std::string printti = "", bool odota = true) {
	std::cout << printti << std::endl;
	if (odota) {
		std::cout << "	Paina ENTER jatkaaksesi.." << std::endl;
		char ignore = _getch();
	}
}
inline void printtaaTutoriaali(std::string printti, bool odota = false) {
	if (tutorial) {
		printtaaJaOdota("  * " + printti, odota);
	}
}


