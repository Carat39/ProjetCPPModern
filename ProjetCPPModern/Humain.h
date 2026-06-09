#ifndef JOUEUR_Humain_H
#define JOUEUR_Humain_H

#include <iostream>
#include <vector>
#include "Carte.h"
#include <algorithm>
#include <memory>
#include "Joueur.h"
#include "Equipe.h"


class Humain : public Joueur {

public:
	Humain(int num) {
		numero = num;
		points = 0;
		equipe = nullptr;
	}

	//On peut pas copier un joueur
	Humain(const Humain& autre) = delete;
	//On peut le déplacer
	Humain(Humain&& autre) noexcept = default;

	//On peut pas copier un joueur
	Humain& operator=(const Humain& autre) = delete;
	//On peut le déplacer
	Humain& operator=(Humain&& autre) noexcept = default;

	~Humain() = default;

	
	unique_ptr<Carte>& Jouer() override;

	//Donner la carte se fera dans pli



};
#endif
