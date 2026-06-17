#include "JeuClem.h"

JeuClem::~JeuClem() {
    for (Joueur*& joueur : lesJoueurs) {
        delete joueur;
    }
}

void JeuClem::Partie() {
    int nbJoueurs = -1;
    int nbIa = -1;
    string laCouleur = "";
    int laValeur = 0;
    int indexJ;

    DefinirNbJoueurMinMax(); //Attributs minjoueurs et maxjoueurs
    while (nbJoueurs + nbIa < nbJoueursMinMax[0] || nbJoueursMinMax[1] < nbJoueurs + nbIa) {
        cout << "Nombres Joueurs Min: " << nbJoueursMinMax[0] << " Nombres Joueurs Max: " << nbJoueursMinMax[1] << endl;
        nbJoueurs = Affichage::Demander("Combien y'a t-il de Joueurs: ");
        nbIa = Affichage::Demander("Combien y'a t-il d'IA: ");
    }
    PreparationJoueur(nbJoueurs, nbIa); //Créer Joueurs et IA
    PreparationPaquet(); //Créer Paquet
    PreparationPli(); //Créer Pli

    while (condPartie) {
        condManche = true;
        Distribution(); // Distribuer carte
        Commencer(); // attribution joueur qui commence peut y avoir une annonce ici comme pour le tarot

        while (condManche) {
            int indexcarte = -1;
            int newIndexJ = -1;
            for (indexJ = commencer; indexJ < commencer + nbJoueurs + nbIa; indexJ++) {
                Joueur* joueurActuel = lesJoueurs[indexJ % lesJoueurs.size()];
                joueurActuel->AfficherMain(cout);

                // 1. Le joueur choisit et extrait sa carte de sa main
                unique_ptr<Carte> carteChoisie = move(joueurActuel->Jouer());

                // 2. On transmet directement cette carte récupérée à la méthode JouerCarte
                JouerCarte(joueurActuel, std::move(carteChoisie));
                ConfirmerJoueurSuivant(); //Peut potentiellement y avoir des annonces
                ConfirmerJoueurSuivant(); //On clear la console et demande au joueur suivant s'il est prêt
                //On affichera les cartes du joueur suivant ainsi que le pli actuel à ce moment là
            }
            VerifierPli(); //Met a jour le vainqueur et les points temporaire
            VerifierCondManche();
        }
        AttribuerPoints(); //Attribuer les points
        VerifierCondPartie(); //Change ou non condPartie
    }
    FinDePartie(); //Lance la fin de la partie
}