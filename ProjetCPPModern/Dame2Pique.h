#ifndef DAME2_PIQUE_H
#define DAME2_PIQUE_H

#include <string>
#include <vector>
#include "Jeu.h"
#include "PaquetD2P.h"
#include "Pli_D2P.h"
using namespace std;
#include <list>
#include <iostream>
#include <assert.h>
#include "Joueur.h"



class Dame2Pique
{
	private:
		std::vector<Joueur> joueurs;

		std::vector<int> points_temp;

		Pli_D2P lePli;

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
