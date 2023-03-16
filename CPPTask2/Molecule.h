#pragma once
#include "Atom.h"
#include "Coordinate.h"
#include <string>  
#include <map>

using std::string;
using std::map;

class Molecule
{
private:
	map<Atom*, Coordinate*> atomToCoordinateMap;
public:
	double getEnergy();
	double getMass();
	int getAtomNumber(int protonNumber);
	void shuffleAtomPositions();
	string toString();
	Atom** getAtoms();
	void addAtom(Atom* atom);
	~Molecule();
};

