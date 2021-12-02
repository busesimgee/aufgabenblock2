#include "Simulationsobjekt.h"

int Simulationsobjekt::p_iMaxID = 0;

Simulationsobjekt::Simulationsobjekt() : p_iID(p_iMaxID)
{
	p_iMaxID++;
}

Simulationsobjekt::Simulationsobjekt(string sName) : p_sName(sName), p_iID(p_iMaxID)
{
	p_iMaxID++;
}

Simulationsobjekt::~Simulationsobjekt()
{
	cout << "Name geloeschten Simulationsobject: " << p_sName << endl;
	cout << "ID geloeschen Simulationsobject: " << p_iID << endl;
}
void Simulationsobjekt::vAusgeben(ostream& o)const
{
	o << setiosflags(ios::left) << setw(9) << p_iID << setw(17) << p_sName;
}

ostream& operator<<(ostream& o, const Simulationsobjekt& simulationsobjekt)
{
	simulationsobjekt.vAusgeben(o);
	return o;
}

bool Simulationsobjekt::operator==(const Simulationsobjekt& simulationsobjekt)
{
	return(this->p_iID == simulationsobjekt.p_iID);
}

void Simulationsobjekt::vSimulieren()
{

}

string Simulationsobjekt::getName()
{
	return p_sName;
}