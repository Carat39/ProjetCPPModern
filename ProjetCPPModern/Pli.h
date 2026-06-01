#ifndef PLI [ABS]_H
#define PLI [ABS]_H

#include <iostream>
#include <vector>
#include <map>
#include "Carte.h"

class Pli{
	private:
		map<int,Carte> pli;


	public:
		
		virtual int Vainqueur(int premier_j) = 0;

		virtual void setCarte(int joueur, Carte carte) = 0;
		
};
#endif
