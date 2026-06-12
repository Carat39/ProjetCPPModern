#include <iostream>
#include <vector>

#include "IADame2Pique.h"
#include <string>
#include "Affichage.h"
#include <cstdlib>
#include <ctime>
#include <memory>
#include "JeuClem.h"


unique_ptr<Carte>& IADame2Pique::Jouer() {
	srand((unsigned int)time(NULL));
	int r = rand() % (int)(mainJ.size());
	string laCouleur = mainJ[r]->get_couleur()   ;
	int laValeur = mainJ[r]->get_valeur();
	while (!jeu->CarteJouable(this, laCouleur, laValeur)) {
		r = rand() % (int)mainJ.size();
		laCouleur = mainJ[r]->get_couleur();
		laValeur = mainJ[r]->get_valeur();
	}
	return Renvoyer_carte(laCouleur, laValeur);

}