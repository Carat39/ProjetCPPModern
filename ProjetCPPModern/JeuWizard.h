#ifndef JEUWIZARD_H
#define JEUWIZARD_H 300
#include "JeuClem.h"
using namespace std;

class JeuWizard:public JeuClem{
    private:
        int manche;
	public:
        JeuWizard();

        virtual void DefinirNbJoueurMinMax();

        virtual void PreparationJoueur(int nbJoueur, int nbIa);

        virtual void PreparationPaquet();

        virtual void PreparationPli();

        virtual void Distribution();

        virtual void Commencer();

        virtual void VerifierCondManche();


        virtual bool CarteJouable(string laCouleur, int laValeur);

        virtual void JouerCarte(Joueur* joueur,string couleur, int valeur);

        virtual void ConfirmerJoueurSuivant();

        virtual void VerifierPli();

        virtual void AttribuerPoints();

        virtual void VerifierCondPartie();

        virtual void FinDePartie();
};

#endif

