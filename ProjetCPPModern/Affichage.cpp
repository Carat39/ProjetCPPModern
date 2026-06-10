#include "Affichage.h"
#include "Humain.h"
#include "IA.h"

int Affichage::DemanderValeurCarte() {
	int valeur = -1;
	cout << "Valeur carte: ";
	cin >> valeur;
	cin.ignore();
	if (cin.fail()) {
		cout << "\nArgument invalide !\n" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		valeur = -1;
	}
	if (valeur < 0 || valeur > 13) {
		valeur = -1;
	}
	return valeur;
}

string Affichage::DemanderCouleurCarte() {
	string schoix = " ";
	cout << "Couleur carte: ";
	getline(cin, schoix);
	return schoix;
}

int Affichage::DemanderNbJoueurs(string Precision) {
	int valeur = -1;
	cout << "Combient y'a t-il d" << Precision << ": ";
	cin >> valeur;
	cin.ignore();
	if (cin.fail()) {
		cout << "\nArgument invalide !\n" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		valeur = -1;
	}
	if (valeur < 0 || valeur > 13) {
		valeur = -1;
	}
	return valeur; 
}


void Affichage::Afficher_jeu_Humain(vector<Humain*>& vectJ) {
	for (Humain* joueur : vectJ) {
		joueur->AfficherMain(cout);
	}
}

void Affichage::Afficher_jeu_IA(vector<IA*>& vectJ) {
	for (IA* joueur : vectJ) {
		joueur->AfficherMain(cout);
	}
}

