#ifndef PLI_H
#define PLI_H

#include <iostream>
#include <vector>
#include <map>
#include "Carte.h"
#include "Paquet.h"
#include <memory>


class Pli{
	protected:
		std::map<int,std::unique_ptr<Carte>> pli;
		Paquet* lePaquet;

	public:
		virtual int Vainqueur(int premier_j) = 0;

		void setCarte(int joueur, std::unique_ptr<Carte> carte);
		
};
#endif
