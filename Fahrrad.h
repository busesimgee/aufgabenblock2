#pragma once
#include "Fahrzeug.h"


// Die Fahrrad-Klasse bildet ein manuell angetriebenes Fahrrad ab. Abgeleitet von Fahrzeug.
class Fahrrad : 
	public Fahrzeug
{
	protected :

public:
	//aktuelle Geschwindigkeit, sinkt um 10% pro 20km
	double dGeschwindigkeit() const override;
	//Konstruktor
	Fahrrad();
	virtual ~Fahrrad();
	Fahrrad(string sName, double dMaxGeschwindigkeit);
	double dGeschwindigkeit() const override;

};


