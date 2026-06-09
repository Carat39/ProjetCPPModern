#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include <vector>
#include "Carte.h"
#include <algorithm>
#include <memory>

class Equipe;

class Joueur{
	private:
		int numero;

		std::vector<unique_ptr<Carte>> mainJ;

		int points;

		Equipe* equipe;


	public:
		Joueur(int num) {
			numero = num;
			points = 0;
			equipe = nullptr;
		}

		//On peut pas copier un joueur
		Joueur(const Joueur& autre ) = delete;
		//On peut le déplacer
		Joueur(Joueur&& autre ) noexcept = default;

		//On peut pas copier un joueur
		Joueur& operator=(const Joueur& autre) = delete;
		//On peut le déplacer
		Joueur& operator=(Joueur&& autre) noexcept = default;

		~Joueur() = default;

		std::vector<unique_ptr<Carte>> getMain()  { return move(mainJ); };

		int getNumero() const { return numero; };

		int getPoints() const { return points; };

		void addPoints(int nbPoints);

		void addCarte(unique_ptr<Carte> laCarte);

		void addMain(std::vector<unique_ptr<Carte>> lesCartes);

		void supprMain(unique_ptr<Carte> laCarte);

		bool CouleurPresente(string coul);

		bool Trouver_carte(string coul, int val);

		unique_ptr<Carte>& Renvoyer_carte(string coul, int val) noexcept;

		void Jouer();

		void AfficherMain(ostream& os) const noexcept; 

		void EliminerCarte();

		void Trier();

		//Donner la carte se fera dans pli



};
#endif
