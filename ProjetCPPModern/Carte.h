#ifndef CARTE_H
#define CARTE_H 50

#include <iostream>
#include <memory>
#include "Affichage.h"
using namespace std;

class Carte {
private:
	//Attributs
	string couleur;
	int valeur;

public:
	//Constructeurs et Destructeurs
	Carte() {
		couleur = " ";
		valeur = -1;
	}
	Carte(string coul, int val) {
		couleur = coul;
		valeur = val;
	}

	Carte(Carte& autre)  {
		couleur = autre.couleur;
		valeur = autre.valeur;
	}

	Carte(Carte&& autre) noexcept {
		couleur = autre.couleur;
		valeur = autre.valeur;
	}


	//Méthodes
	void set_couleur(string coul) {couleur = coul;}
	void set_valeur(int val) {valeur = val;}
	string get_couleur() const{ return couleur; }
	int get_valeur() const { return valeur; }

	Carte& operator= (Carte&& autre) noexcept {
		couleur = autre.couleur;
		valeur = autre.valeur;
		return *this;
	}

	void AfficherCarte(ostream& os) const  {
		if (get_couleur() == "♠" || get_couleur() == "VIOLET")
		{
			os << PIQUE() + M();
			//cout << "1" <<endl;
		}
		else if (get_couleur() == "♣" || get_couleur() == "VERT")
		{
			os << TREFLE() + M();
			//cout << "2" << endl;
		}
		else if (get_couleur() == "♦" || get_couleur() == "BLEU")
		{
			os << CARREAU() + M();
			//cout << "3" << endl;
		}
		else if (get_couleur() == "♥" || get_couleur() == "ROUGE")
		{
			os << COEUR() + M();
			//cout << "4" << endl;
		}

		os << " |" << get_valeur() << get_couleur() << "| " <<endl;
		os << END_CSI();
	}

	bool operator<(Carte& other) {
		if (this->get_couleur() == other.get_couleur()) {
			return this->get_valeur() > other.get_valeur();
		}
		return this->get_couleur() < other.get_couleur();
	}
};

//using laCarte = unique_ptr<Carte>;

#endif