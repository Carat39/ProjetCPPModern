#ifndef AFFICHAGE_H
#define AFFICHAGE_H 500

#include <iostream>
#include <string>
#include <memory>
#include <vector>


class Humain;   
class IA;

using namespace std;

class Affichage{
	public:
		static int DemanderValeurCarte();

		static string DemanderCouleurCarte();

		static int DemanderNbJoueurs(string Precision);

		static void Afficher_jeu_Humain(vector<Humain*>& vectJ);

		static void Afficher_jeu_IA(vector<IA*>& vectJ);

};


#endif
