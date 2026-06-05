#include <iostream>
#include <vector>

#include "Pli.h"


void Pli::setCarte(int joueur, Carte carte){
	pli.insert(std::pair<int, Carte>(joueur, carte));
}