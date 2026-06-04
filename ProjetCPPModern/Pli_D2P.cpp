#include <iostream>
#include <vector>

#include "Pli_D2P.h"

using namespace std;

template<typename TPaquet>
int Pli_D2P::Vainqueur(int premier_j, TPaquet le_paquet)
{
	int le_gagnant=premier_j;
	string couleur_atout= (pli.find(premier_j))->second.get_couleur();
	int meilleur_carte= (pli.find(premier_j))->second.get_valeur();
	for (const auto &pair : pli)
	{
		if ((pair.second).get_couleur() == couleur_atout && (pair.second).get_valeur() > meilleur_carte)
		{
			le_gagnant = pair.first;
			meilleur_carte = (pair.second).get_valeur();
		}
	}
	cout << le_gagnant;

	for (const auto& pair : pli) {
		le_paquet.Ajouter_carte(pair.second);
		pair.second= NULL;
	}

	return le_gagnant;
}

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
