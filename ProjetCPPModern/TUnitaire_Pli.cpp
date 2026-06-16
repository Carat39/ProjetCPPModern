#include "Carte.h"
#include "Paquet.h"
#include "Joueur.h"
#include "PliD2P.h"
#include "Humain.h"
void testPli() {
	Paquet MonPaquet = Paquet("Paquets/Paquet52Cartes.txt");
	PliD2P MonPli(&MonPaquet);
	Humain Marandin = Humain(0);
	Humain Clement = Humain(1);
	Humain Thibault = Humain(2);
	Humain Nino = Humain(3);
	MonPaquet.Melanger();

	vector<Humain> list_joueurs;
	list_joueurs.push_back(move(Marandin));
	list_joueurs.push_back(move(Clement));
	list_joueurs.push_back(move(Thibault));
	list_joueurs.push_back(move(Nino));
	unsigned int index = 0;
	size_t taille = MonPaquet.taille();
	while (index < taille) {
		MonPaquet.Distribuer(list_joueurs[index % 4]);
		index++;
	}
	vector<unique_ptr<Carte>> laMano;
	for (Humain& joueur : list_joueurs) {
		laMano = joueur.getMain();
		MonPli.setCarte(joueur.getNumero(), move(laMano[0]));
		laMano.erase(laMano.begin());
		joueur.addMain(move(laMano));
	}
	cout  << MonPli.Calcul_points() <<endl ;
	MonPli.Vainqueur(0);
}