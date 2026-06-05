#ifndef JEU_H
#define JEU_H 15

#include <iostream>
#include <vector>
#include "Joueur.h"

class Jeu{
	private:
		std::vector<Joueur> joueurs;

		int nb_pli;

		std::vector<int> points_temp;

	public:
		virtual void Partie(int nb_humains, int nb_ia) = 0;

		virtual int Verifier_points() = 0;

		virtual int Commencer_tour() = 0;

		virtual void Attribuer_points() = 0;

};
#endif