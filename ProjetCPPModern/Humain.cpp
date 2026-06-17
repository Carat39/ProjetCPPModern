#include "Humain.h"
#include "Affichage.h"
#include "JeuClem.h"
#include <iostream>
#include <cstdio>

unique_ptr<Carte> Humain::Jouer() {
    int laValeur = Affichage::DemanderValeurCarte();
    string laCouleur = Affichage::DemanderCouleurCarte();
    cout << laCouleur;

    // On boucle TANT QUE la carte n'est pas dans la main OU n'est pas jouable
    while (!jeu->CarteJouable(this, laCouleur, laValeur)) {
        printf("\n[Erreur] Carte invalide ou absente de votre main !\n");
        AfficherMain(cout);
        laValeur = Affichage::DemanderValeurCarte();
        laCouleur = Affichage::DemanderCouleurCarte();
    }

    // La carte est validée, on appelle Renvoyer_carte qui la retire de la main et la retourne
    return Renvoyer_carte(laCouleur, laValeur);
}