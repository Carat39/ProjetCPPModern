#include "JeuWizard.h"
#include <iostream>

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
		Humain leJoueur = Humain(compteur);
		lesJoueurs.push_back(move(&leJoueur));
	}
	for (compteur = 0; compteur < nbIa; compteur++) {
		Humain leJoueur = Humain(compteur); //Faudra Changer pour JoueurHumain et JoueurIA
		lesJoueurs.push_back(move(&leJoueur));
	}
}

void JeuWizard::PreparationPaquet() {
	Paquet* monPaquet = new Paquet("Paquets/PaquetWizard.txt");
	lePaquet = move(monPaquet);
}

void JeuWizard::PreparationPli() {

}

void JeuWizard::Distribution() {
	for (int indice = 0; indice < manche; indice++) {
		lePaquet->Distribuer(*lesJoueurs[indice]);
	}
}

void JeuWizard::Commencer(){
	commencer = lesJoueurs[manche]->getNumero();
}

void JeuWizard::VerifierCondManche() {

}

bool JeuWizard::CarteJouable(string laCouleur, int laValeur) {
	return 0;
}

void JeuWizard::JouerCarte(Humain* joueur, string couleur, int valeur){
	unique_ptr< Carte>& laCarte = joueur->Renvoyer_carte(couleur, valeur);
	//lePli.setCarte(joueur->getNumero(), move(laCarte));
}

void JeuWizard::ConfirmerJoueurSuivant(){
	lePaquet->AfficherPaquet(cout);
}

void JeuWizard::VerifierPli(){

}

void JeuWizard::AttribuerPoints(){

}

void JeuWizard::VerifierCondPartie(){
	lePaquet->AfficherPaquet(cout);
	manche++;
	if (manche == 60/lesJoueurs.size()+1) {
		condPartie = true;
	}
}

void JeuWizard::FinDePartie(){

}