#include "JeuD2P.h"
#include <utility>


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
	int indexJ, indexIA = 0;
	for (indexJ = 0; indexJ < nbJoueur; indexJ++) {
		lesJoueurs.push_back(move(new Humain(indexJ)));
	}
	for (indexIA = indexJ; indexIA < nbJoueur + nbIa; indexIA++) {
		lesJoueurs.push_back(move(new IADame2Pique(indexIA)));
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
	lePaquet->Melanger();
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
	for (index1 = 0; index1 < 52/lesJoueurs.size(); index1++) {
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

bool JeuD2P::CarteJouable(Joueur* joueur, string laCouleur, int laValeur) {
	bool cartejouable = true;
	if (!joueur->Trouver_carte(laCouleur, laValeur)) {
		//Il n'a pas cette carte
		cartejouable = false;
	}
	else{
		//si c'est le premier joueur qui est en train de jouer
		if (joueur->getNumero() == commencer) {
			//On définit la couleur du pli
			couleurPli = laCouleur;
			//Joue t-il du coeur en premier?
			if (laCouleur == "♥" && coeur_bloque) {
				//Il possede encore du coeur
				if (joueur->CouleurPresente("♣")
					|| joueur->CouleurPresente("♦")
					|| joueur->CouleurPresente("♠")) {
					cartejouable = false;
				}
				else {
					cartejouable = false;
				}
			}
		}
		else {
			if (laCouleur != couleurPli && joueur->CouleurPresente(couleurPli)) {
				cartejouable = false;
			}
		}
	}
	if (cartejouable && laCouleur == "♥") {
		coeur_bloque = false;
	}
	return cartejouable;
}

void JeuD2P::JouerCarte(Joueur* joueur, string laCouleur, int laValeur) {
	unique_ptr<Carte> Cajouer = move(joueur->Renvoyer_carte(laCouleur, laValeur));
	joueur->EliminerCarte();
	lePli->setCarte(joueur->getNumero(), move(Cajouer));
}

void JeuD2P::ConfirmerJoueurSuivant() {
	system("cls");
}

void JeuD2P::VerifierPli() {
	points_temp[commencer] += ((PliD2P*)lePli)->Calcul_points();
	commencer = ((PliD2P*)lePli)->Vainqueur(commencer);
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
	int indexJ = 0;
	for (indexJ = 0; indexJ < lesJoueurs.size();indexJ++) {
		if (lesJoueurs[indexJ]->getPoints() >= 50) {
			condPartie = false;
		}
	}
}

void JeuD2P::FinDePartie() {
	//Trier à l'avenir comme dans le TP avec les tasks
	int indexJ = 0;
	for (indexJ = 0; indexJ < lesJoueurs.size(); indexJ++) {
		cout << "Pts Finaux Joueur n°" << lesJoueurs[indexJ]->getNumero() 
			<< " = " << lesJoueurs[indexJ]->getPoints() << endl;
	}
}