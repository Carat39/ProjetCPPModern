#ifndef AFFICHAGE_H
#define AFFICHAGE_H 500

#include <iostream>
#include <string>
#include <memory>

#include "Joueur.h"
using namespace std;

//Définitions des code ANSI pour l'affichage en couleur :
static string CSI(){
	return "\033[";
}
static const string END_CSI() {
	return "\033[0m";
}
static constexpr string FG() {
	return "3";
}
static constexpr string BG() {
	return "4";
}
static constexpr string GREEN() {
	return "2";
}
static constexpr string BLUE() {
	return "4";
}
static constexpr string RED() {
	return "1";
}
static constexpr string MAGENTA() {
	return "5";
}
static constexpr string LIGHT() {
	return ";1";
}
static constexpr string DARK() {
	return ";2";
} //ne peut pas clignoter for some reason...
static constexpr string CLIGNOTE() {
	return ";5";
}


//Définitions de template de couleurs pour l'affichage d'une carte :
static string COEUR() {
	return CSI() + FG() + RED();
}
static string CARREAU() {
	return CSI() + FG() + BLUE();
}
static string PIQUE() {
	return CSI() + FG() + MAGENTA();
}
static string TREFLE() {
	return CSI() + FG() + GREEN();
}

class Affichage{
	public:
		static int DemanderValeurCarte();

		static string DemanderCouleurCarte();

		static int DemanderNbJoueurs(string Precision);

		static void Afficher_jeu(vector<Joueur>& vectJ);

};


#endif
