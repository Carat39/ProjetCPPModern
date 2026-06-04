#ifndef PLI__D2_P_H
#define PLI__D2_P_H

#include <iostream>
#include <vector>

#include "Pli.h"

class Pli_D2P : public Pli{
	public:
		template<typename TPaquet>
		int Vainqueur(int premier_j, TPaquet le_paquet);

		int Calcul_points();

		bool Coeur_existe();

};
#endif
