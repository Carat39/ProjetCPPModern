#ifndef I_A_DAME2_PIQUE_H
#define I_A_DAME2_PIQUE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "IA.h"

template <class Jeu>
class IADame2Pique : public IA<Jeu>
{
private:
	int nb_coeur;

	bool d2p;

};
#endif
