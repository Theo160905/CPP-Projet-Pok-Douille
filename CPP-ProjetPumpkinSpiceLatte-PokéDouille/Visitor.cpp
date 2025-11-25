// Test du Design Pattern Visitor

#include <iostream>
#include <array>
#include "Visitor.hpp"

int main2()
{
	std::array<const Type*, 3> types = { new Fire, new Water, new Grass };
	VisitorFire* v1 = new VisitorFire;
	VisitorWater* v2 = new VisitorWater;
	VisitorGrass* v3 = new VisitorGrass;

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