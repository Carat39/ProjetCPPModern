#include "Affichage.h"
#include "Humain.h"
#include "IA.h"


int Affichage::DemanderValeurCarte() {
	int valeur = -1;
	cout << "Valeur carte: ";
	cin >> valeur;
	cin.ignore();
	if (cin.fail()) {
		cout << "\nArgument invalide !\n" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		valeur = -1;
	}
	if (valeur < 0 || valeur > 14) {
		valeur = -1;
	}
	return valeur;
}

string Affichage::DemanderCouleurCarte() {
	string schoix = " ";
	cout << "Couleur carte: ";
	getline(cin, schoix);
	return schoix;
}

int Affichage::Demander(string Precision) {
	int valeur = -1;
	cout << Precision;
	cin >> valeur;
	cin.ignore();
	if (cin.fail()) {
		cout << "\nArgument invalide !\n" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		valeur = -1;
	}
	return valeur; 
}

int Affichage::DemanderIndex() {
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
    bool fin = true;
    int indexcarte = 0;
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
                //Flèche du bas :
                case 80:
                    indexcarte += 1;
                    cout << "index carte : " << indexcarte <<endl;
                    break;
                //Flèche du haut :
                case 72:
                    indexcarte -= 1;
                    cout << "index carte : " << indexcarte << endl;
                    break;
                //Touche Entrée :
                case 28:
                    fin = false;
                    break;
                }
            }
        }
    }
    return indexcarte;
    SetConsoleMode(hConsoleHandle, dwMode);
}


void Affichage::Afficher_jeu_Humain(vector<Humain*>& vectJ) {
	for (Humain* joueur : vectJ) {
		joueur->AfficherMain(cout);
	}
}

void Affichage::Afficher_jeu_IA(vector<IA*>& vectJ) {
	for (IA* joueur : vectJ) {
		joueur->AfficherMain(cout);
	}
}

