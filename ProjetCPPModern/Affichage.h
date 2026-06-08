#ifndef AFFICHAGE_H
#define AFFICHAGE_H 500

#include <iostream>
#include <string>
#include <memory>

#include "Joueur.h"
using namespace std;

class Affichage{
	public:
		static int DemanderValeurCarte();

		static string DemanderCouleurCarte();

		static int DemanderNbJoueurs(string Precision);

		static void Afficher_jeu(vector<Joueur>& vectJ);

};


#endif
