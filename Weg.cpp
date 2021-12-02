#include "Weg.h"
#include"Fahrzeug.h"

#include"Fahrausnahme.h"

using namespace std;

Weg::Weg() :Simulationsobjekt(), p_iTempolimit(3)
{

}

Weg::~Weg()
{

}

Weg::Weg(string sName, double Laenge, int iTempolimit) :Simulationsobjekt(sName), p_iTempolimit(iTempolimit), p_dLaenge(Laenge)
{

}

double Weg::getTempolimit()
{
	switch (p_iTempolimit)
	{
	case 1:
	{
		return double(Tempolimit::Innerorts);
		break;
	}
	case 2:
	{
		return double(Tempolimit::Landstrasse);
		break;
	}
	case 3:
	{
		return double(Tempolimit::Autobahn);
	}

	return;
	}
}

void Weg::vSimulieren()
{
	if (!p_pFahrzeuge.empty())
	{
		for (auto& it : p_pFahrzeuge)
		{
			try
			{
				it->vSimulieren();
			}
			catch (Fahrausnahme* fahrausnahme)
			{
				fahrausnahme->vBearbeiten();
				delete fahrausnahme;
			}
		}
	}
}

void Weg::vKopf()
{
	cout << setiosflags(ios::left) << setw(7) << "ID" << " | " << setw(15) << "Name" << " | " << setw(20) << "Laenge" << " | " << setw(30) << "Fahrzeuge" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------------------";

}

void Weg::vAusgeben(ostream& o)const
{
	Weg::vKopf();
	cout << endl;
	Simulationsobjekt::vAusgeben();
	o << setw(6) << ":" << setw(20) << p_dLaenge << "(";
	for (auto& it : p_pFahrzeuge)
	{
		o << *it << endl;
	}
	o << ")";
	cout << endl;
	cout << endl;
	Fahrzeug::vKopf();
	for (auto& it : p_pFahrzeuge)
	{
		o << *it << endl;
	}
}

double Weg::getLaenge()
{
	return p_dLaenge;
}

void Weg::vAnnahme(unique_ptr<Fahrzeug>pFahrzeug)
{
	pFahrzeug->vNeueStrecke(*this);
	p_pFahrzeuge.push_back(move(pFahrzeug));
}

void Weg::vAnnahme(unique_ptr<Fahrzeug>pFahrzeug, double dStartzeitpunkt)
{
	pFahrzeug->vNeueStrecke(*this, dStartzeitpunkt);
	p_pFahrzeuge.push_front(move(pFahrzeug));
}