#ifndef JEUWIZARD_H
#define JEUWIZARD_H 300
#include "JeuClem.h"
#include "Humain.h"
#include "PliWizard.h"
using namespace std;

class JeuWizard:public JeuClem{
    private:
        int manche;

        string couleurAtout;

        vector<int> predictions;

        vector<int> nbPli;

	public:
        JeuWizard();

        virtual void DefinirNbJoueurMinMax();

        virtual void PreparationJoueur(int nbJoueur, int nbIa);

        virtual void PreparationPaquet();

        virtual void PreparationPli();

        virtual void Distribution();

        virtual void ReglesSupplementaires();

        virtual void AfficherInformations(ostream& os);

        virtual void Commencer();

        virtual void VerifierCondManche();

        virtual bool CarteJouable(Joueur* joueur,string laCouleur, int laValeur);

        virtual void JouerCarte(Joueur* joueur, unique_ptr<Carte> laCarte);

        virtual void ConfirmerJoueurSuivant();

        virtual void VerifierPli();

        virtual void AttribuerPoints();

        virtual void VerifierCondPartie();

        virtual void FinDePartie();
};

#endif

