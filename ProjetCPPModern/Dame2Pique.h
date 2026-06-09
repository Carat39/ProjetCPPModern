#ifndef DAME2_PIQUE_H
#define DAME2_PIQUE_H

#include <iostream>
#include <vector>
#include "Jeu.h"
#include "PaquetD2P.h"
#include "PliD2P.h"

using namespace std;

class Dame2Pique:public Jeu{
	private:
		std::vector<Joueur> joueurs;

		std::vector<int> points_temp;

		PliD2P lePli;

		PaquetD2P lePaquet;

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
