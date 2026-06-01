#ifndef PAQUET_H 
#define PAQUET_H 100


#include <iostream>
#include <vector>
#include "Carte.h"
#include "Joueur.h"
using namespace std;

class Paquet{
	private:
		//Attributs
		vector<Carte> lePaquet;

	public:
		//Constructeurs et Destructeurs
		Paquet();
		Paquet(vector<string> couleursValides, vector<int> valeursValides);
		

		//Méthodes
		void Ajouter_carte(string coul, int val);

		void AfficherPaquet();

		void Melanger();

		void Distribuer(vector<Joueur> joueurs);


};

#endif // PAQUET_H 50
