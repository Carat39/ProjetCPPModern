#ifndef CARTE_H
#define CARTE_H 50

#include <iostream>
using namespace std;

class Carte{
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

		Carte(Carte& autre) noexcept {
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
		string get_couleur() const { return couleur; }
		int get_valeur() const { return valeur; }

		Carte& operator= (Carte&& autre) noexcept {
			couleur = autre.couleur;
			valeur = autre.valeur;
			return *this;
		}

		void AfficherCarte(ostream& os) const noexcept {
			os << get_valeur() << " " << get_couleur() << endl;
		}
};

//using laCarte = unique_ptr<Carte>;

#endif

