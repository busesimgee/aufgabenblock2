#include "Fahrrad.h"
#include<cmath>

Fahrrad::Fahrrad() :Fahrzeug()
{

}

Fahrrad::~Fahrrad()
{

}

double Fahrrad::dGeschwindigkeit() const
{
	double dAktGeschwindigkeit = p_dMaxGeschwindigkeit * pow(.9, floor(p_dGesamtStrecke /20));

	return (dAktGeschwindigkeit >= 12) ? dAktGeschwindigkeit : 12;
}
Fahrrad::Fahrrad(string sName, double dMaxGeschwindigkeit) :Fahrzeug(sName, dMaxGeschwindigkeit)
{
} 