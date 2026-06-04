#include "Affichage.h"

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

void Affichage::Afficher_jeu() {
}