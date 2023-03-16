#pragma once
#include <string>

using std::string;

class Atom
{
private:
	int protonNumber;
	int neutronNumber;
	int electroNumber;
	Atom(int protonNumber, int neutronNumber, int electroNumber);
public:
	double getMass();
	double getElectronCharge();
	double getProtonNumber();
	string getConfiguration();

	friend class AtomFactory;
};

