#ifndef PAQUET_H 
#define PAQUET_H 100


#include <iostream>
#include <vector>
#include "Carte.h"
#include "Joueur.h"

class Paquet{
	protected:
		//Attributs
		std::vector<std::unique_ptr<Carte>> lePaquet;

		std::vector<std::unique_ptr<Carte>> laDefausse;

	public:
		//Constructeurs et Destructeurs
		Paquet();
		Paquet(string nomfichier);
		~Paquet();

		//Méthodes
		void Ajouter_carte(string coul, int val);

		void Move_carte(std::unique_ptr<Carte>&& autre) noexcept {
			lePaquet.push_back(move(autre));
		}

		void AfficherPaquet(ostream& os);

		size_t taille() { return lePaquet.size(); }

		void Melanger();

		void Distribuer(Joueur& joueur);

		//Récupère la première carte du paquet
		unique_ptr<Carte>& RecupererCarte() noexcept;

		//Déplace dans laDefausse
		void DefausserCarte(unique_ptr<Carte>&& carte) noexcept;

		void DetruireCarte(string coul, int val) noexcept;

		size_t tailleDefausse() const { return laDefausse.size(); }






};

#endif // PAQUET_H 50
