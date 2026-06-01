#include "Paquet.h"
#include <iostream>

void testPaquet() {
	Paquet MonPaquet = Paquet();
	MonPaquet.AfficherPaquet();
	cout << "Mélange" << endl;
	MonPaquet.Melanger();
	MonPaquet.AfficherPaquet();
}