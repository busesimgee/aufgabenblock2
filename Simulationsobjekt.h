#pragma once
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;

class Simulationsobjekt
{
public:
	Simulationsobjekt();
	Simulationsobjekt(string sName);
	virtual ~Simulationsobjekt();
	Simulationsobjekt(const Simulationsobjekt&) = delete;
	virtual void vAusgeben(ostream& o = cout)const;
	bool operator==(const Simulationsobjekt& simulationsobjekt);
	virtual void vSimulieren() = 0;
	string getName();

protected:
	string p_sName = ""; //Name of Fahrzeug
	const int p_iID;
	double p_dZeit = 0;


private:
	static int p_iMaxID;



};

ostream& operator <<(ostream& o, const Simulationsobjekt& simulationsobjekt);

