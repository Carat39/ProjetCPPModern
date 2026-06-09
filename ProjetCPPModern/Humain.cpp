#include <iostream>
#include <vector>

#include "Humain.h"
#include "Affichage.h"
#include <memory>
#include <string>
#include "Carte.h"


unique_ptr<Carte>& Humain::Jouer() {
	string laCouleur = Affichage::DemanderCouleurCarte();
	int laValeur = Affichage::DemanderValeurCarte();

	while (!jeu->CarteJouable(this, laCouleur, laValeur)) {
		laCouleur = Affichage::DemanderCouleurCarte();
		laValeur = Affichage::DemanderValeurCarte();
	}
	return Renvoyer_carte(laCouleur, laValeur);
}