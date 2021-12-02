#pragma once
#include "Fahrzeug.h"
#include <limits>
#include<iomanip>


class PKW :
	public Fahrzeug
{
	protected :
	//Verbrauch l/100km
	double p_dVerbrauch = 0;
	//Tankvolumen in l
	double p_dTankvolumen = 0;
	//akt. Tankinhalt
	double p_dTankinhalt = 0;
public:
	//Konstruktor
	PKW();
	PKW(string sName, double dMaxGeschwindigkeit, double dVerbrauch, double dTankvolumen =55);
	virtual ~PKW();
	//Tanken. Optionale Eingabe: getankte Menge, sonst vollgetankt
	double dTanken(double dMenge = numeric_limits<double>::infinity()) override;
	//Simulationsfkt. Bleibt stehen, wenn Tank nicht ausreichend gefuellt
	void vSimulieren() override;
	//Ausgabefkt, zusaetzlich Gesamtverbrauch und akt. Tankinhalt
	void vAusgeben(ostream& o = cout) const override;
	//Zuweisungsoperator fuer PKWs
	PKW& operator=(const PKW& a2);
	double dGeschwindigkeit()const override;
};

