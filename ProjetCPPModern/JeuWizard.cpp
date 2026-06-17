#include "JeuWizard.h"
#include <iostream>
#include <fstream>

JeuWizard::JeuWizard() {
	condManche = true;
	condPartie = true;
	manche = 1;
}

void JeuWizard::DefinirNbJoueurMinMax() {
	nbJoueursMinMax[0] = 3;
	nbJoueursMinMax[1] = 6;
}

void JeuWizard::PreparationJoueur(int nbJoueur, int nbIa) {
	int indexJ, indexIA = 0;
	for (indexJ = 0; indexJ < nbJoueur; indexJ++) {
		lesJoueurs.push_back(move(new Humain(indexJ,this)));
	}
	for (indexIA = indexJ; indexIA < nbJoueur + nbIa; indexIA++) {
		lesJoueurs.push_back(move(new Humain(indexIA,this)));
	}
}

void JeuWizard::PreparationPaquet() {
	lePaquet = new Paquet("Paquets/PaquetWizard.txt");
	lePaquet->Melanger();
}

void JeuWizard::PreparationPli() {
	lePli = new PliWizard(lePaquet);
	//On met le nb de Pli par Joueur à 0
	for (int a = 0; a < lesJoueurs.size(); a++) {
		nbPli.push_back(0);
	}
	//On met les prédictions par Joueur à 0
	for (int a = 0; a < lesJoueurs.size(); a++) {
		predictions.push_back(0);
	}
}

void JeuWizard::Distribution() {
	int index1, index2 = 0;
	lePaquet->Melanger();
	//On distribue toutes les cartes
	for (index1 = 0; index1 < manche; index1++) {
		for (index2 = 0; index2 < lesJoueurs.size(); index2++) {
			lePaquet->Distribuer(*lesJoueurs[index2]);
		}
	}
	//On trie le jeu des joueurs
	for (index2 = 0; index2 < lesJoueurs.size(); index2++) {
		lesJoueurs[index2]->Trier();
	}
	couleurAtout = " ";
	couleurPli = " ";
}


/*
BUG à régler
*/
void JeuWizard::Commencer() {
	//Changement de joueur qui commence à chaque manche
	commencer = lesJoueurs[manche % lesJoueurs.size()]->getNumero();
}

void JeuWizard::ReglesSupplementaires() {
	//Definition de l'atout
	unique_ptr<Carte> laCarte = move(lePaquet->RecupererCarte());
	couleurAtout = laCarte->get_couleur();
	lePaquet->DefausserCarte(move(laCarte));
	lePaquet->DetruireCartePaquet(0);

	//Demander prediction
	int indexJ, pliDemande, totalNbPliReel = 0;
	int totalNbPlitheor = 0;
	int newindexJ = 0;
	for (indexJ = manche; indexJ < manche + lesJoueurs.size(); indexJ ++) {
		//Si humain demander Carte
		newindexJ = indexJ % lesJoueurs.size();
		if (typeid(*lesJoueurs[newindexJ]) == typeid(Humain)) {
			pliDemande = -1;
			while (0 > pliDemande || pliDemande > manche) {
				cout << "NbPli actuellement " << totalNbPliReel << endl;
				AfficherInformations(cout);
				lesJoueurs[newindexJ]->AfficherMain(cout);
				pliDemande = Affichage::Demander("Combien de pli penses tu faire: ");
				totalNbPlitheor += pliDemande;
				if (totalNbPlitheor == manche && newindexJ == manche%lesJoueurs.size() -1) {
					cout << "Impossible d'avoir autant de pli que de carte" << endl;
					totalNbPlitheor = totalNbPliReel;
					pliDemande = -1;
				}
			}
			totalNbPliReel += pliDemande;
			totalNbPlitheor = totalNbPliReel;
			predictions[newindexJ] = pliDemande;
		}
		else {
			predictions[newindexJ] = (int)lesJoueurs.size()/4;//Fonction de l'IA
		}
	}
}

void JeuWizard::AfficherInformations(ostream& os){
	system("cls");
	cout << "Manche n°" << manche << endl;
	if (couleurPli != "FOU" && couleurPli != " ") {
		os  << "Couleur Pli " << couleurPli << endl;

	}
	os << "Couleur Atout " << couleurAtout << endl;

}

bool JeuWizard::CarteJouable(Joueur* joueur, string laCouleur, int laValeur) {
	bool carteJouable = true;
	if (laCouleur == " ") {
		carteJouable = false;
	}
	else {
		if (joueur->getNumero() == commencer) {
			//On définit la couleur du pli
			couleurPli = laCouleur;
		}
		else {
			if (couleurPli == "FOU") {
				//On définit la nouvelle couleur du pli
				couleurPli = laCouleur;
			}
			else if (couleurPli != "WIZARD") {
				//Si la couleur n'est ni un fou/Wizard et que le joueur ne possède pas la couleur c'est correct
				if (laCouleur != couleurPli && joueur->CouleurPresente(couleurPli)
					&& laCouleur != "FOU"
					&& laCouleur != "WIZARD") {
					carteJouable = false;
				}
			}
		}
	}
	return carteJouable;
}

void JeuWizard::JouerCarte(Joueur* joueur, string laCouleur, int laValeur){
	unique_ptr<Carte> Cajouer = move(joueur->Renvoyer_carte(laCouleur, laValeur));
	joueur->EliminerCarte();
	lePli->setCarte(joueur->getNumero(), move(Cajouer));
}


void JeuWizard::ConfirmerJoueurSuivant(){
	string attente = "";
	system("cls");
	cout << "Appuyer sur une touche pour passer au joueur suivant";
	getline(cin, attente);
}

void JeuWizard::VerifierPli(){
	commencer = ((PliWizard*)lePli)->Vainqueur(commencer,couleurAtout);
	nbPli[commencer]++;
}

void JeuWizard::VerifierCondManche() {
	if (lePaquet->taille() == 59) {
		condManche = false;
		//On augmente la manche
		manche++;
		//On remets les cartes dans le paquets
		unique_ptr<Carte> CarteDefausse = move(lePaquet->RecupererCarteDefausse());
		lePaquet->Move_carte(move(CarteDefausse));
		lePaquet->DetruireCarteDefausse(0);
	}
	couleurPli = " ";
}

void JeuWizard::AttribuerPoints(){
	int index = 0;
	for (index = 0; index < lesJoueurs.size(); index++) {
		if (nbPli[index] == predictions[index]) {
			//gagne 20 + 10 par pli
			lesJoueurs[index]->addPoints(20 + 10* predictions[index]);
		}
		else {
			lesJoueurs[index]->addPoints(-10 * abs(predictions[index] - nbPli[index]));
		}
		//règles supplémentaire
		if (lesJoueurs[index]->getPoints() == -100) {
			//Passe à 100
			lesJoueurs[index]->addPoints(200);
		}
		//On réinitialise les nbPlis
		nbPli[index] = 0;
	}
}

void JeuWizard::VerifierCondPartie(){
	if (manche == 60/lesJoueurs.size()+1) {
		condPartie = true;
	}
}

void JeuWizard::FinDePartie(){
	int indexJ = 0;
	for (indexJ = 0; indexJ < lesJoueurs.size(); indexJ++) {
		cout << "Pts Finaux Joueur n°" << lesJoueurs[indexJ]->getNumero()
			<< " = " << lesJoueurs[indexJ]->getPoints() << endl;
	}
}
