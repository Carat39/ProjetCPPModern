#include "Joueur.h"
#include "PaquetD2P.h"
#include <array>
#include <iostream>
/*#include <windows.h>
#include <locale>
#include <codecvt>
#include <stdlib.h>*/
#include "Affichage.h"


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
    /*HANDLE hConsoleHandle = GetStdHandle(STD_INPUT_HANDLE);
    DWORD dwMode;
    GetConsoleMode(hConsoleHandle, &dwMode);
    SetConsoleMode(hConsoleHandle, ENABLE_EXTENDED_FLAGS | ENABLE_MOUSE_INPUT | ENABLE_PROCESSED_INPUT);

    //Le record des records
    INPUT_RECORD record;
    //Les events qu'on va capter
    DWORD events;

    //Position x et y de la souris
    SHORT posx = 0;
    SHORT posy = 0;
    WORD valkey = 0;
    //Faire un map des key
    while (true) {
        ReadConsoleInput(hConsoleHandle, &record, 1, &events);
        if (record.EventType == MOUSE_EVENT) {
            //On récupère les infos de la souris
            MOUSE_EVENT_RECORD mouse = record.Event.MouseEvent;
            if (mouse.dwEventFlags == MOUSE_MOVED) {
                cout << "dac";
                //Actualisation de la position de la souris
                posx = mouse.dwMousePosition.X;
                posy = mouse.dwMousePosition.Y;
                if (posx < 50 && posy < 50) {
                    cout << "ok \f\r";
                }
            }
        }
        if (record.EventType == KEY_EVENT) {
            KEY_EVENT_RECORD key = record.Event.KeyEvent;
            if (key.bKeyDown) {
                valkey = key.wVirtualScanCode;
                cout << valkey;
                Affichage::Afficher_jeu(list_joueurs);
            }
        }
    }
    SetConsoleMode(hConsoleHandle, dwMode);
    */

}