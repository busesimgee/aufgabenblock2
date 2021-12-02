#pragma once
#include "Verhalten.h"
#include "Losfahren.h"

class Parken:
	public Verhalten
{
public:
	virtual ~Parken();
	Parken(Weg& weg, double dStartzeitpunkt);
	virtual double dStrecke(Fahrzeug& aFzg, double dZeitIntervall) override;

private:
	double p_dStartzeitpunkt;
};

