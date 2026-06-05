#include "JeuClem.h"

JeuClem::~JeuClem() {
    for (Joueur*& joueur : lesJoueurs) {
        delete joueur;
    }
}

void JeuClem::Partie() {
    int nbJoueurs = -1;
    int nbIa = -1;
    string couleur = "";
    int valeur = 0;
    int indexJ;

    PreparationPaquet(); //Créer Paquet
    DefinirNbJoueurMinMax(); //Attributs minjoueurs et maxjoueurs
    while(nbJoueurs + nbIa < nbJoueursMinMax[0] || nbJoueursMinMax[1] < nbJoueurs + nbIa) {
        cout << "Nombres Joueurs Min: " << nbJoueursMinMax[0] << " Nombres Joueurs Max: " << nbJoueursMinMax[1] << endl;
        nbJoueurs = Affichage::DemanderNbJoueurs("e Joueurs");
        nbIa = Affichage::DemanderNbJoueurs("'IA");
    }
    PreparationJoueur(nbJoueurs,nbIa); //Créer Joueurs et IA
    PreparationPli(); //Créer Pli
    while(!condPartie) {
        Distribution(); // Distribuer carte
        Commencer(); // attribution joueur qui commence peut y avoir une annonce ici comme pour le tarot
        for (indexJ = 0; indexJ < nbJoueurs + nbIa; indexJ++) {
            couleur = "-1";
            while (lesJoueurs[indexJ]->Trouver_carte(couleur, valeur) == false) {
                couleur = Affichage::DemanderCouleurCarte();
                valeur = Affichage::DemanderValeurCarte();
            }
            JouerCarte(lesJoueurs[indexJ],couleur, valeur); //Peut potentiellement y avoir des annonces
            ConfirmerJoueurSuivant(); //On clear la console et demande au joueur suivant s'il est prêt
                                      //On affichera les cartes du joueur suivant ainsi que le pli actuel à ce moment là
            }
        VerifierPli(); //Met a jour le vainqueur et les points temporaire
        AttribuerPoints(); //Attribut les points
        VerifierCondPartie(); //Change ou non condPartie
    }
    FinDePartie(); //Lance la fin de la partie
}