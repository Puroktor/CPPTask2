#pragma once
#include <string>

using std::string;

class Atom
{
private:
	int protonNumber;
	int neutronNumber;
	int electronNumber;
	Atom(int protonNumber, int neutronNumber, int electronNumber);
public:
	double getMass();
	double getElectronCharge();
	int getProtonNumber();
	string toString();

	friend class AtomFactory;
};

