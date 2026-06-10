#ifndef PLI__D2_P_H
#define PLI__D2_P_H

#include <iostream>
#include <vector>
#include "Pli.h"

class PliD2P : public Pli{
	public:
		PliD2P(Paquet* paquet);

		virtual int Vainqueur(int premier_j);

		int Calcul_points();

		bool Coeur_existe();

};


#endif
