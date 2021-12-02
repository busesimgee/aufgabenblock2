#pragma once
#include "Weg.h"
#include"Fahrzeug.h"

class Verhalten
{
public:
	virtual ~Verhalten();
	Verhalten(Weg& weg);
	virtual double dStrecke(Fahrzeug& aFzg, double dZeitIntervall);
	Weg* getWeg()const;

protected:
	Weg* p_pWeg;
};

