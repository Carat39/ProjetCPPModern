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
        ReglesSupplementaires();
        Commencer(); // attribution joueur qui commence peut y avoir
        while (condManche) {
            int indexcarte = -1;
            int newIndexJ = -1;
            for (indexJ = commencer; indexJ < commencer + nbJoueurs + nbIa; indexJ++) {
                newIndexJ = indexJ % lesJoueurs.size();
                indexcarte = -1;
                if (typeid(*lesJoueurs[newIndexJ]) == typeid(Humain)) {
                    AfficherInformations(cout);
                    lesJoueurs[newIndexJ]->AfficherMain(cout);
                    indexcarte = Affichage::DemanderIndex();
                    laValeur = lesJoueurs[newIndexJ]->getValeur(indexcarte);
                    laCouleur = lesJoueurs[newIndexJ]->getCouleur(indexcarte);
                    while (laCouleur == " " && indexcarte != 25) {
                        laValeur = lesJoueurs[newIndexJ]->getValeur(indexcarte);
                        laCouleur = lesJoueurs[newIndexJ]->getCouleur(indexcarte);
                        indexcarte++;
                    }
                    ///Ok par thibault en théorie
                    while (!CarteJouable(lesJoueurs[newIndexJ], laCouleur, laValeur)) {
                        indexcarte = Affichage::DemanderIndex();
                        laValeur = lesJoueurs[newIndexJ]->getValeur(indexcarte);
                        laCouleur = lesJoueurs[newIndexJ]->getCouleur(indexcarte);
                        while (laCouleur == " " && indexcarte != 25) {
                            laValeur = lesJoueurs[newIndexJ]->getValeur(indexcarte);
                            laCouleur = lesJoueurs[newIndexJ]->getCouleur(indexcarte);
                            indexcarte++;
                        }
                    }
                }
                else {
                    //Fonction Thibault...
                    //Truc arbitraire en attendant :
                    laValeur = lesJoueurs[newIndexJ]->getValeur(0);
                    laCouleur = lesJoueurs[newIndexJ]->getCouleur(0);
                }
                JouerCarte(lesJoueurs[newIndexJ], laCouleur, laValeur); //Peut potentiellement y avoir des annonces
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