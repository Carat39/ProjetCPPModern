#ifndef AFFICHAGE_H
#define AFFICHAGE_H 500
#define NOMINMAX

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <windows.h>


class Humain;   
class IA;

using namespace std;

//Définitions des code ANSI pour l'affichage en couleur :
static string CSI(){
	return "\033[";
}
static string END_CSI() {
	return "\033[0m";
}
static string FG() {
	return "3";
}
static string BG() {
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
//ne peut pas clignoter for some reason...
static constexpr string DARK() {
	return ";2";
}
static constexpr string CLIGNOTE() {
	return ";5";
}
static constexpr string M() {
	return "m";
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

		static int Demander(string Precision);

		static int DemanderIndex(Humain* leJoueur, string couleurPli);

		static void Afficher_jeu_Humain(vector<Humain*>& vectJ);

		static void Afficher_jeu_IA(vector<IA*>& vectJ);

};


#endif
