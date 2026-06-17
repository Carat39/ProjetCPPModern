#ifndef JEUD2P_H
#define JEUD2P_H 1050

#include <iostream>
#include <string>
#include <vector>
#include "JeuClem.h"
#include "PaquetD2P.h"
#include "PliD2P.h"
#include "Humain.h"
#include "IADame2Pique.h"

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

        virtual void ReglesSupplementaires();

        virtual void AfficherInformations(ostream& os);

        virtual void VerifierCondManche();

        virtual bool CarteJouable(Joueur* joueur,string laCouleur, int laValeur);

        virtual void JouerCarte(Joueur* joueur, unique_ptr<Carte> laCarte) override;

        virtual void ConfirmerJoueurSuivant();

        virtual void VerifierPli();

        virtual void AttribuerPoints();

        virtual void VerifierCondPartie();

        virtual void FinDePartie();

        //Nouvelles méthodes
        int GrandChelem();


};
#endif
