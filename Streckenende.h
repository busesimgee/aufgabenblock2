#pragma 
#include "Fahrausnahme.h"


class Streckenende:
	public Fahrausnahme
{
public:
	void vBearbeiten() override;
	virtual ~Streckenende();
	Streckenende(Fahrzeug& fahrzeug, Weg& weg);
};

