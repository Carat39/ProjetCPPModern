#ifndef PLI_H
#define PLI_H

#include <iostream>
#include <vector>
#include <map>
#include "Carte.h"

class Pli{
	protected:
		std::map<int,Carte> pli;

	public:
		
		virtual int Vainqueur(int premier_j) = 0;

		void setCarte(int joueur, Carte carte);
		
};
#endif
