#include <iostream>
#include <stdexcept>
#include "Molecule.h"
#include "AtomFactory.h"

using std::cin;
using std::cout;
using std::endl;

void showInfo()
{
	cout << "0 - Exit" << endl;
	cout << "1 - Show current molecule configuration" << endl;
	cout << "2 - Add new atom" << endl;
	cout << "3 - Calculate interatomic energy" << endl;
	cout << "4 - Calculate molecule mass" << endl;
	cout << "5 - Show number of specific atoms" << endl;
	cout << "6 - Shufle" << endl;
}

int readNumberOfProtons()
{
	int n;
	cout << "Enter number of protons:" << endl;
	cin >> n;
	return n;
}

int main()
{
	Molecule* molecule = new Molecule();
	int action, n;
	showInfo();
	while (true)
	{
		cout << "Action: ";
		cin >> action;
		switch (action)
		{
		case 0:
			goto end;
		case 1:
			cout << "Configuration:" << endl;
			cout << molecule->getConfiguration() << endl;
			break;
		case 2:
			n = readNumberOfProtons();
			try
			{
				Atom* atom = AtomFactory::createAtom(n);
				molecule->addAtom(atom);
				cout << "Added" << endl;
			}
			catch (std::invalid_argument& e)
			{
				cout << e.what() << endl;
			}
			break;
		case 3:
			cout << "Energy: " << molecule->getEnergy() << endl;
			break;
		case 4:
			cout << "Mass: " << molecule->getMass() << endl;
			break;
		case 5:
			n = readNumberOfProtons();
			cout << "Number of this atoms: " << molecule->getAtomNumber(n) << endl;
			break;
		case 6:
			molecule->shuffleAtomPositions();
			cout << "Shuffled" << endl;
			break;
		default:
			showInfo();
			break;
		}
	}

end:
	Atom** atoms = molecule->getAtoms();
	for (int i=0; i< sizeof(atoms)/sizeof(Atom); i++)
	{
		delete atoms[i];
	}
	delete molecule;
}