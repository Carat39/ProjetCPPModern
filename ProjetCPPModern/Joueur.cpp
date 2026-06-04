#include <iostream>
#include <vector>

#include "Joueur.h"


void Joueur::addPoints(int nbPoints) {
	points += nbPoints;
}

void Joueur::addCarte(Carte laCarte) {
	mainJ.push_back(move(laCarte));
}

void Joueur::addMain(std::vector<Carte> lesCartes) {
	for (Carte& laCarte : lesCartes) {
		addCarte(move(laCarte));
	}
}

void Joueur::supprMain(Carte laCarte) {
	laCarte.~Carte();
}

void Joueur::Jouer() {
}

bool Joueur::CouleurPresente(string coul) {
	for (Carte& laCarte : mainJ) {
		if (laCarte.get_couleur() == coul) {
			return true;
		}
	}
	return false;
}

bool Joueur::Trouver_carte(string coul, int val) {
	for (Carte& laCarte : mainJ) {
		if (laCarte.get_couleur() == coul && laCarte.get_valeur() == val) {
			return true;
		}
	}
	return false;
}

Carte& Joueur::Renvoyer_carte(string coul, int val) noexcept {
	for (Carte& laCarte : mainJ) {
		if (laCarte.get_couleur() == coul && laCarte.get_valeur() == val) {
			return laCarte;
		}
	}
}

void Joueur::AfficherMain(ostream& os) const noexcept {
	os << "Joueur " << getNumero() << ":" << endl;
	for (const Carte& carte : mainJ) {
		carte.AfficherCarte(os);
	}
}