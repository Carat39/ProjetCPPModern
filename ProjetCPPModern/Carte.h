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
		Carte();
		Carte(string coul, int val);
		//move constructeur
		Carte(Carte&& autre) noexcept;

		//Méthodes
		string get_couleur() const { return couleur; }
		int get_valeur() const { return valeur; }

		void AfficherCarte(ostream& os) const noexcept {
			os << get_valeur() << " " << get_couleur() << endl;
		}
};

#endif

