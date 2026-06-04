#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Dame2Pique.h"
#include "Affichage.h"
#include "Pli_D2P.h"
#include "PaquetD2P.h"
#include "Carte.h"


void Dame2Pique::Partie(int nb_humains, int nb_ia)
{

	lePaquet = PaquetD2P();

	size_t carte_a_retirer = lePaquet.taille() % joueurs.size();
	if (carte_a_retirer > 0) {
		lePaquet.retirer_carte("♦", 2);
	}
	if (carte_a_retirer > 1) {
		lePaquet.retirer_carte("♣", 2);
	}
	for (int i = 0; i < nb_humains + nb_ia; i++) {
		Joueur joueur = Joueur(i);
		joueurs.push_back(joueur);
	}

	int commence = Commencer_tour();
	int val;
	bool carte_ok = true;
	std::string coul;
	std::string couleur_pli;

	while (Verifier_points() == -1) {

		for (int i = 0; i < lePaquet.taille() / joueurs.size(); i++) {
			for (int j = commence; j < commence + joueurs.size(); j++) {
				carte_ok = false;

				while (carte_ok == false) {
					if (j == commence) {
						val = Affichage::DemanderValeurCarte();
						coul = Affichage::DemanderCouleurCarte();
						if (joueurs[i].Trouver_carte(coul, val)) {
							carte_ok = true;
						}
						if (coul == "♥" && coeur_bloque) {
							if (!joueurs[i].CouleurPresente("♣") && !joueurs[i].CouleurPresente("♦") && !joueurs[i].CouleurPresente("♠")) {
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
						if (joueurs[i].Trouver_carte(coul, val)) {
							carte_ok = true;
						}
						if (joueurs[i].CouleurPresente(couleur_pli) && coul != couleur_pli) {
							carte_ok = false;
						}
					}
				}


				Carte Cajouer = move(joueurs[i].Renvoyer_carte(coul, val));
				lePli.setCarte(j % 4, Cajouer);

			}

			commence = lePli.Vainqueur(commence,lePaquet);
			points_temp[commence]+= lePli.Calcul_points();

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

	
	lePaquet.Melanger();
	for ( i = 0; i < lePaquet.taille()/ joueurs.size(); i++) {
		for ( j = 0; j < joueurs.size(); j++) {
			lePaquet.Distribuer(joueurs[j]);
		}
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
