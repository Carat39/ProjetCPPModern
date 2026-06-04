#ifndef EQUIPE_H
#define EQUIPE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include "Joueur.h"

class Equipe
{
private:
	std::vector<Joueur> joueurs;

	int points_equipe;

public:
	Equipe() { points_equipe = 0; };
};
#endif
