#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include <vector>
#include "Carte.h"
class Equipe;

class Joueur{
	private:
		int numero;

		std::vector<Carte> mainJ;

		int points;

		Equipe* equipe;


	public:
		Joueur(int num) {
			numero = num;
			points = 0;
			equipe = nullptr;
		}

		std::vector<Carte> getMain() const { return mainJ; };

		int getNumero() const { return numero; };

		int getPoints() const { return points; };

		void addPoints(int nbPoints);

		void addCarte(Carte laCarte);

		void addMain(std::vector<Carte> lesCartes);

		void supprMain(Carte laCarte);

		bool CouleurPresente(string coul);

		bool Trouver_carte(string coul, int val);

		Carte& Renvoyer_carte(string coul, int val) noexcept;

		void Jouer();

		void AfficherMain(ostream& os) const noexcept; 

		//Donner la carte se fera dans pli



};
#endif
