#pragma once

#include "common_defs.h"
#include "valikko.h"
using namespace std;


class Valikko
{
public:
	Valikko() {
		nimi = "";
	}
	int Menu();
private:
	string nimi;

}; 