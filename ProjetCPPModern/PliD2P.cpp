#include <iostream>
#include <vector>

#include "PliD2P.h"

using namespace std;

PliD2P::PliD2P(Paquet* paquet) {
	lePaquet = paquet;
}

int PliD2P::Calcul_points()
{
	int pts_pli = 0;
	for (const auto& pair : pli) {
		if ((pair.second)->get_couleur() == "♥") {
			pts_pli++;
		}
		else if ((pair.second)->get_couleur() == "♠" && (pair.second)->get_valeur() == 12) {
			pts_pli += 13;
		}
	}
	return pts_pli;
}

bool PliD2P::Coeur_existe()
{
	bool trouve= false;
	for (const auto& pair : pli) {
		if (pair.second->get_couleur() == "♥")
		{
			trouve = true;
		}
	}
	return trouve;
}

int PliD2P::Vainqueur(int premier_j)
{
	int le_gagnant = premier_j;
	string couleur_atout = (pli.find(premier_j))->second->get_couleur();
	int meilleur_carte = (pli.find(premier_j))->second->get_valeur();
	for (const auto& pair : pli)
	{
		if ((pair.second)->get_couleur() == couleur_atout && (pair.second)->get_valeur() > meilleur_carte)
		{
			le_gagnant = pair.first;
			meilleur_carte = (pair.second)->get_valeur();
		}
	}
	cout << le_gagnant;

	for (auto& pair : pli) {
		lePaquet->Move_carte(move(pair.second));
	}
	pli.clear();

	return le_gagnant;
}
