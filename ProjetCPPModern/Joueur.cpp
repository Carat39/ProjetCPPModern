#include <iostream>
#include <vector>

#include "Joueur.h"


vector<Carte> Joueur::getMain(){
	return main;
}

int Joueur::getNumero(){
	return numero;
}

int Joueur::getPoints(){
	return points;
}

void Joueur::addPoints(int nbPoints){
}

void Joueur::addCarte(Carte laCarte) {
	main.push_back(move(laCarte));
}

void Joueur::addMain(vector<Carte> lesCartes){
	for (Carte& laCarte : lesCartes) {
		addCarte(move(laCarte));
	}
}

void Joueur::supprMain(Carte laCarte){
}

void Joueur::Jouer(){
}

bool Joueur::Trouver_carte(string coul, int val){
	
}
