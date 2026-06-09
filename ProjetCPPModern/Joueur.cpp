#include <iostream>
#include <vector>

#include "Joueur.h"
using namespace std;

void Joueur::addPoints(int nbPoints){
	points += nbPoints;
}

void Joueur::addCarte(unique_ptr<Carte> laCarte) {
	mainJ.push_back(move(laCarte));
}

void Joueur::addMain(std::vector<unique_ptr<Carte>> lesCartes){
	for (unique_ptr<Carte>& laCarte : lesCartes) {
		addCarte(move(laCarte));
	}
}

void Joueur::supprMain(unique_ptr<Carte> laCarte){
	laCarte.~unique_ptr<Carte>();
}


bool Joueur::CouleurPresente(string coul) {
	for (unique_ptr<Carte>& laCarte : mainJ) {
		if (laCarte->get_couleur() == coul) {
			return true;
		}
	}
	return false;
}

bool Joueur::Trouver_carte(string coul, int val){
	for (unique_ptr<Carte>& laCarte : mainJ) {
		if (laCarte->get_couleur() == coul && laCarte->get_valeur() == val) {
			return true;
		}
	}
	return false;
}

unique_ptr<Carte>& Joueur::Renvoyer_carte(string coul, int val) noexcept {
	int index = 0;
	for (index = 0; index < mainJ.size(); index++) {
		if (mainJ[index]->get_couleur() == coul && mainJ[index]->get_valeur() == val) {
			unique_ptr<Carte>& laCarte = mainJ[index];
			return laCarte;
		}
	} 
}

void Joueur::EliminerCarte() {
	int index = 0;
	for (index = 0; index < mainJ.size(); index++) {
		if (!mainJ[index]) {
			mainJ.erase(mainJ.begin() + index);

		}
	}
}


void Joueur::AfficherMain(ostream& os) const noexcept {
	os << "Joueur " << getNumero() << ":" << endl;
	for (const unique_ptr<Carte>& carte : mainJ) {
		carte->AfficherCarte(os);
	}
}

void Joueur::Trier() {
	sort(mainJ.begin(), mainJ.end(), [](const auto& carte1, const auto& carte2) {
		return *carte1 < *carte2;
	});
}

/*sort(scheduling.begin(), scheduling.end(), [&tasks](int scheduling1, int scheduling2) {
	return tasks[scheduling2].d > tasks[scheduling1].d;
	});
	*/