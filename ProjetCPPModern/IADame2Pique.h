#ifndef I_A_DAME2_PIQUE_H
#define I_A_DAME2_PIQUE_H

#include <iostream>
#include <vector>

#include "IA.h"


class IADame2Pique : public IA{
	protected:
		int nb_coeur;

		bool d2p;

	public:
		IADame2Pique(int num) {
			numero = num;
			points = 0;
			equipe = nullptr;
		}

		//On peut pas copier un joueur
		IADame2Pique(const IADame2Pique& autre) = delete;
		//On peut le déplacer
		IADame2Pique(IADame2Pique&& autre) noexcept = default;

		//On peut pas copier un joueur
		IADame2Pique& operator=(const IADame2Pique& autre) = delete;
		//On peut le déplacer
		IADame2Pique& operator=(IADame2Pique&& autre) noexcept = default;

		~IADame2Pique() = default;

		unique_ptr<Carte>& Jouer() override;
};
#endif
