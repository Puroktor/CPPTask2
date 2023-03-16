#include "AtomFactory.h"
#include <stdexcept>
#include <random>
#include <cmath>

using std::max;

Atom* AtomFactory::createAtom(int protonNumber)
{
	if (protonNumber <= 0 || protonNumber > 117)
		throw std::invalid_argument("Atom with such proton number doesn't exsist");

	// Создаем изотопы случайным образом
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> neuronDist(max(0, protonNumber - 3), protonNumber + 3);
	std::uniform_int_distribution<std::mt19937::result_type> electronDist(max(0, protonNumber-4), protonNumber + 4);

	return new Atom(protonNumber, neuronDist(rng), electronDist(rng));
}
