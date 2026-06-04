#ifndef PLI__D2_P_H
#define PLI__D2_P_H

#include <iostream>
#include <vector>

#include "Pli.h"

class Pli_D2P : public Pli{
	public:
		template<typename TPaquet>
		int Vainqueur(int premier_j, TPaquet le_paquet)
		{
			int le_gagnant = premier_j;
			string couleur_atout = (pli.find(premier_j))->second.get_couleur();
			int meilleur_carte = (pli.find(premier_j))->second.get_valeur();
			for (const auto& pair : pli)
			{
				if ((pair.second).get_couleur() == couleur_atout && (pair.second).get_valeur() > meilleur_carte)
				{
					le_gagnant = pair.first;
					meilleur_carte = (pair.second).get_valeur();
				}
			}
			cout << le_gagnant;

			for (int i=0; i<pli.size(); i++) {
				le_paquet.Move_carte(move(pli.at(i)));
			}

			return le_gagnant;
		}

		int Calcul_points();

		bool Coeur_existe();

};
#endif
