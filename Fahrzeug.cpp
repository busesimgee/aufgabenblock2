#include "Fahrzeug.h"
#include "Verhalten.h"
#include "Fahren.h"
#include"Parken.h"
#include"PKW.h"
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
/*
Initialsierung des Id zählers
*/
//int Fahrzeug::p_iMaxID = 0;

Fahrzeug::Fahrzeug():Simulationsobjekt()
{
	cout << "Default Konstruktor" << endl << "Name des Fahrzeugs: " << p_sName << endl <<
		"ID: " << p_iID << endl << endl;
}
Fahrzeug::Fahrzeug(string sName) : Simulationsobjekt(sName) //die maximal vergebene ID um einen erhöht
{
	
	cout << "Konstruktor" << endl << "Name des Fahrzeugs: " << p_sName << endl << "ID: " <<
		p_iID << endl << endl;
}
Fahrzeug::Fahrzeug(string sName, double dMaxGeschwindigkeit) : Simulationsobjekt(sName), p_dMaxGeschwindigkeit((dMaxGeschwindigkeit > 0) ? dMaxGeschwindigkeit : 0)
{
	
	cout << "dekonstruktor." << endl << "Name des Fahrzeugs: " << p_sName << endl << "ID: " <<p_iID << endl << endl;
}
Fahrzeug::~Fahrzeug()
{
	cout << "Destruktor." << endl << "Name des geloeschte Fahrzeugs: " << p_sName << endl << "ID: " <<
		p_iID << endl << endl;
}
void Fahrzeug::vAusgeben(ostream& o) const
{
	o << setiosflags(ios::left) << setw(4) << p_iID << setw(15) << p_sName << setw(20) << p_dMaxGeschwindigkeit << setw(20) << p_dGesamtStrecke
		<< setw(30) << dGeschwindigkeit();
}
void Fahrzeug::vKopf()
{
	cout << setiosflags(ios::left) << setw(4) << "ID" << setw(15) << "Name" << setw(20) << "Max. Geschwindigkeit" <<
		setw(20) << "Gesamtstrecke" << setw(30) << "akt. Geschwindigkeit" << setw(20)
		<< "Gesamtverbrauch" << setw(20) << "akt. Tankinhalt" << endl;
	cout <<
		"---------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}
void Fahrzeug::vSimulieren()
{
	if (dGlobaleZeit > p_dZeit) //zeit hat sich verändert, bewegung
	{
		double dZeitdifferenz = dGlobaleZeit - p_dZeit; // past time
		//p_dStreckeGefahren = p_pVerhalten->dStrecke(*this, dZeitdifferenz);

		p_dGesamtStrecke += dZeitdifferenz * dGeschwindigkeit(); //weg=zeit*geschwindigkeit
		p_dGesamtZeit += dZeitdifferenz; //zeit anpassuing
		p_dZeit = dGlobaleZeit; //aktuelle zeit
	}
}
double Fahrzeug::dTanken(double dMenge)
{
	return 0.0;
}
double Fahrzeug::dGeschwindigkeit() const
{
	return p_dMaxGeschwindigkeit;
}
bool Fahrzeug::operator<(Fahrzeug& f2) const //überladen  < operator
{
	return (this->p_dGesamtStrecke < f2.p_dGesamtStrecke);
}
/*bool Fahrzeug::operator>(Fahrzeug& f2) const //uberladen 
{
	return (this->p_dGesamtStrecke > f2.p_dGesamtStrecke) ? true : false;
}
void Fahrzeug::operator=(const Fahrzeug& f2)
{
	p_sName = f2.p_sName;
	p_dMaxGeschwindigkeit = f2.p_dMaxGeschwindigkeit;
}*/
Fahrzeug& Fahrzeug::operator=(const Fahrzeug& f2)
{
	p_sName = f2.p_sName;
	p_dMaxGeschwindigkeit = f2.p_dMaxGeschwindigkeit;

	return *this;
}
void Fahrzeug::vNeueStrecke(Weg& weg)
{
		//p_pVerhalten = new Fahren(weg);
	p_pVerhalten = make_unique<Fahren>(weg);
	p_dAbschnittStrecke = 0;
}

double Fahrzeug::getAbschnittStrecke()
{
	return p_dAbschnittStrecke;
}

void Fahrzeug::vNeueStrecke(Weg& weg, double dStartzeitpunkt)
{
	//p_pVerhalten = new Parken(weg, dStartzeitpunkt);
	p_pVerhalten = make_unique<Parken>(weg, dStartzeitpunkt);
	p_dAbschnittStrecke = 0;
}

ostream& operator<<(ostream& o, const Fahrzeug& f2)//Ueberladung des <<-Operators fuer Fahrzeuge
{
	f2.vAusgeben(o);
	return o;
}
