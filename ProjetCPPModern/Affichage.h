#ifndef AFFICHAGE_H
#define AFFICHAGE_H 500

#include <iostream>
#include <string>
#include "Joueur.h"
using namespace std;

class Affichage{
	public:
		static int DemanderValeurCarte();

		static string DemanderCouleurCarte();

		template<typename ListJoueur = vector<Joueur>>
		static void Afficher_jeu(ListJoueur vectJ);

};
 
template<typename ListJoueur> void Affichage::Afficher_jeu(ListJoueur vectJ) {
	if (typeid(vectJ) == typeid(vector<Joueur>)) {
		cout << "m";
	}
	/*for (Joueur& joueur : vectJ) {
		joueur.AfficherMain(cout);
	}*/

}

#endif
