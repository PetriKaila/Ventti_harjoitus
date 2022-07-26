#include "Lista.h"
#include "common_defs.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

Lista::Lista()
{
    for (int i = 0; i < NIMITAULU_MAX_PITUUS; i++) {
        nimet[i].nimi = "";
        nimet[i].laskuri = 0;
       
    }
}
/*Vertailu funktio qsortille.*/
int vertaa(const void* a, const void* b)
{

    Nimitiedot* A = (Nimitiedot*)a;
    Nimitiedot* B = (Nimitiedot*)b;

    return (B->laskuri - A->laskuri);
}

/* enitenVoittoja metodi lukee voittajat tiedostosta, kerää ne taulukkoon, 
   järjestää taulukon sen mukaan kenen nimi on taulukossa useimmin. Ja lopuksi tulostaa taulukon*/
int Lista::enitenVoittoja()
{
    string discard;
    string sana;
    int indeksi = 0;
    int i;
    string rivi;
    ifstream lista;
    lista.open("toplista.txt");
    while (lista >> discard >> discard >> discard >> discard >> discard) {

      
        lista >> sana;
        int loydetty = haeNimi(sana);
        if (loydetty == -1) {
            //cout << "loytyi uusi" << sana << endl;
            nimet[indeksi].nimi = sana;
            nimet[indeksi].laskuri++;
            indeksi++;
        }
        else {
            //cout << "loytyi ennestään" << sana << endl;
            nimet[loydetty].laskuri++;
        }
#include <conio.h>
    
   }
    cout << "              *** PISTEET *** \n\n";
    qsort(nimet, sizeof nimet / sizeof * nimet, sizeof * nimet, vertaa);
    for (i = 0; i < indeksi; i++) {

        printf("%4s %-20s \t  %d\n","", nimet[i].nimi.c_str(), nimet[i].laskuri);
        replace(nimet[i].nimi.begin(), nimet[i].nimi.end(), '\n', ' '); 

    }
    printtaaJaOdota();
    lista.close();
    cout << endl;
    return 0; 
}
/* haeNimi etsii löytyykö kyseinen nimi jo taulukosta.
   Mikäli nimi löytyy, funktio palauttaa löydetyn indeksin,
   ja jos ei löydy palauttaa -1*/
int Lista::haeNimi(string haettava)
{
    for (int i = 0; i < NIMITAULU_MAX_PITUUS; i++) {
        if (nimet[i].nimi == haettava)
            return i;
    }   
    return -1; 
}
/* Poistaa tiedoston kokonaan, eli ei pelkästään tyhjennä.*/
int Lista::tyhjennaLista()  
{
    char varmistus = 0;
    cout << "Haluatko varmasti tyhjentaa listan ? (K / e)";
    varmistus = _getch();
    if (varmistus == 'K' || varmistus == 'k') {
        {
            if (remove("toplista.txt") != 0)
                cout << "Virhe poistaessa listaa!" << endl;
            else
                cout << "Toplista nollattu!" << endl;
        }
    }
    else {
        cout << "Listaa ei nollattu.\n" << endl;
        return 0;
    }
    return 0;
}
    




