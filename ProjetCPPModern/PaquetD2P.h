#ifndef PAQUETD2P_H 
#define PAQUETD2P_H 110

#include "Paquet.h"

class PaquetD2P: public Paquet{
	private:
		//Attributs
		vector<Carte> cartesEcartes;

	public:
		//Constructeurs et Destructeurs
		PaquetD2P(): Paquet({ "♠","♦","♥","♣" }, { 2,3,4,5,6,7,8,9,10,11,12,13,14 }){};
		
		//Méthodes
		void retirer_carte(string coul, int val);

		//Déplace dans cartesEcartes
		void Invalider_carte(Carte&& autre) noexcept;




};



#endif