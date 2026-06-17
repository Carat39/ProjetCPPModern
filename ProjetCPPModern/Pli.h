#ifndef PLI_H
#define PLI_H

#include <iostream>
#include <vector>
#include <map>
#include "Carte.h"
#include "Paquet.h"
#include <memory>
#include <iostream>


class Pli{
	protected:
		std::map<int,std::unique_ptr<Carte>> pli;
		Paquet* lePaquet;

	public:
		virtual int Vainqueur(int premier_j, string couleurAtout) = 0;

		void setCarte(int joueur, std::unique_ptr<Carte> carte);
		
		void Afficher_Pli(int commence) {
			std::vector<int> cles;
			for (auto& [cle, carte] : pli) {
				cles.push_back(cle);
			}
			for (int i = 0; i < (int)cles.size(); i++) {
				int index = (commence + i) % cles.size();
				pli.at(cles[index])->AfficherCarte(cout);
				cout << "joueur " << i <<endl;
			}
		}
};
#endif
