#include "Paquet.h"

Paquet::Paquet() {
	vector<string> couleursValides = {"♠","♦","♥","♣"};
	vector<int> valeursValides = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
	for (string& coul : couleursValides) {
		for (int& val : valeursValides) {
			Ajouter_carte(coul, val);
		}
	}
}

Paquet::Paquet(vector<string> couleursValides, vector<int> valeursValides) {
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

void Paquet::Melanger(){
}

void Paquet::Distribuer(Joueur joueur){
}