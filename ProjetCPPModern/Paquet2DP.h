#ifndef PAQUET2DP_H 
#define PAQUET2DP_H 110

#include "Paquet.h"

class Paquet2DP: public Paquet{
	private:
		//Attributs
		vector<Carte> cartesEcartes;

	public:
		//Constructeurs et Destructeurs
		
		void retirer_carte(string coul, int val);

		//Déplace dans cartesEcartes
		void Invalider_carte(Carte&& autre) noexcept;




};

#endif