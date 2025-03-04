#include "pointers.h"

int add_integers(int lhs, int rhs)
{
	return lhs + rhs;
}

void add_integers2(int lhs, int rhs, int* result)
{
	if (result)
		*result = lhs + rhs;
}

void add_integers3(int lhs, int rhs)
{
	// Cannot be implemented as described
	rhs + lhs; // ?
}

void add_integers4(int* lhs, int rhs)
{
	if (lhs)
		*lhs += rhs;
}

unsigned int add_unsigned(unsigned int lhs, unsigned int rhs)
{
	return lhs + rhs;
}
