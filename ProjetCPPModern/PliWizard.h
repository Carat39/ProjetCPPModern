#ifndef PLIWIZARD_H
#define PLIWIZARD_H 720

#include "Pli.h"

class PliWizard:public Pli{
	public:
		PliWizard(Paquet* paquet);

		virtual int Vainqueur(int premier_j, string couleurAtout);
};

#endif

