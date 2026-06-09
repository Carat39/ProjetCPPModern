#define _HAS_STD_BYTE 0
#include <iostream>
#include <windows.h>
#include <locale>
#include <codecvt>
#include <stdlib.h>
using namespace std;
#include "Dame2Pique.h"

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
    /*cout << "\033[31;4mRouge souligné\033[0m" << endl;
    cout << "\033[31;42mRouge + fond vert\033[0m" << endl;
    cout << "\033[35;1;5mMagenta clignotant\033[0m" << endl;*/
    //testJoueur();
    //testPli();
    //testWizard();
    testD2P();
}

/*
    Les events que l'on peut capter:
    KEY_EVENT_RECORD          KeyEvent;
    MOUSE_EVENT_RECORD        MouseEvent;
    WINDOW_BUFFER_SIZE_RECORD WindowBufferSizeEvent;
    MENU_EVENT_RECORD         MenuEvent;
    FOCUS_EVENT_RECORD        FocusEvent;
    */
