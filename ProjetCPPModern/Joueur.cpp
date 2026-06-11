#include <iostream>
#include <vector>

#include "Joueur.h"
using namespace std;

void Joueur::addPoints(int nbPoints) {
	points += nbPoints;
}

void Joueur::addCarte(unique_ptr<Carte> laCarte) {
	mainJ.emplace((int) mainJ.size(), move(laCarte));
}

void Joueur::addMain(std::map<int, unique_ptr<Carte>> lesCartes) {
	/*for (unique_ptr<Carte>& laCarte : lesCartes) {
		addCarte(move(laCarte));
	}*/
	for (int index = 0; index < lesCartes.size(); index++) {
		addCarte(move(lesCartes[index]));
	}
}
// Une map de MAP

void Joueur::supprMain(unique_ptr<Carte> laCarte) {
	laCarte.~unique_ptr<Carte>();
}


bool Joueur::CouleurPresente(string coul) {
	for (auto it = mainJ.begin(); it != mainJ.end(); it++) {
		if ((*it).second->get_couleur() == coul){
			return true;
		}
	}
	return false;
}

bool Joueur::Trouver_carte(string coul, int val){
	for (auto it = mainJ.begin(); it != mainJ.end(); it++) {
		if ((*it).second->get_couleur() == coul && (*it).second->get_valeur() == val) {
			return true;
		}
	}
	return false;
}

unique_ptr<Carte>& Joueur::Renvoyer_carte(string coul, int val) noexcept {
	for (auto it = mainJ.begin(); it != mainJ.end(); it++) {
		if ((*it).second->get_couleur() == coul && (*it).second->get_valeur() == val) {
			return (*it).second;
		}
	}
	return (mainJ.begin())->second;
}

void Joueur::EliminerCarte() {
	auto it = mainJ.begin();
	while (it != mainJ.end()) {
		if (!((*it).second)) {
			it = mainJ.erase(it);
		}
		else { 
			it++; 
		}
	}
	/*int index = 0;
	for (index = 0; index < mainJ.size(); index++) {
		if (!mainJ[index]) {
			mainJ.erase(index);
		}
	}*/
}


void Joueur::AfficherMain(ostream& os) noexcept {
	os << "Joueur " << getNumero() << ":" << endl;
	for (auto it = mainJ.begin(); it != mainJ.end(); it++) {
		((*it).second)->AfficherCarte(os);
	}
}

void Joueur::Trier() {
	/*for (indexCarte = 0; indexCarte < size; indexCarte++) {
		vectorATrier.push_back(move(mainJ[indexCarte]));
	}*/
	int indexCarte = 0;
	size_t size = mainJ.size();
	vector<unique_ptr<Carte>> vectorATrier;
	for (auto itCarte = mainJ.begin(); itCarte != mainJ.end(); itCarte++) {
		vectorATrier.push_back(move((*itCarte).second));
	}
	mainJ.clear();
	sort(vectorATrier.begin(), vectorATrier.end(), [](const auto& carte1, const auto& carte2) {
		return *carte1 < *carte2;
	});
	for (indexCarte = 0; indexCarte < size; indexCarte++) {
		addCarte(move(vectorATrier[indexCarte]));
	}
	cout << "ok";
}
