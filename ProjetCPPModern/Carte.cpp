#include "Carte.h"

Carte::Carte() {
	couleur = " ";
	valeur = -1;
}

Carte::Carte(string coul, int val) {
	couleur = coul;
	valeur = val;
}

Carte::Carte(Carte&& autre) noexcept {
	couleur = autre.couleur;
	valeur = autre.valeur;
}
