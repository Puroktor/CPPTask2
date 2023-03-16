#pragma once
#include "Atom.h"

class AtomFactory
{
public:
	static Atom* createAtom(int protonNumber);
};
