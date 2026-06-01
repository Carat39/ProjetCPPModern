#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include <vector>
#include "Equipe.h"
#include "Carte.h"

class Joueur{
	private:
		vector<Carte> main;

		int numero;

		int points;

		Equipe* equipe;


	public:
		vector<Carte> getMain();

		int getNumero();

		int getPoints();

		void addPoints(int nbPoints);

		void addCarte(Carte laCarte);

		void addMain(vector<Carte> lesCartes);

		void supprMain(Carte laCarte);

		void Jouer();

		bool Trouver_carte(string coul, int val);

};
#endif
