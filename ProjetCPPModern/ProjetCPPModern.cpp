#include <iostream>
#include <windows.h>
#include <locale>
#include <codecvt>
#include <stdlib.h>
using namespace std;

void testPaquet();
void testJoueur();
void testPli();

int main(){
    //Mettre en UTF8 pour affichage caractère spéciale
    if (!SetConsoleOutputCP(CP_UTF8) || !SetConsoleCP(CP_UTF8)) {
        cout << "Impossible d'afficher du Unicode";
        return 1;
    }
    /*Z
    //Création du Handle
    HANDLE hConsoleHandle = GetStdHandle(STD_INPUT_HANDLE);
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
            }
        }
    }
    SetConsoleMode(hConsoleHandle, dwMode);
    */    
    cout << "♠♣♦♥" << endl;
    //testJoueur();
    //testPli();
}


/*
While(verifier_points == -1){
    * int commencer = Commencer()

    for (i = 0; i < 13; i++){
        for (j = commencer ; j < nbjoueur; j++){
            
        }

        commencer Vainqueur();
    }
    Attribuer_points();
}

*/

/*
    Les events que l'on peut capter:
    KEY_EVENT_RECORD          KeyEvent;
    MOUSE_EVENT_RECORD        MouseEvent;
    WINDOW_BUFFER_SIZE_RECORD WindowBufferSizeEvent;
    MENU_EVENT_RECORD         MenuEvent;
    FOCUS_EVENT_RECORD        FocusEvent;
    */