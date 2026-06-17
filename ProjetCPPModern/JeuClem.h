#ifndef JEUCLEM_H
#define JEUCLEM_H 1000
#include "Paquet.h"
#include "Pli.h"
#include "Affichage.h"
#include <memory>
#include "Joueur.h"
#include "Humain.h"

class JeuClem{
	protected:
		//Attributs
        int nbJoueursMinMax[2];
        vector<Joueur*> lesJoueurs;
        Paquet* lePaquet;
        Pli* lePli;
        bool condManche;
        bool condPartie;
        int commencer;
        string couleurPli;

	public:
        //Pas de constructeurs
        ~JeuClem();

        //La méthode qui contient le squelette de la partie qu'on ne peut modifier
        virtual void Partie() final;

        virtual void DefinirNbJoueurMinMax() = 0;

        virtual void PreparationJoueur(int nbJoueur, int nbIa) = 0;

        virtual void PreparationPaquet() = 0;

        virtual void PreparationPli() = 0;

        virtual void Distribution() = 0;

        virtual void Commencer() = 0;

        virtual void ReglesSupplementaires() = 0;

        virtual void AfficherInformations(ostream& os) = 0;

        virtual void VerifierCondManche() = 0;

        virtual bool CarteJouable(Joueur* joueur,string laCouleur, int laValeur) = 0;

        virtual void JouerCarte(Joueur* joueur,string laCouleur, int laValeur) = 0;

        virtual void ConfirmerJoueurSuivant() = 0;

        virtual void VerifierPli() = 0;

        virtual void AttribuerPoints() = 0;

        virtual void VerifierCondPartie() = 0;

        virtual void FinDePartie() = 0;
};

#endif
