#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include <vector>
#include <map>
#include "Carte.h"
#include <memory>
#include <utility>
#include <algorithm>

class Equipe;
class JeuClem;

class Joueur{
	protected:
		int numero;

		std::map<int,unique_ptr<Carte>> mainJ;

		int points;

		Equipe* equipe;

		JeuClem* jeu;

	public:


		std::map<int,unique_ptr<Carte>> getMain()  { return move(mainJ); };

		int getNumero() const { return numero; };

		int getPoints() const { return points; };

		void addPoints(int nbPoints);

		void addCarte(unique_ptr<Carte> laCarte);

		void addMain(std::map<int,unique_ptr<Carte>> lesCartes);

		void supprMain(unique_ptr<Carte> laCarte);

		bool CouleurPresente(string coul);

		bool Trouver_carte(string coul, int val);

		unique_ptr<Carte> Renvoyer_carte(string coul, int val) noexcept;

		string getCouleur(unsigned int indexCarte);

		int getValeur(unsigned int indexCarte);

		size_t get_taille() const { return mainJ.size(); }

		virtual std::unique_ptr<Carte> Jouer()=0;

		void AfficherMain(ostream& os) noexcept; 

		void EliminerCarte();

		void Trier();

		//Donner la carte se fera dans pli



};
#endif
