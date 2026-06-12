#include "PliWizard.h"
#include <iostream>
#include <vector>

using namespace std;

PliWizard::PliWizard(Paquet* paquet) {
	lePaquet = paquet;
}

int PliWizard::Vainqueur(int premier_j,string couleurAtout = "") {
	int leGagnant = premier_j;
	string couleurPli = (pli.find(premier_j))->second->get_couleur();
	string coulMeilleurCarte = (pli.find(premier_j))->second->get_couleur();
	int valMeilleurCarte = (pli.find(premier_j))->second->get_valeur();
	for (const auto& pair : pli){
		if (coulMeilleurCarte != "WIZARD") {
			//Le pli peut être gagnable
			if ((pair.second)->get_couleur() == coulMeilleurCarte) {
				//Même couleur que la meilleur carte
				if ((pair.second)->get_valeur() == valMeilleurCarte) {
					leGagnant = pair.first;
					coulMeilleurCarte = (pair.second)->get_couleur();
					valMeilleurCarte = (pair.second)->get_valeur();
				}
			}
			else {
				//On regarde s'il a joué de l'ATOUT ou un WIZARD
				if ((pair.second)->get_couleur() == "WIZARD" ||
					(pair.second)->get_couleur() == couleurAtout) {
					leGagnant = pair.first;
					coulMeilleurCarte = (pair.second)->get_couleur();
					valMeilleurCarte = (pair.second)->get_valeur();
				}
			}
		}
	}
	if (coulMeilleurCarte == "FOU") {
		//Cas particulier à 3 ou 4 joueurs
		leGagnant = premier_j;
	}
	cout << leGagnant << endl;

	for (auto& pair : pli) {
		lePaquet->Move_carte(move(pair.second));
	}
	pli.clear();

	return leGagnant;
}