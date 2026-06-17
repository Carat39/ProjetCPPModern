#include "Humain.h"
#include "Affichage.h"
#include "JeuClem.h"
#include <iostream>
#include <cstdio>

unique_ptr<Carte> Humain::Jouer() {
    int indexcarte = 0;
    jeu->AfficherInformations(cout);
    AfficherMain(cout, indexcarte);
    indexcarte = Affichage::DemanderIndex(this, jeu->GetCouleurPli());
    int laValeur = getValeur(indexcarte);
    string laCouleur = getCouleur(indexcarte);
    while (laCouleur == " " && indexcarte != 25) {
        AfficherMain(cout, indexcarte);
        laValeur = getValeur(indexcarte);
        laCouleur = getCouleur(indexcarte);
        indexcarte++;
    }
    ///Ok par thibault en théorie
    while (!jeu->CarteJouable(this, laCouleur, laValeur)) {
        indexcarte = Affichage::DemanderIndex(this, jeu->GetCouleurPli());
        laValeur = getValeur(indexcarte);
        laCouleur = getCouleur(indexcarte);
        while (laCouleur == " " && indexcarte != 25) {
            laValeur = getValeur(indexcarte);
            laCouleur = getCouleur(indexcarte);
            indexcarte++;
        }
    }


    // La carte est validée, on appelle Renvoyer_carte qui la retire de la main et la retourne
    return Renvoyer_carte(laCouleur, laValeur);
}