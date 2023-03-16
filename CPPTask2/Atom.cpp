#include "Atom.h"
#include "PhysicsContsraints.h"

using std::to_string;

Atom::Atom(int protonNumber, int neutronNumber, int electronNumber)
	: protonNumber(protonNumber), neutronNumber(neutronNumber), electronNumber(electronNumber)
{
}

/*
*  Суммарная масса нуклонов и электронов = масса атома 
*/
double Atom::getMass()
{
	return ELECTRON_MASS * electronNumber + (protonNumber + neutronNumber) * NUCLEON_MASS;
}

double Atom::getElectronCharge()
{
	return -ELEMENTARY_CHARGE * electronNumber;
}

int Atom::getProtonNumber()
{
	return protonNumber;
}

string Atom::toString()
{
	return "Protons: " + to_string(protonNumber) + " Neutrons: " + to_string(neutronNumber) + " Electons: " + to_string(electronNumber);
}
