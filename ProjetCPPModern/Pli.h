#ifndef PLI_H
#define PLI_H

#include <iostream>
#include <vector>
#include <map>
#include "Carte.h"

class Pli{
	private:
		std::map<int,Carte> pli;

	public:
		
		virtual int Vainqueur(int premier_j) = 0;

		virtual void setCarte(int joueur, Carte carte) = 0;
		
};
#endif
