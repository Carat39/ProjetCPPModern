#include "Carte.h"
#include "Pli_D2P.h"

void testPli() {
	Carte carte0= Carte("♥", 4);
	Carte carte1= Carte("♥", 10);
	Carte carte2 = Carte("♠", 12);
	Carte carte3 = Carte("♣", 13);
	Pli_D2P MonPli;
	MonPli.setCarte(0,carte0);
	MonPli.setCarte(1,carte1);
	MonPli.setCarte(2,carte2);
	MonPli.setCarte(3,carte3);

	MonPli.Vainqueur(0);
}