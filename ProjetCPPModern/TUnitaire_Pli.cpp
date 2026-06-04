#include "Carte.h"
#include "Paquet.h"
#include "Joueur.h"
#include "Pli_D2P.h"

void testPli() {
	Paquet MonPaquet = Paquet();
	Pli_D2P MonPli;
	/*Joueur MonJoueur(0);
	MonPli.setCarte(0,MonPaquet.Distribuer(MonJoueur));
	MonPli.setCarte(1,carte1);
	MonPli.setCarte(2,carte2);
	MonPli.setCarte(3,carte3);*/

	MonPli.Vainqueur<Paquet>(0, MonPaquet);
}