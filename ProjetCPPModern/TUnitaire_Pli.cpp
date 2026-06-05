#include "Carte.h"
#include "Paquet.h"
#include "Joueur.h"
#include "Pli_D2P.h"

void testPli() {
	Paquet MonPaquet = Paquet();
	Pli_D2P MonPli;
	Joueur MonJoueur(0);
	Joueur Clement = Joueur(1);
	Joueur Thibault = Joueur(2);
	Joueur Nino = Joueur(3);
	MonPaquet.Melanger();

	Joueur list_joueurs[] = { Clement,Thibault,Nino };
	unsigned int index = 0;
	while (index < MonPaquet.taille()) {
		MonPaquet.Distribuer(list_joueurs[index % 3]);
		index++;
	}
	index= 0;
	vector<Carte> laMano;
	for (Joueur& joueur : list_joueurs) {
		laMano= joueur.getMain();
		MonPli.setCarte(index, laMano[index]);
		index++;
	}

	MonPli.Vainqueur<Paquet>(0, MonPaquet);
	cout << endl << MonPli.Calcul_points();
}