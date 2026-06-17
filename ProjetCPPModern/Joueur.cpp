#include <iostream>
#include <vector>

#include "Joueur.h"
using namespace std;

void Joueur::addPoints(int nbPoints) {
	points += nbPoints;
}

void Joueur::addCarte(unique_ptr<Carte> laCarte) {
	if (!laCarte) return;

	// On trouve le premier index numérique disponible (0, 1, 2...)
	int index = 0;
	while (mainJ.find(index) != mainJ.end()) {
		index++;
	}
	mainJ[index] = move(laCarte);
}

void Joueur::addMain(std::map<int, unique_ptr<Carte>> lesCartes) {
	for (int index = 0; index < lesCartes.size(); index++) {
		addCarte(move(lesCartes[index]));
	}
}

void Joueur::supprMain(unique_ptr<Carte> laCarte) {
	laCarte.~unique_ptr<Carte>();
}


bool Joueur::CouleurPresente(string coul) {
	for (auto it = mainJ.begin(); it != mainJ.end(); it++) {
		if ((*it).second) {
			if ((*it).second->get_couleur() == coul) {
				return true;
			}
		}
	}
	return false;
}

bool Joueur::Trouver_carte(string coul, int val){
	for (auto it = mainJ.begin(); it != mainJ.end(); it++) {
		if ((*it).second) {
			if ((*it).second->get_couleur() == coul && (*it).second->get_valeur() == val) {
				return true;
			}
		}
	}
	return false;
}

unique_ptr<Carte> Joueur::Renvoyer_carte(string coul, int val) noexcept {
	for (auto it = mainJ.begin(); it != mainJ.end(); ++it) {
		if (it->second) { // S'assurer que le pointeur n'est pas nul
			if (it->second->get_couleur() == coul && it->second->get_valeur() == val) {
				// 1. On extrait le unique_ptr (transfert de propriété)
				unique_ptr<Carte> carteTrouvee = std::move(it->second);

				// 2. On retire l'entrée de la map pour réduire la taille de la main
				mainJ.erase(it);

				// 3. On retourne la carte au demandeur
				return carteTrouvee;
			}
		}
	}
	// Cas de secours (ne devrait pas arriver si validé en amont par Trouver_carte)
	return nullptr;
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
}

string Joueur::getCouleur(unsigned int indexCarte) {
	if (mainJ[indexCarte]) {
		return mainJ[indexCarte]->get_couleur();
	}
	return " ";
}

int Joueur::getValeur(unsigned int indexCarte) {
	if (mainJ[indexCarte]){
		return mainJ[indexCarte]->get_valeur();
	}
	return -1;
}

void Joueur::AfficherMain(ostream& os) noexcept {
	os << "Joueur " << getNumero() << ":" << endl;
	for (auto it = mainJ.begin(); it != mainJ.end(); it++) {
		if ((*it).second) {
			os << "index: " << (*it).first << " Carte: ";
			((*it).second)->AfficherCarte(os);
		}
	}
}

void Joueur::AfficherMain(ostream& os, int indexSelectionne) noexcept {
	os << "Joueur " << getNumero() << ":" << endl;
	for (auto it = mainJ.begin(); it != mainJ.end(); it++) {
		if ((*it).second) {
			if ((*it).first == indexSelectionne)
			{
				os << CSI() << CLIGNOTE() << M();
			}

			os << "index: " << (*it).first << " Carte: ";
			((*it).second)->AfficherCarte(os);

			os << END_CSI();
		}
	}
}

void Joueur::Trier() {
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
}
