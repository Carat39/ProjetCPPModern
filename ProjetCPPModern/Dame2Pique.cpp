#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Dame2Pique.h"
#include "Affichage.h"
#include "PliD2P.h"
#include "PaquetD2P.h"
#include "Carte.h"


void Dame2Pique::Partie(int nb_humains, int nb_ia){
	lePaquet = PaquetD2P();
	for (int i = 0; i < nb_humains + nb_ia; i++) {
		Humain joueur = Humain(i);
		joueurs.push_back(move(joueur));
	}

	size_t carte_a_retirer = lePaquet.taille() % joueurs.size();
	if (carte_a_retirer > 0) {
		lePaquet.retirer_carte("♦", 2);
	}
	if (carte_a_retirer > 1) {
		lePaquet.retirer_carte("♣", 2);
	}
	//ok
	size_t taille = lePaquet.taille() / joueurs.size();
	int commence = Commencer_tour();
	int val;
	coeur_bloque = true;
	bool carte_ok = true;
	std::string coul;
	std::string couleur_pli;
	for (int a = 0; a < 4; a++) {
		points_temp.push_back(0);
	}

	while (Verifier_points() == -1) {
		commence = Commencer_tour();
		for (int i = 0; i < taille; i++) {
			for (int j = commence; j < commence + joueurs.size(); j++) {
				carte_ok = false;

				while (carte_ok == false) {
					joueurs[j%joueurs.size()].AfficherMain(cout);
					if (j == commence) {
						val = Affichage::DemanderValeurCarte();
						coul = Affichage::DemanderCouleurCarte();
						if (joueurs[j % joueurs.size()].Trouver_carte(coul, val)) {
							carte_ok = true;
						}
						if (coul == "♥" && coeur_bloque) {
							if (!joueurs[j % joueurs.size()].CouleurPresente("♣") && !joueurs[j % joueurs.size()].CouleurPresente("♦") && !joueurs[j % joueurs.size()].CouleurPresente("♠")) {
								carte_ok = true;
							}
							else {
								carte_ok = false;
							}
						}
						couleur_pli = coul;
					}
					if (j != commence) {
						val = Affichage::DemanderValeurCarte();
						coul = Affichage::DemanderCouleurCarte();
						if (joueurs[j % joueurs.size()].Trouver_carte(coul, val)) {
							carte_ok = true;
						}
						if (joueurs[j % joueurs.size()].CouleurPresente(couleur_pli) && coul != couleur_pli) {
							carte_ok = false;
						}
					}
				}

				//Ici je me suis arreté
				unique_ptr<Carte> Cajouer = move(joueurs[j % joueurs.size()].Renvoyer_carte(coul, val));
				joueurs[j % joueurs.size()].EliminerCarte();
				lePli.setCarte(j % joueurs.size(), move(Cajouer));

			}
			points_temp[commence] += lePli.Calcul_points();
			commence = lePli.Vainqueur(commence);

		}
		Attribuer_points();

	}

	for (int i = 0; i < joueurs.size(); i++) {
		if (joueurs[i].getPoints() >= 50) {
			printf("Joueur Numero %d perdant", i);
		}
	}

}

int Dame2Pique::Verifier_points()
{
	int perdant = -1;
	for (int i = 0; i < joueurs.size(); i++) {
		if (perdant == -1 && joueurs[i].getPoints() >= 50) {
			perdant = i;
		}
		else {
			if (perdant != -1 && joueurs[i].getPoints() >= 50) {
				if (joueurs[i].getPoints() > joueurs[perdant].getPoints()) {
					perdant = i;
				}
			}
		}
		return perdant;
	}
	return 0;
}

int Dame2Pique::Commencer_tour()
{
	int i;
	int j;
	size_t taille = lePaquet.taille() / joueurs.size();


	lePaquet.Melanger();
	for (i = 0; i < taille; i++) {
		for (j = 0; j < joueurs.size(); j++) {
			lePaquet.Distribuer(joueurs[j]);
		}
	}
	for (j = 0; j < joueurs.size(); j++) {
		joueurs[j].Trier();
	}
	for (i = 0; i < joueurs.size(); i++) {
		if (joueurs[i].Trouver_carte("♥", 12)) {
			return i;
		}
	}
	return 0;
}

int Dame2Pique::Grand_chelem()
{
	for (int i = 0; i < joueurs.size(); i++) {
		if (joueurs[i].getPoints() == 26) {
			return i;
		}
	}
	return -1;
}

void Dame2Pique::Attribuer_points()
{
	int gagnant = Grand_chelem();
	if (gagnant != -1) {
		for (int i = 0; i < joueurs.size(); i++) {
			if (i != gagnant) {
				joueurs[i].addPoints(26);
			}
		}
	}
	else {
		for (int i = 0; i < joueurs.size(); i++) {
			joueurs[i].addPoints(points_temp[i]);
		}
	}
}