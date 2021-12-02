#pragma once
#include "Simulationsobjekt.h"
#include<list>
#include<memory>
#include"Tempolimit.h"

using namespace std;
class Fahrzeug;
class Fahrausnahme;

class Weg :
	public Simulationsobjekt
{
public:
	Weg(); //standartkonstruktor
	Weg(string sName, double Laenge, int iTempolimit = 3);
	virtual ~Weg();
	double getTempolimit();
	void vSimulieren();
	static void vKopf();
	void vAusgeben(ostream& o = cout)const override;
	double getLaenge();
	void vAnnahme(unique_ptr<Fahrzeug>pFahrzeug);
	void vAnnahme(unique_ptr<Fahrzeug>pFahrzeug, double dStartzeitpunkt);

private:
	double p_dLaenge = 0;
	list < unique_ptr<Fahrzeug>>p_pFahrzeuge; //sich aktuell auf dem Weg befinden
	Tempolimit p_eTempolimit; //maximal zulässige Geschwindigkeit
	const int p_iTempolimit;
};

