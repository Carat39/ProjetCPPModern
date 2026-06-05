#ifndef AFFICHAGE_H
#define AFFICHAGE_H 500

#include <iostream>
#include <string>
#include "Joueur.h"
using namespace std;

	public:
		static int DemanderValeurCarte();

		static string DemanderCouleurCarte();

		static void Afficher_jeu(vector<Joueur> vectJ);

};


#endif
