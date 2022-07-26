#include "Kortti.h"
#include "common_defs.h"
#include "Pakka.h"
#include "Peli.h"

Kortti::Kortti() {
	arvo = 0;
	maa = "";
	nostettu = false;
	
}
void Kortti::muutaAssa(int aArvo)
{
	arvo = aArvo;
}
