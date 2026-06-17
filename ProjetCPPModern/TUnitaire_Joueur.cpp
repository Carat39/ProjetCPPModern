#define _HAS_STD_BYTE 0
#include "Joueur.h"
#include "PaquetD2P.h"
#include <array>
#include <iostream>
using namespace std;
#include <locale>
#include <codecvt>
#include <stdlib.h>
#include "Affichage.h"
#include <memory>
#include "Humain.h"
#include <utility>


void testJoueur() {
    Humain Clement = Humain(1);
    Humain Thibault = Humain(2);
    Humain Nino = Humain(3);
    PaquetD2P MonPaquet = PaquetD2P();
    cout << "Mélange" << endl;
    MonPaquet.Melanger();
    MonPaquet.AfficherPaquet(cout);
    MonPaquet.retirer_carte("♦", 2);


    vector<Humain*> list_joueurs;
    list_joueurs.push_back(move(&Clement));
    list_joueurs.push_back(move(&Thibault));
    list_joueurs.push_back(move(&Nino));
    unsigned int index = 0;
    while (index < MonPaquet.taille()) {
        MonPaquet.Distribuer(*list_joueurs[index % 3]);
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
    bool fin = true;
    while (fin) {
        ReadConsoleInput(hConsoleHandle, &record, 1, &events);
        if (record.EventType == MOUSE_EVENT) {
            //On récupère les infos de la souris
            MOUSE_EVENT_RECORD mouse = record.Event.MouseEvent;
            if (mouse.dwEventFlags == MOUSE_MOVED) {
                //Actualisation de la position de la souris
                posx = mouse.dwMousePosition.X;
                posy = mouse.dwMousePosition.Y;
            }
        }
        if (record.EventType == KEY_EVENT) {
            KEY_EVENT_RECORD key = record.Event.KeyEvent;
            if (key.bKeyDown) {
                valkey = key.wVirtualScanCode;
                cout << "valeur clavier " << valkey;
                switch (valkey) {
                case 1:
                    fin = false;
                    break;
                case 16:
                    Affichage::Afficher_jeu_Humain(list_joueurs);
                    break;
                case 25:
                    system("cls");
                }
            }
        }
    }
    SetConsoleMode(hConsoleHandle, dwMode);
    */

}