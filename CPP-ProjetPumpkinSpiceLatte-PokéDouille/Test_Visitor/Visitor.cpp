// Test du Design Pattern Visitor

#include <iostream>
#include <array>
#include "Visitor.h"

int main()
{
	std::array<const Type*, 3> types = {new Fire, new Water, new Grass};
	Visitor1 *v1 = new Visitor1;
	Visitor2 *v2 = new Visitor2;
	Visitor2 *v3 = new Visitor3;

	for (const Type* ty : types) 
	{
		ty->Accept(v1);
	}
	for (const Type* ty : types)
	{
		ty->Accept(v2);
	}
	for (const Type* ty : types)
	{
		ty->Accept(v3);
	}

	//cleanup
	for (const Type* ty : types) 
	{
		delete ty;
	}

	delete v1;
	delete v2;
	delete v3;

	return 0;
};
