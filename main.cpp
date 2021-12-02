#include"Fahrzeug.h"
#include"PKW.h"
#include"Fahrrad.h"
#include"Simulationsobjekt.h"
#include"Weg.h"
#include"Tempolimit.h"
#include<iostream>
#include<iomanip>
#include<random>
#include <map>
#include<memory>
#include<vector>
#include<cmath>
#include<string>
#include"SimuClient.h"

double dGlobaleZeit = 0.0;

using namespace std;
//double dEpsilon = 0.001;

//Testfunktion Aufgabe 1
/*void vAufgabe1()
{
	Fahrzeug f1;
	Fahrzeug f2;
	Fahrzeug* f3 = new Fahrzeug();
	Fahrzeug* f4 = new Fahrzeug();
	delete f3;
	delete f4;

	auto f5 = make_unique<Fahrzeug>();
	auto f6 = make_unique<Fahrzeug>("Smart");
	shared_ptr<Fahrzeug> f7 = make_shared<Fahrzeug>();
	auto f8 = make_shared<Fahrzeug>("Geteilter Smart");
	cout << f8.use_count() << endl;
	shared_ptr<Fahrzeug> f8_2 = f8;
	cout << f8.use_count() << endl;
	//auto f9 = make_unique<Fahrzeug>("Geteilter Smart");
	//cout << f9.use_count() << endl;
	//unique_ptr<Fahrzeug> f9_2 = f9;
	//cout << f9.use_count() << endl;
	vector<unique_ptr<Fahrzeug>> fVec;
	//fVec.push_back(move(f5));
	fVec.push_back(move(f6));
	fVec.clear();
	//Vektor mit sharedPtr
	//auto f10 = make_shared<Fahrzeug>("Shared 2");
	vector<shared_ptr<Fahrzeug>> fVecShared;
	//f7 vor pushback(ohne move)
	cout << f7.use_count() << endl;
	fVecShared.push_back(f7);
	cout << f7.use_count() << endl;
	cout << f8.use_count()<<endl;
	fVecShared.push_back(move(f8));
	cout << fVecShared.back().use_count() << endl;
	fVecShared.clear();

	Fahrzeug f9("PKW1", 40);
	Fahrzeug f10("Auto3", 30);

	Fahrzeug::vKopf();
	f9.vAusgeben();
	cout << endl;
	f10.vAusgeben();
	cout << endl << endl;
	//f1.vKopf();
	//cout << endl;
	//f1.vAusgeben();
	//cout << endl;
	//f2.vAusgeben();
	//cout << endl;
	//f6->vAusgeben();
	
}
void vAufgabe1a()
{
	vector<unique_ptr<Fahrzeug>> vec1a;
	for (int i = 1; i < 4; i++)
	{
		string sName;
		double dMaxGeschwindigkeit;
		cout << "Bitte Name und max. Geschwindigkeit des " << i << ". Fahrzeugs eingeben:"<< endl;
		cin >> sName;
		cin >> dMaxGeschwindigkeit;
		auto ka = make_unique<Fahrzeug>(sName, dMaxGeschwindigkeit);
		vec1a.push_back(move(ka));
	}
	for (int j=0; j<10; j++)
	{
		dGlobaleZeit += 0.20;
		cout << "aktuelle zeit: " << dGlobaleZeit << endl;
		Fahrzeug::vKopf();
		
		vec1a[0]->vKopf();
		cout << endl;
		for (int i = 0; i < 3; i++)
		{
			vec1a[i]->vSimulieren();
			vec1a[i]->vAusgeben();
			cout << endl;
		}
		cout << endl;
	}
}
void vAufgabe_AB1() {

	int l = 0; // Laufindex für gezielte AUsgabe
	vector<int> ausgabe{ 15 };
	double dTakt = 0.3;

	std::vector<unique_ptr<Fahrzeug>> vecFahrzeuge;
	vecFahrzeuge.push_back(make_unique <PKW>("Audi", 229, 9.6));
	vecFahrzeuge.push_back(make_unique <Fahrrad>("BMX", 24.7));
	for (dGlobaleZeit = 0; dGlobaleZeit < 10; dGlobaleZeit += dTakt)
	{
		auto itL = find(ausgabe.begin(), ausgabe.end(), l);
		if (itL != ausgabe.end()) {
			std::cout << std::endl << l << " Globalezeit = " << dGlobaleZeit << std::endl;
			Fahrzeug::vKopf();
		}

		for (int i = 0; i < vecFahrzeuge.size(); i++)
		{
			vecFahrzeuge[i]->vSimulieren();
			if (fabs(dGlobaleZeit - 3.0) < dTakt / 2)
			{
				vecFahrzeuge[i]->dTanken();
			}
			if (itL != ausgabe.end()) {
				std::cout << *vecFahrzeuge[i] << endl;
			}
		}
		l++;
	}
	char c;
	std::cin >> c;
}

void vAufgabe_2()
{
	vector<unique_ptr<Fahrzeug>> vec_2;
	cout << "Anzahl der zu erstellenden PKWs: ";
	int iAnzahl;
	cin >> iAnzahl;
	for (int i = 0; i < iAnzahl; i++)
	{
		cout << "Name, max. Geschwindigkeit, Verbrauch in l/100km und Tankvolumen des " << i
			<< ". Autos angeben: " << endl;
		string sName;
		double dMaxGeschwindigkeit, dVerbrauch, dTankvolumen;
		cin >> sName;
		cin >> dMaxGeschwindigkeit;
		cin >> dVerbrauch;
		cout << "Tankvolumen angeben? (j/n) \n";
		string sEingabe;
		cin >> sEingabe;
		if (sEingabe == "j")
		{
			cin >> dTankvolumen;
			vec_2.push_back(make_unique<PKW>(sName, dMaxGeschwindigkeit, dVerbrauch,
				dTankvolumen));
		}
		else
		{
			vec_2.push_back(make_unique<PKW>(sName, dMaxGeschwindigkeit, dVerbrauch));
		}
	}
	cout << "Anzahl der zu erstellenden Fahrräder: ";
	cin >> iAnzahl;
	for (int i = 0; i < iAnzahl; i++)
	{
		cout << "Name und max. Geschwindigkeit des " << i << ". Fahrrads eingeben: " << endl;
		string sName;
		double dMaxGeschwindigkeit;
		cin >> sName;
		cin >> dMaxGeschwindigkeit;
		vec_2.push_back(make_unique<Fahrrad>(sName, dMaxGeschwindigkeit));
	}
	bool bSchonGetankt = false;
	for (; dGlobaleZeit < 12; dGlobaleZeit += .5)
	{
		cout << endl;
		cout << "Aktuelle Zeit: " << dGlobaleZeit << endl;			   
		vec_2[0]->vKopf();
		cout << endl;
		for (unsigned int i = 0; i < vec_2.size(); i++)
		{
			vec_2[i]->vSimulieren();
			if (dGlobaleZeit >= 2.97 && bSchonGetankt == false)
			{
				vec_2[i]->dTanken();
			}
			vec_2[i]->vAusgeben(cout);
			cout << endl;
		}
		if (dGlobaleZeit >= 2.97) { bSchonGetankt = true; }
	}
}
void vAufgabe3()
{
	PKW a1("Hans", 100, 10);
	PKW a2("Otto", 200, 10);
	Fahrrad f1("dumm", 30);
	dGlobaleZeit = 2;
	a1.vSimulieren();
	a2.vSimulieren();
	f1.vSimulieren();
	(a1 > f1) ? cout << "> funktioniert." : cout << "Fehler bei >-Operator";
	cout << endl;
	(a1 < a2) ? cout << "< funktioniert." : cout << "Fehler bei <-Operator";
	cout << endl;
	a1.vKopf();
	cout << endl;
	cout << "Ausgabe von a1: " << a1 << endl;
	a2 = a1;
	cout << "Kopie von a1: " << a2 << endl;
}
*/
void vAufgabe_6()
{
	Weg weg1("Landstrasse", 200, 2);
	Weg weg2("Innenorts", 300, 1);
	weg1.vAnnahme(make_unique<PKW>("Mercedes", 1000, 6, 60));
	weg2.vAnnahme(make_unique<Fahrrad>("BMX", 25));
	weg1.vAnnahme(make_unique<PKW>("Audi", 1000, 6, 60),2);
	weg2.vAnnahme(make_unique<Fahrrad>("citybike", 25),4);
	cout << endl;
	for (int i = 0; i <= 10; i++)
	{
		dGlobaleZeit += 0.5;
		cout << "aktuelle zeit: " << dGlobaleZeit << endl;
		weg1.vSimulieren();
		weg2.vSimulieren();
		cout << weg1 << endl;
		cout << weg2 << endl;
	}
}
int main()
{
	//vAufgabe_AB1();
	vAufgabe_6();
	return 0;
}