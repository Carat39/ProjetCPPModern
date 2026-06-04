#include "Joueur.h"
#include "PaquetD2P.h"
#include <array>

void testJoueur() {
	Joueur Clement = Joueur(1);
	Joueur Thibault = Joueur(2);
	Joueur Nino = Joueur(3);
	PaquetD2P MonPaquet = PaquetD2P();
	cout << "Mélange" << endl;
	MonPaquet.Melanger();
	MonPaquet.AfficherPaquet(cout);
	MonPaquet.retirer_carte("♦", 2);


	Joueur list_joueurs[] = {Clement,Thibault,Nino};
	unsigned int index = 0;
	while(index < MonPaquet.taille()) {
		MonPaquet.Distribuer(list_joueurs[index%3]);
		index++;
	}
	for (Joueur& joueur : list_joueurs) {
		joueur.AfficherMain(cout);
	}
}