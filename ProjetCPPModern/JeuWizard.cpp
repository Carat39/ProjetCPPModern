#include "JeuWizard.h"
#include <iostream>
#include <fstream>

JeuWizard::JeuWizard() {
	condPartie = false;
	manche = 1;
}

void JeuWizard::DefinirNbJoueurMinMax() {
	nbJoueursMinMax[0] = 3;
	nbJoueursMinMax[1] = 6;
}

void JeuWizard::PreparationJoueur(int nbJoueur, int nbIa) {
	int compteur;
	for (compteur = 0; compteur < nbJoueur; compteur++) {
		Joueur leJoueur = Joueur(compteur);
		lesJoueurs.push_back(move(&leJoueur));
	}
	for (compteur = 0; compteur < nbIa; compteur++) {
		Joueur leJoueur = Joueur(compteur); //Faudra Changer pour JoueurHumain et JoueurIA
		lesJoueurs.push_back(move(&leJoueur));
	}
}

void JeuWizard::PreparationPaquet() {
	ifstream fichier("Paquets/PaquetWizard.txt", ios::in);
	if (!fichier) {
		cout << "Erreur" << endl;
	}
	else {
		Paquet monPaquet;
		string nbCartes;
		fichier.ignore(11, '=');
		getline(fichier, nbCartes);

		cout << "NBCartes : " << nbCartes << endl;

		string couleur, valeur, lettre="";

		fichier.ignore(10, '[');
		for (unsigned int index = 0; index < (unsigned int)stoi(nbCartes) + 1; index++) {
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
				monPaquet.Ajouter_carte(couleur, stoi(valeur));
			}
			catch (...) {
				cout << "Carte deja existante" << endl;
			}
		}
		//lePaquet = move(monPaquet);
		fichier.close();
	}
}

void JeuWizard::PreparationPli() {

}

void JeuWizard::Distribution() {
	for (int indice = 0; indice < manche; indice++) {
		//lePaquet.Distribuer(*lesJoueurs[indice]);
	}
}

void JeuWizard::Commencer(){
	commencer = lesJoueurs[manche]->getNumero();
}

void JeuWizard::VerifierCondManche() {

}

bool JeuWizard::CarteJouable(Joueur* joueur, string laCouleur, int laValeur) {
	return true;
}

void JeuWizard::JouerCarte(Joueur* joueur, string couleur, int valeur){
	//Carte& laCarte = joueur->Renvoyer_carte(couleur, valeur);
	//lePli.setCarte(joueur->getNumero(), move(laCarte));
}

void JeuWizard::ConfirmerJoueurSuivant(){
	//lePaquet.AfficherPaquet(cout);
}

void JeuWizard::VerifierPli(){

}

void JeuWizard::AttribuerPoints(){

}

void JeuWizard::VerifierCondPartie(){
	//lePaquet.AfficherPaquet(cout);
	manche++;
	if (manche == 60/lesJoueurs.size()+1) {
		condPartie = true;
	}
}

void JeuWizard::FinDePartie(){

}