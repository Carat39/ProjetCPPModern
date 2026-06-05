#include <iostream>
#include <vector>

#include "Pli_D2P.h"

using namespace std;


int Pli_D2P::Calcul_points()
{
	int pts_pli = 0;
	for (const auto& pair : pli) {
		if ((pair.second).get_couleur() == "♥") {
			pts_pli++;
		}
		else if ((pair.second).get_couleur() == "♠" && (pair.second).get_valeur() == 12) {
			pts_pli += 13;
		}
	}
	return pts_pli;
}

bool Pli_D2P::Coeur_existe()
{
	bool trouve= false;
	for (const auto& pair : pli) {
		if (pair.second.get_couleur() == "♥")
		{
			trouve = true;
		}
	}
	return trouve;
}
