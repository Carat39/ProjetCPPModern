#define _HAS_STD_BYTE 0
#include <iostream>
#include <windows.h>
#include <locale>
#include <codecvt>
#include <stdlib.h>
using namespace std;
#include "JeuD2P.h"

void testPaquet();
void testJoueur();
void testPli();
void testWizard();
void testD2P();

int main(){
    //Mettre en UTF8 pour affichage caractère spéciale
    if (!SetConsoleOutputCP(CP_UTF8) || !SetConsoleCP(CP_UTF8)) {
        cout << "Impossible d'afficher du Unicode";
        return 1;
    }



    
    cout << "♠♣♦♥" << endl;

	int jeu = -1;
    while (jeu != 0) {
        system("cls");
		jeu = Affichage::Demander("Vous voulez-jouer à quel jeu?\n0 Pour quitter \n1 Pour dame de Pique\n2 pour Wizard \n");
        if (jeu == 1) {
            system("cls");
            testD2P();
        }
        else if (jeu == 2){
            system("cls");
            testWizard();
        }
	}
    return 0;
}