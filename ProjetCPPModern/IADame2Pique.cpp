#include "IADame2Pique.h"
#include "Affichage.h"
#include "JeuClem.h"
#include <cstdlib>

unique_ptr<Carte> IADame2Pique::Jouer() {
	// Note : Retirez srand(time(NULL)) d'ici, mettez-le une seule fois dans le main() général.

	string choixCouleur = "";
	int choixValeur = -1;

	// --- Étape 2 : Chercher une carte jouable sans risque ---
	int meilleureValeur = -1;
	string meilleureCouleur = "";

	for (auto& paire : mainJ) {
		if (paire.second) { // Vérification que le pointeur n'est pas nul
			string coul = paire.second->get_couleur();
			int val = paire.second->get_valeur();
			bool estDame2Pique = (coul == "♠" && val == 12);
			bool estCoeur = (coul == "♥");

			if (!estCoeur && !estDame2Pique && jeu->CarteJouable(this, coul, val)) {
				if (val > meilleureValeur) {
					meilleureValeur = val;
					meilleureCouleur = coul;
				}
			}
		}
	}

	if (meilleureValeur != -1) {
		choixCouleur = meilleureCouleur;
		choixValeur = meilleureValeur;
	}
	else {
		// --- Étape 3 : Aucune carte sûre, chercher une carte jouable hors dame de pique ---
		int plusFaibleValeur = 100;
		string plusFaibleCouleur = "";

		for (auto& paire : mainJ) {
			if (paire.second) {
				string coul = paire.second->get_couleur();
				int val = paire.second->get_valeur();
				bool estDame2Pique = (coul == "♠" && val == 12);

				if (!estDame2Pique && jeu->CarteJouable(this, coul, val)) {
					if (val < plusFaibleValeur) {
						plusFaibleValeur = val;
						plusFaibleCouleur = coul;
					}
				}
			}
		}

		if (plusFaibleValeur != 100) {
			choixCouleur = plusFaibleCouleur;
			choixValeur = plusFaibleValeur;
		}
		else {
			// --- Étape 4 : Seule la dame de pique est jouable ---
			for (auto& paire : mainJ) {
				if (paire.second) {
					string coul = paire.second->get_couleur();
					int val = paire.second->get_valeur();
					if (jeu->CarteJouable(this, coul, val)) {
						choixCouleur = coul;
						choixValeur = val;
						break;
					}
				}
			}
		}
	}

	return Renvoyer_carte(choixCouleur, choixValeur);
}