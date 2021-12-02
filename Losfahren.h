#pragma once
#include "Fahrausnahme.h"


class Losfahren:
	public Fahrausnahme
{
public:
	void vBearbeiten() override;
	virtual ~Losfahren();
	Losfahren(Fahrzeug& fahrzeug, Weg& weg);
};

