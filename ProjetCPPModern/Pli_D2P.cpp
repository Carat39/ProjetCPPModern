#include <iostream>
#include <vector>

#include "Pli_D2P.h"

using namespace std;


int Pli_D2P::Calcul_points()
{
	
	return 0;
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
