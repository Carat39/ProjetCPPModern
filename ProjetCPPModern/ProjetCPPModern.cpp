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
    //testJoueur();
    //testPli();
    //testWizard();
    testD2P();
    return 0;
}

/*
    Les events que l'on peut capter:
    KEY_EVENT_RECORD          KeyEvent;
    MOUSE_EVENT_RECORD        MouseEvent;
    WINDOW_BUFFER_SIZE_RECORD WindowBufferSizeEvent;
    MENU_EVENT_RECORD         MenuEvent;
    FOCUS_EVENT_RECORD        FocusEvent;
    */
