#ifndef PAQUETD2P_H 
#define PAQUETD2P_H 110

#include "Paquet.h"

class PaquetD2P: public Paquet{
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