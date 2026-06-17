#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Humain.h"
#include "Affichage.h"
#include <memory>
#include <string>
#include "Carte.h"
#include "JeuClem.h"
#include <cstdio>


unique_ptr<Carte>& Humain::Jouer() {
    int laValeur = Affichage::DemanderValeurCarte();      
    string laCouleur = Affichage::DemanderCouleurCarte(); 

    while (!jeu->CarteJouable(this, laCouleur, laValeur)) {
        printf("Carte fausse");
        AfficherMain(cout);
        laValeur = Affichage::DemanderValeurCarte();
        laCouleur = Affichage::DemanderCouleurCarte();
    }
    return Renvoyer_carte(laCouleur, laValeur);
}