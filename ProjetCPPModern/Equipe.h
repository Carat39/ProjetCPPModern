#ifndef EQUIPE_H
#define EQUIPE_H

#include <iostream>
#include <vector>
#include "Joueur.h"


class Equipe{
	private:
		std::vector<Joueur> joueurs;

		int points_equipe;
	public:

		std::vector<Joueur> get_joueurs() { return joueurs; }
		int get_points() { return points_equipe; }
		void set_points(int nv_points) { points_equipe = nv_points; }

		Joueur* Trouver_Joueur(int numJ);

};
#endif
