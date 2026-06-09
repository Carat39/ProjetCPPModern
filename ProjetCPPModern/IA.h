#ifndef JOUEUR_IA_H
#define JOUEUR_IA_H

#include <iostream>
#include <vector>
#include "Carte.h"
#include <algorithm>
#include <memory>
#include "Joueur.h"
#include <exception>
#include <stdexcept>


class IA : public Joueur {

public:

	virtual unique_ptr<Carte>& Jouer()=0;


};

#endif
