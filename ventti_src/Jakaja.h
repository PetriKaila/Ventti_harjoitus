#pragma once
#include "Pelaaja.h"
class Jakaja :
    public Pelaaja    //T‰ss‰ luokassa perit‰‰n luokka pelaaja, koska jakajalla on hyvin pitk‰lti samat toiminnot kuin pelaajalla.
{
public:
    Jakaja() {
        asetaNimi("Jakaja");
    }
    void tulostaKasi();
  
private:
   
};