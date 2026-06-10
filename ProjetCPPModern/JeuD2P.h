#ifndef JEUD2P_H
#define JEUD2P_H 1050

#include <iostream>
#include <vector>
#include "Jeu.h"
#include "PaquetD2P.h"
#include "PliD2P.h"
#include "JeuClem.h"
#include "Humain.h"

using namespace std;

class JeuD2P :public JeuClem {
	private:
		std::vector<int> points_temp;

		bool coeur_bloque;

		int nb_pli;

		bool dongauche;


	public:
        JeuD2P();

        virtual void DefinirNbJoueurMinMax();

        virtual void PreparationJoueur(int nbJoueur, int nbIa);

        virtual void PreparationPaquet();

        virtual void PreparationPli();

        virtual void Distribution();

        virtual void Commencer();

        virtual void VerifierCondManche();

        virtual bool CarteJouable(Joueur* joueur,string laCouleur, int laValeur);

        virtual void JouerCarte(Joueur* joueur, string laCouleur, int laValeur);

        virtual void ConfirmerJoueurSuivant();

        virtual void VerifierPli();

        virtual void AttribuerPoints();

        virtual void VerifierCondPartie();

        virtual void FinDePartie();

        int GrandChelem();

};
#endif
