#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "IADame2Pique.h"
#include <string>
#include "Affichage.h"
#include <cstdlib>
#include <ctime>
#include <memory>
#include "JeuClem.h"


unique_ptr<Carte>& IADame2Pique::Jouer() {
	srand(time(NULL));

	// --- Étape 1 : Collecter toutes les cartes jouables ---
	string choixCouleur = "";
	int choixValeur = -1;

	// Couleurs à risque (cœur = points, dame de pique = 13 points)
	// Priorité : se débarrasser des cœurs, puis des piques hauts, éviter la dame de pique

	// --- Étape 2 : Chercher une carte jouable sans risque (pas cœur, pas dame de pique) ---
	// On cherche d'abord la carte jouable la plus haute hors cœur et hors dame de pique
	int meilleureValeur = -1;
	string meilleureCouleur = "";

	for (int i = 0; i < (int)mainJ.size(); i++) {
		string coul = mainJ[i]->get_couleur();
		int val = mainJ[i]->get_valeur();
		bool estDame2Pique = (coul == "♠" && val == 12);
		bool estCoeur = (coul == "♥");

		if (!estCoeur && !estDame2Pique && jeu->CarteJouable(this, coul, val)) {
			if (val > meilleureValeur) {
				meilleureValeur = val;
				meilleureCouleur = coul;
			}
		}
	}
	
	if (meilleureValeur != -1) {
		// On a trouvé une carte sûre : on la joue
		choixCouleur = meilleureCouleur;
		choixValeur = meilleureValeur;
	}
	else {
		// --- Étape 3 : Aucune carte sûre, chercher une carte jouable hors dame de pique ---
		// On préfère sacrifier un cœur faible plutôt que la dame de pique
		int plusFaibleValeur = 100;
		string plusFaibleCouleur = "";

		for (int i = 0; i < (int)mainJ.size(); i++) {
			string coul = mainJ[i]->get_couleur();
			int val = mainJ[i]->get_valeur();
			bool estDame2Pique = (coul == "♠" && val == 12);

			if (!estDame2Pique && jeu->CarteJouable(this, coul, val)) {
				if (val < plusFaibleValeur) {
					plusFaibleValeur = val;
					plusFaibleCouleur = coul;
				}
			}
		}

		if (plusFaibleValeur != 100) {
			// On joue la carte la plus faible disponible 
			choixCouleur = plusFaibleCouleur;
			choixValeur = plusFaibleValeur;
		}
		else {
			// --- Étape 4 : Seule la dame de pique est jouable, on n'a pas le choix ---
			for (int i = 0; i < (int)mainJ.size(); i++) {
				string coul = mainJ[i]->get_couleur();
				int val = mainJ[i]->get_valeur();
				if (jeu->CarteJouable(this, coul, val)) {
					choixCouleur = coul;
					choixValeur = val;
					break;
				}
			}
		}
	}

	return Renvoyer_carte(choixCouleur, choixValeur);
}