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

Paquet::~Paquet() {
	//Détruire toute les cartes
}

void Paquet::Ajouter_carte(string coul, int val) {
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
unique_ptr<Carte>& Paquet::RecupererCarte() noexcept {
	return *(lePaquet.begin());
}

unique_ptr<Carte>& Paquet::RecupererCarteDefausse() noexcept {
	return *(laDefausse.begin());
}

void Paquet::DefausserCarte(unique_ptr<Carte>&& carte) noexcept{
	laDefausse.push_back(move(carte));
}

void Paquet::DetruireCartePaquet(int index) {
	lePaquet.erase(lePaquet.begin() + index);
}

void Paquet::DetruireCarteDefausse(int index) {
	laDefausse.erase(laDefausse.begin() + index);
}

void Paquet::DetruireCarte(string coul, int val) noexcept{
	bool find = false;
	unsigned int index = 0;
	while (index < taille() && find == false) {
		if (lePaquet[index]->get_couleur() == coul && lePaquet[index]->get_valeur() == val) {
			lePaquet.erase(lePaquet.begin() + index); // voir pour appel destructeur particulier de la carte
			find = true;
		}
		else {
			index++;
		}
	}
}