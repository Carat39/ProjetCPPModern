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

		//Méthodes
		void set_couleur(string coul) {couleur = coul;}
		void set_valeur(int val) {valeur = val;}
		string get_couleur() const { return couleur; }
		int get_valeur() const { return valeur; }

		void AfficherCarte(ostream& os) const noexcept {
			os << get_valeur() << " " << get_couleur() << endl;
		}
};

#endif

