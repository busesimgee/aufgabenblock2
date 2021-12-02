#include "Streckenende.h"

Streckenende::~Streckenende()
{

}

Streckenende::Streckenende(Fahrzeug& fahrzeug, Weg& weg) : Fahrausnahme(fahrzeug, weg)
{

}

void Streckenende::vBearbeiten()
{
	cout << "Name des Fahrzeuges in der die Ausnahme auftritt: " << p_pFahrzeug1.getName() << endl;
	cout << "Weg auf dem sich daas Fahrzeug befindet: " << p_pWeg1.getName() << endl;
	cout << "Art der Ausnahme: Streckenende" << endl;

}