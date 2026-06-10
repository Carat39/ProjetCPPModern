#include <iostream>
#include <vector>

#include "Humain.h"
#include "Affichage.h"


template <typename PJeu>
unique_ptr<Carte> Humain::Jouer(PJeu& jeu) {
	string laCouleur = Affichage::DemanderCouleurCarte();
	int laValeur = Affichage::DemanderValeurCarte();

	while (!jeu.CarteJouable(this, laCouleur, laValeur)) {
		laCouleur = Affichage::DemanderCouleurCarte();
		laValeur = Affichage::DemanderValeurCarte();
	}
	return Renvoyer_carte(laCouleur, laValeur);

}