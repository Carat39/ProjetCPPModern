#include "Paquet.h"
#include <algorithm>
#include <random>
#include <fstream>
#include <iostream>
#include <string>

Paquet::Paquet() {
	ifstream fichier("Paquets/Paquet52Cartes.txt", ios::in);
	if (!fichier) {
		cout << "Erreur" << endl;
	}
	else {
		string nbCartes;
		fichier.ignore(10, '=');
		getline(fichier, nbCartes);
		string couleur, valeur, lettre = "";

		fichier.ignore(10, '[');
		for (unsigned int index = 0; index < (unsigned int)stoi(nbCartes); index++) {
			couleur = "";
			valeur = "";
			fichier.ignore(10, '=');
			lettre = fichier.get();
			while (lettre != ",") {
				couleur += lettre;
				lettre = fichier.get();
			}
			fichier.ignore(10, '=');
			lettre = fichier.get();
			while (lettre != "\n") {
				valeur += lettre;
				lettre = fichier.get();
			}
			//cout << couleur << " " << valeur << endl;
			try {
				Ajouter_carte(couleur, stoi(valeur));
			}
			catch (...) {
				cout << "Carte deja existante" << endl;
			}
		}
		fichier.close();
	}
}

Paquet::Paquet(string nomfichier = "Paquets/Paquet52Cartes.txt") {
	ifstream fichier(nomfichier, ios::in);
	if (!fichier) {
		cout << "Erreur" << endl;
	}
	else {
		string nbCartes;
		fichier.ignore(10, '=');
		getline(fichier, nbCartes);

		cout << "NBCartes : " << nbCartes << endl;

		string couleur, valeur, lettre = "";

		fichier.ignore(10, '[');
		for (unsigned int index = 0; index < (unsigned int)stoi(nbCartes); index++) {
			couleur = "";
			valeur = "";
			fichier.ignore(10, '=');
			lettre = fichier.get();
			while (lettre != ",") {
				couleur += lettre;
				lettre = fichier.get();
			}
			fichier.ignore(10, '=');
			lettre = fichier.get();
			while (lettre != "\n") {
				valeur += lettre;
				lettre = fichier.get();
			}
			//cout << couleur << " " << valeur << endl;
			try {
				Ajouter_carte(couleur, stoi(valeur));
			}
			catch (...) {
				cout << "Carte deja existante" << endl;
			}
		}
		fichier.close();
	}
}


void Paquet::Ajouter_carte(string coul, int val){
	//Création de la carte
	lePaquet.push_back(move(make_unique<Carte>(coul, val)));
	
}


void Paquet::AfficherPaquet(ostream& os) {
	for (std::unique_ptr<Carte>& laCarte : lePaquet) {
		laCarte->AfficherCarte(os);
	}
}


void Paquet::Melanger() {
	std::shuffle(lePaquet.begin(), lePaquet.end(), std::mt19937((unsigned int)time(nullptr))); //ou std::minstd_rand() ou std::minstd_rand0()
};


void Paquet::Distribuer(Joueur& joueur) {
	unique_ptr<Carte> carte = std::move(lePaquet[0]);
	joueur.addCarte(std::move(carte));
	//On enlève la carte du paquet
	lePaquet.erase(lePaquet.begin());
}