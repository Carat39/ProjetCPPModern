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
            // On récupère les clés (numéros de joueurs ayant joué), triées
            std::vector<int> cles;
            for (auto& [cle, carte] : pli) {
                cles.push_back(cle);
            }

            // On trouve la position de "commence" dans cles, ou le premier joueur >= commence
            auto it = std::lower_bound(cles.begin(), cles.end(), commence);
            int start = std::distance(cles.begin(), it);

            int n = cles.size();
            for (int i = 0; i < n; i++) {
                int index = (start + i) % n;
                int joueur = cles[index];
                pli.at(joueur)->AfficherCarte(cout);
                cout << "joueur " << joueur << endl;
            }
        }
};
#endif
