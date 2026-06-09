#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include <vector>
#include "Carte.h"
#include <algorithm>
#include <memory>
#include "JeuClem.h"

class Equipe;

class Joueur{
	protected:
		int numero;

		std::vector<unique_ptr<Carte>> mainJ;

		int points;

		Equipe* equipe;

		JeuClem* jeu;

	public:


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

		virtual unique_ptr<Carte>& Jouer()=0;

		void AfficherMain(ostream& os) const noexcept; 

		void EliminerCarte();

		void Trier();

		//Donner la carte se fera dans pli



};
#endif
