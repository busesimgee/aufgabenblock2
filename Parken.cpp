#include "Parken.h"

Parken::~Parken()
{

}

Parken::Parken(Weg& weg, double dStartzeitpunkt): Verhalten(weg),p_dStartzeitpunkt
{

}

double Parken::dStrecke(Fahrzeug& aFzg, double dZeitInterval)
{
	if (dGlobaleZeit >= p_dStartzeitpunkt)
	{
		cout << " " << aFzg.getName() << " hat Startzeitpunkt erreicht" << endl;
		Losfahren* losfahren = new Losfahren(aFzg, *p_pWeg);
		throw losfahren;
	}
	else
	{
		return;
	}
}