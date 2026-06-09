#include <iostream>
#include <vector>

#include "Pli.h"


void Pli::setCarte(int joueur, std::unique_ptr<Carte> carte){
	pli.insert(std::make_pair(joueur, std::move(carte)));
}