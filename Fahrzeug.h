#pragma once
#include<string>
#include<iostream>
#include<iomanip>
#include"Weg.h"
#include"Simulationsobjekt.h"


class Verhalten;
class Parken;
class Fahren;
extern double dGlobaleZeit;

using namespace std;

class Fahrzeug:public Simulationsobjekt
{
/*private:
	//Statische Variable: Maximal vergebene ID
	static int p_iMaxID;*/
protected:
	
	string p_sName = " ";  //Name des Fahrzeugs
	//Eindeutige ID
	//const int p_iID = 0; 
	double p_dMaxGeschwindigkeit = 0;//Maximalgeschwindigkeit
	
	double p_dGesamtStrecke = 0;//bisher zurueckgelegte Gesamtstrecke

	double p_dGesamtZeit = 0;	//gesamte Fahrzeit
	
	//double p_dZeit = 0;//letzte Simulationszeit

	double p_dAbschnittStrecke = 0;
	double p_dStreckeGefahren = 0;

	unique_ptr<Verhalten>p_pVerhalten;

public:
	
	Fahrzeug();//Standardkonstruktor
	
	Fahrzeug(string sName);//Konstruktor, Name als Eingabe, hochzählende ID
	
	Fahrzeug(string sName, double dMaxGeschwindigkeit);//Konstruktor, Name als Eingabe, hochzählende ID, Maximalgeschwindigkeit
	
	virtual ~Fahrzeug();//Destruktor
	
	virtual void vAusgeben(ostream& o = cout) const;//Ausgabefunktion
	
	static void vKopf();//Static Ausgabefunktion Tabellenkopf
	
	virtual void vSimulieren();//Simulationsfkt
	
	virtual double dTanken(double dMenge = numeric_limits<double>::infinity());//Tanken. Falls kein PKW, wird nichts getankt gibt die betänkte menge zuruck
	
	virtual double dGeschwindigkeit() const;//gibt aktuelle Geschwindigkeit an
	
	bool operator<(Fahrzeug& f2) const;//Kleiner-Operator fuer Fahrzeuge. True falls Gesamtstrecke kleiner ist

	//bool operator>(Fahrzeug& f2) const;//Groesser-Operator fuer Fahrzeuge. True falls Gesamtstrecke groesser ist

	Fahrzeug(const Fahrzeug&) = delete;	//Copy-Konstruktor verbieten
	
	virtual Fahrzeug& operator=(const Fahrzeug& f2);//Zuweisungsoperator fuer Fahrzeuge. Uebertraegt nur Stammdaten (Name, Maximalgeschwindigkeit)

	void vNeueStrecke(Weg& weg);
	void vNeueStrecke(Weg& weg, double dStartzeitpunkt);
	double getAbschnittStrecke();
};
//ostream& operator<<(ostream& o, const Fahrzeug&);
