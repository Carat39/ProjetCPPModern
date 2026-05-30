#include <iostream>
#include <windows.h>
#include <locale>
#include <codecvt>
using namespace std;

void testPaquet();

int main(){
    if (!SetConsoleOutputCP(CP_UTF8) || !SetConsoleCP(CP_UTF8)) {
        cout << "Impossible d'afficher du Unicode";
        return 1;
    }
    cout << "♠♣♦♥";
    testPaquet();
}


/*
While(verifier_points == -1){
    * int commencer = Commencer()

    for (i = 0; i < 13; i++){
        for (j = commencer ; j < nbjoueur; j++){
            
        }

        commencer Vainqueur;
    }
    Attribuer_points();
}

*/