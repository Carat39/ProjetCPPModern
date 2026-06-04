#ifndef PAQUET_H 
#define PAQUET_H 100


#include <iostream>
#include <vector>
#include "Carte.h"
#include "Joueur.h"

class Paquet {
protected:
	//Attributs
	std::vector<Carte> lePaquet;

public:
	//Constructeurs et Destructeurs
	Paquet();
	Paquet(std::vector<string> couleursValides, std::vector<int> valeursValides);

	//Méthodes
	void Ajouter_carte(string coul, int val);

	void Move_carte(Carte&& autre) noexcept {
		lePaquet.push_back(move(autre));
	}

	void AfficherPaquet(ostream& os);

	size_t taille() { return lePaquet.size(); }

	void Melanger();

	void Distribuer(Joueur& joueur);





};

#endif // PAQUET_H 50