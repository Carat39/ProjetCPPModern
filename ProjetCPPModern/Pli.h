#ifndef PLI_H
#define PLI_H

#include <iostream>
#include <vector>
#include <map>
#include "Carte.h"
#include <memory>


class Pli{
	protected:
		std::map<int,std::unique_ptr<Carte>> pli;

	public:
		template<typename TPaquet>
		int Vainqueur(int premier_j, TPaquet& le_paquet);

		void setCarte(int joueur, std::unique_ptr<Carte> carte);
		
};
template<typename TPaquet>
int Pli::Vainqueur(int premier_j, TPaquet& le_paquet){
	return 0;
}
#endif
