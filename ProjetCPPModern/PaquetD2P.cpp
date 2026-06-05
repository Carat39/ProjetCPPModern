#include "PaquetD2P.h"
#include <string>
#include <utility>
#include "Carte.h"


void PaquetD2P::retirer_carte(string coul, int val) {
	bool find = false;
	unsigned int index = 0;
	while (index < taille() && find == false) {
		if (lePaquet[index].get_couleur() == coul && lePaquet[index].get_valeur() == val) {
			Invalider_carte(move(lePaquet[index]));
			lePaquet.erase(lePaquet.begin()+index);
			find = true;
		}
		else {
			index++;
		}
	}

}

void PaquetD2P::Invalider_carte(Carte&& autre) noexcept {
	cartesEcartes.push_back(move(autre));
}