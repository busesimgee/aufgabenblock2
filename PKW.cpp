#include "PKW.h"
#include "Fahrzeug.h"
#include"Verhalten.h"

#include <iomanip>
#include <iostream>

PKW::PKW() :Fahrzeug()
{

}

PKW::~PKW()
{

}



PKW::PKW(string sName, double dMaxGeschwindigkeit, double dVerbrauch, double dTankvolumen) :Fahrzeug(sName, dMaxGeschwindigkeit), p_dVerbrauch(dVerbrauch),p_dTankvolumen(dTankvolumen), p_dTankinhalt(dTankvolumen / 2)
{
}

double PKW::dTanken(double dMenge)
{
	double dFreierTank = p_dTankvolumen - p_dTankinhalt; //frei verfugbare platz im tank
	if (dMenge < 0)
	{
		return 0;
	}else if (dFreierTank > dMenge)
	{
		p_dTankinhalt += dMenge; //tankinhallt wird mit der menge ausgefullt
		return dMenge;
	}else//tankinhalt ist kleiner als zubefüllende menge
	{
	p_dTankinhalt += p_dTankvolumen;
	return dFreierTank;
	}
}
void PKW::vSimulieren()
{
	
	//Wenn der Tank nicht leer ist
	if (p_dTankinhalt > 0)
	{
		Fahrzeug::vSimulieren();
		double dTankverbrauch = (dGlobaleZeit - p_dZeit) * dGeschwindigkeit() * p_dVerbrauch / 100;
		p_dTankinhalt -= dTankverbrauch;
	
	}else
	{
	p_dZeit = dGlobaleZeit; //tankinhalt wird reduziert
	}
}
void PKW::vAusgeben(ostream& o) const //uberladen des ausgabeoperators
{
	Fahrzeug::vAusgeben(o);
	o << setw(20) << p_dGesamtStrecke * p_dVerbrauch / 100 << setw(25) << p_dTankinhalt << endl;
}
PKW& PKW::operator=(const PKW& a2)
{
	Fahrzeug::operator=(a2);
	return *this;
}

double PKW::dGeschwindigkeit()const
{
	Weg* weg = p_pVerhalten->getWeg();
	double limit = weg->getTempolimit();
	if (p_dMaxGeschwindigkeit > limit)
	{
		return limit;
	}
	else
	{
		return p_dMaxGeschwindigkeit;
	}
}
