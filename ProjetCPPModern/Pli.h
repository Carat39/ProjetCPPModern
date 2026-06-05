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
		template<typename TPaquet>
		int Vainqueur(int premier_j, TPaquet& le_paquet);

		void setCarte(int joueur, Carte carte);
		
};
template<typename TPaquet>
int Pli::Vainqueur(int premier_j, TPaquet& le_paquet){
	return 0;
}
#endif
