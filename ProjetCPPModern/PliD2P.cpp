#include <iostream>
#include <vector>

#include "PliD2P.h"

using namespace std;

PliD2P::PliD2P(Paquet* paquet) {
	lePaquet = paquet;
}

int PliD2P::Calcul_points()
{
	int pts_pli = 0;
	for (const auto& pair : pli) {
		if ((pair.second)->get_couleur() == "♥") {
			pts_pli++;
		}
		else if ((pair.second)->get_couleur() == "♠" && (pair.second)->get_valeur() == 12) {
			pts_pli += 13;
		}
	}
	return pts_pli;
}

bool PliD2P::Coeur_existe()
{
	bool trouve= false;
	for (const auto& pair : pli) {
		if (pair.second->get_couleur() == "♥")
		{
			trouve = true;
		}
	}
	return trouve;
}

int PliD2P::Vainqueur(int premier_j, string couleurAtout) {

    if (pli.empty()) {
        throw std::runtime_error("Pli vide !");
    }

    std::vector<int> ordre;
    int nbJoueurs = pli.size();

    for (int i = 0; i < nbJoueurs; i++) {
        int j = (premier_j + i) % nbJoueurs;
        if (pli.find(j) != pli.end()) {
            ordre.push_back(j);
        }
    }

    int gagnant = ordre[0];
    string couleur_pli = pli[gagnant]->get_couleur();
    int meilleure_valeur = pli[gagnant]->get_valeur();

    for (int i = 1; i < ordre.size(); i++) {
        int j = ordre[i];
        auto& carte = pli[j];

        if (!couleurAtout.empty()) {
            if (carte->get_couleur() == couleurAtout &&
                couleur_pli != couleurAtout) {
                gagnant = j;
                meilleure_valeur = carte->get_valeur();
                couleur_pli = couleurAtout;
                continue;
            }
        }

        if (carte->get_couleur() == couleur_pli &&
            carte->get_valeur() > meilleure_valeur) {
            gagnant = j;
            meilleure_valeur = carte->get_valeur();
        }
    }

    cout << "Gagnant du pli : Joueur " << gagnant << endl;

    for (auto& pair : pli) {
        lePaquet->Move_carte(std::move(pair.second));
    }
    pli.clear();

    return gagnant;
}