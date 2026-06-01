#include <iostream>
#include <vector>

#include "Joueur.h"


void Joueur::addPoints(int nbPoints){
	points += nbPoints;
}

void Joueur::addCarte(Carte laCarte) {
	mainJ.push_back(move(laCarte));
}

void Joueur::addMain(std::vector<Carte> lesCartes){
	for (Carte& laCarte : lesCartes) {
		addCarte(move(laCarte));
	}
}

void Joueur::supprMain(Carte laCarte){
	laCarte.~Carte();
}

void Joueur::Jouer(){
}

bool Joueur::Trouver_carte(string coul, int val){
	return 0;
}

void Joueur::AfficherMain(ostream& os) const noexcept {
	os << "Joueur " << getNumero() << ":" << endl;
	for (const Carte& carte : mainJ) {
		carte.AfficherCarte(os);
	}
}
