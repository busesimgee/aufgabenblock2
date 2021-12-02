#include "Losfahren.h"

void Losfahren::vBearbeiten()
{
	cout << "Name des Fahrzeuges in der die Ausnahme auftritt: " << p_pFahrzeug1.getName() << endl;
	cout << "Weg auf dem sich das Fahrzeug befindet: " << p_pWeg1.getName() << endl;
	cout << "Art der Ausnahme: Losfahren " << endl;

}

Losfahren::~Losfahren()
{

}

Losfahren::Losfahren(Fahrzeug& fahrzeug, Weg& weg) : Fahrausnahme(fahrzeug, weg)
{

}