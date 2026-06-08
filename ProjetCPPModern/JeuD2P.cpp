#include "JeuD2P.h"


JeuD2P::JeuD2P() :JeuClem() {
	coeur_bloque = true;
	nb_pli = 0;
	dongauche = true;
	condManche = true;
	condPartie = true;
	couleurPli = "";
}

void JeuD2P::DefinirNbJoueurMinMax() {
	nbJoueursMinMax[0] = 3;
	nbJoueursMinMax[1] = 5;
}

void JeuD2P::PreparationJoueur(int nbJoueur, int nbIa) {
	for (int i = 0; i < nbJoueur + nbIa; i++) {
		Joueur joueur = Joueur(i);
		lesJoueurs.push_back(move(&joueur));
	}
}

void JeuD2P::PreparationPaquet() {
	lePaquet = new PaquetD2P();
	size_t carte_a_retirer = lePaquet->taille() % lesJoueurs.size();
	if (carte_a_retirer > 0) {
		((PaquetD2P*)lePaquet)->retirer_carte("♦", 2);
	}
	if (carte_a_retirer > 1) {
		((PaquetD2P*)lePaquet)->retirer_carte("♣", 2);
	}
}

void JeuD2P::PreparationPli() {
	lePli = new PliD2P();
	//On met les points tmp à 0
	for (int a = 0; a < lesJoueurs.size(); a++) {
		points_temp.push_back(0);
	}
}

void JeuD2P::Distribution() {
	int index1,index2 = 0;
	//On distribue toutes les cartes
	for (index1 = 0; index1 < 52; index1++) {
		for (index2 = 0; index2 < lesJoueurs.size(); index2++) {
			lePaquet->Distribuer(*lesJoueurs[index2]);
		}
	}
	//On trie le jeu des joueurs
	for (index2 = 0; index2 < lesJoueurs.size(); index2++) {
		lesJoueurs[index2]->Trier();
	}
}

void JeuD2P::Commencer() {
	//Celui qui a la dame de coeur commence
	int index3 = 0;
	bool trouver = false;
	while (index3 < lesJoueurs.size() && !trouver) {
		if (lesJoueurs[index3]->Trouver_carte("♥", 12)) {
			commencer = index3;
			trouver = true;
		}
		else {
			index3++;
		}
	}
}

bool JeuD2P::CarteJouable(string laCouleur, int laValeur) {
	/*if (laCouleur == "♥" && coeur_bloque) {
		if (!lesJoueurs[j % lesJoueurs.size()].CouleurPresente("♣") 
			&& !lesJoueurs[j % lesJoueurs.size()].CouleurPresente("♦") 
			&& !lesJoueurs[j % lesJoueurs.size()].CouleurPresente("♠")) {
			//On définit la couleur du pli
				couleurPli = laCouleur;
				return true;
		}
		else {
			return false;
		}
	}*/
	return false;
}

void JeuD2P::JouerCarte(Joueur* joueur, string couleur, int valeur) {

}

void JeuD2P::ConfirmerJoueurSuivant() {

}

void JeuD2P::VerifierPli() {

}

void JeuD2P::VerifierCondManche() {
	int total = 0;
	for (int pts : points_temp) {
		total += pts;
	}
	if (total == 26) {
		condManche = false;
	}
}

void JeuD2P::AttribuerPoints() {
	int index = 0;
	for (index = 0; index < lesJoueurs.size(); index++) {
		lesJoueurs[index]->addPoints(points_temp[index]);
	}
}

void JeuD2P::VerifierCondPartie() {
	/*if (lePaquet->taille() == 50 || lePaquet->taille() == 51 || lePaquet->taille() == 52) {
		condPartie = false;
	}*/
}

void JeuD2P::FinDePartie() {

}