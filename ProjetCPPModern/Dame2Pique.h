#ifndef DAME2_PIQUE_H
#define DAME2_PIQUE_H

#include <iostream>
#include <vector>
#include "Joueur.h"
using namespace std;

class Dame2Pique
{
private:
	vector<Joueur> joueurs;

	vector<int> points_temp;

	bool coeur_bloque;

	int nb_pli;

	bool dongauche;


public:
	void Partie(int nb_humains, int nb_ia);

	int Verifier_points();

	int Commencer_tour();

	int Grand_chelem();

	void Attribuer_points();

};
#endif
