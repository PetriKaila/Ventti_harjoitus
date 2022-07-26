#pragma once

#include <string>

using namespace std;
const int NIMITAULU_MAX_PITUUS = 20;
struct Nimitiedot {
	string nimi;
	int laskuri;

};
class Lista
{
public:
	Lista();
	int enitenVoittoja();
	int haeNimi(string haettava);
	int tyhjennaLista();
	
private:	
	struct Nimitiedot nimet[NIMITAULU_MAX_PITUUS];
};

