#include "Molecule.h"
#include "PhysicsContsraints.h"
#include <random>

using std::to_string;

/*
* If we calculate energy like in reality, we will write a dissertation :)
* Therefore, we will take into account only the force of interaction of electron shells according to the Coulomb law.
* Probably this was meant in the task.
*/
double Molecule::getEnergy()
{
    // shuffleAtomPositions(); - in real life atoms do move, but for the demonstration let's leave it like this
    double energy = 0;
    for (const auto& entry : atomToCoordinateMap)
    {
        for (const auto& anotherEntry : atomToCoordinateMap)
        {
            if (entry == anotherEntry)
                continue;
            double distance = entry.second->distanceTo(anotherEntry.second);
            if (distance != 0)
            {
                energy += COLUMB_COEFFICIENT * entry.first->getElectronCharge()
                    * anotherEntry.first->getElectronCharge() / (distance * distance);
            }
        }
    }
    return energy;
}

double Molecule::getMass()
{
    double mass = 0;
    for (const auto& entry : atomToCoordinateMap)
    {
        mass += entry.first->getMass();
    }
    return mass;
}

/*
* Atom type is defined by serial number in the periodic table.
* And it is equal to the number of protons.
*/
int Molecule::getAtomNumber(int protonNumber)
{
    int number = 0;
    for (const auto& entry : atomToCoordinateMap)
    {
        if (entry.first->getProtonNumber() == protonNumber)
            number++;
    }
    return number;
}

Coordinate* createNewRandomCoordinate()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, 1e7);

    double x = 1.0 / (dist(rng) - 1e7/2);
    double y = 1.0 / (dist(rng) - 1e7/2);
    double z = 1.0 / (dist(rng) - 1e7/2);
    return new Coordinate(x, y, z);
}

void Molecule::shuffleAtomPositions()
{
    for (auto& entry : atomToCoordinateMap)
        entry.second = createNewRandomCoordinate();
}

string Molecule::toString()
{
    string config = "";
    int i = 0;
    for (const auto& entry : atomToCoordinateMap)
        config += to_string(++i) + ": " + entry.first->toString() + "\n";
    return config;
}

Atom** Molecule::getAtoms()
{
    Atom** atoms = new Atom*[atomToCoordinateMap.size()];
    int i = 0;
    for (const auto& entry : atomToCoordinateMap)
    {
        atoms[i++] = entry.first;
    }
    return atoms;
}

void Molecule::addAtom(Atom* atom)
{
    Coordinate* newCoordinate = createNewRandomCoordinate();
    atomToCoordinateMap.insert({ atom, newCoordinate });
}

Molecule::~Molecule()
{
    for (const auto& entry : atomToCoordinateMap)
        delete entry.second;
}