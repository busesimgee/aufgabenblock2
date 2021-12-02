#include "Fahren.h"


Fahren::Fahren(Weg& weg) :Verhalten(weg)
{
	 
}

Fahren::~Fahren()
{

}

double Fahren::dStrecke(Fahrzeug& aFzg, double dZeitIntervall)
{
	if (p_pWeg->getLaenge() > aFzg.getAbschnittStrecke())
	{
		double dMoeglicheStrecke = dZeitIntervall * aFzg.dGeschwindigkeit();
		double dAbstandStrecke = p_pWeg->getLaenge() - aFzg.getAbschnittStrecke();
		if (dMoeglicheStrecke <= dAbstandStrecke)
		{
			return dMoeglicheStrecke;
		}
		return dAbstandStrecke;
	}
	else
	{
		cout << " " << aFzg.getName() << "ist am Ende des Weges angekommen" << endl;
		Streckenende* streckenende = new Streckenende(aFzg, *p_pWeg);
		throw streckenende;
	}

}
