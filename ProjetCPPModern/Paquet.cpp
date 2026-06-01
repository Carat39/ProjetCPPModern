#include "Paquet.h"
#include <algorithm>
#include <random>

int myrandom(int i) {
	return std::rand() % i;
}

Paquet::Paquet() {
	std::vector<string> couleursValides = {"♠","♦","♥","♣"};
	std::vector<int> valeursValides = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
	for (string& coul : couleursValides) {
		for (int& val : valeursValides) {
			Ajouter_carte(coul, val);
		}
	}
}

Paquet::Paquet(std::vector<string> couleursValides, std::vector<int> valeursValides) {
	for (string& coul : couleursValides) {
		for (int& val : valeursValides) {
			Ajouter_carte(coul, val);
		}
	}
}


void Paquet::Ajouter_carte(string coul, int val){
	//Création de la carte
	lePaquet.push_back(move(Carte(coul,val)));
}


void Paquet::AfficherPaquet() {
	for (Carte& laCarte : lePaquet) {
		laCarte.AfficherCarte(cout);
	}
}

void Paquet::supprCarte() {
	lePaquet.erase(lePaquet.begin());
}


void Paquet::Melanger() {
	srand(unsigned(time(NULL)));
	std::shuffle(lePaquet.begin(), lePaquet.end(), std::mt19937()); //ou std::minstd_rand() ou std::minstd_rand0()
};


void Paquet::Distribuer(Joueur& joueur) {
	Carte carte = std::move(lePaquet[0]);
	joueur.addCarte(std::move(carte));
	supprCarte();
}