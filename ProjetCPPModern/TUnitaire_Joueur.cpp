#include "Joueur.h"
#include "Paquet.h"
#include <array>

void testJoueur() {
	Joueur Clement = Joueur(1);
	Joueur Thibault = Joueur(2);
	Joueur Nino = Joueur(3);
	Joueur J4 = Joueur(4);
	Paquet MonPaquet = Paquet();
	cout << "Mélange" << endl;
	MonPaquet.Melanger();
	MonPaquet.AfficherPaquet();
	Joueur list_joueurs[] = {Clement,Thibault,Nino,J4};
	unsigned int index = 0;
	while(index < 52) {
		MonPaquet.Distribuer(list_joueurs[index%4]);
		index++;
	}
	for (Joueur& joueur : list_joueurs) {
		joueur.AfficherMain(cout);
	}
}