#include "Atom.h"
#include "PhysicsContsraints.h"

using std::to_string;

Atom::Atom(int protonNumber, int neutronNumber, int electroNumber)
	: protonNumber(protonNumber), neutronNumber(neutronNumber), electroNumber(electroNumber)
{
}

/*
*  Суммарная масса нуклонов и электронов = масса атома 
*/
double Atom::getMass()
{
	return ELECTRON_MASS * electroNumber + (protonNumber + neutronNumber) * NUCLEON_MASS;
}

double Atom::getElectronCharge()
{
	return -ELEMENTARY_CHARGE * electroNumber;
}

double Atom::getProtonNumber()
{
	return protonNumber;
}

string Atom::getConfiguration()
{
	return "Protons: " + to_string(protonNumber) + " Neutrons: " + to_string(neutronNumber) + " Electons: " + to_string(electroNumber);
}
