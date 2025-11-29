// Script pour le Design Pattern Visitor

//#include <iostream>
#include <array>
#include <iostream>
#include "Visitor.hpp"

void CheckTypes::CheckTypesMatchup(const Type* typePlayer, const Type* typeEnnemi) {
	std::array<const Type*, 1> types = { typeEnnemi };
	VisitorFire* vF = new VisitorFire;
	VisitorWater* vW = new VisitorWater;
	VisitorGrass* vG = new VisitorGrass;

	if (typeid(*(typePlayer)) == typeid(*(new Fire))) {
		for (const Type* ty : types)
		{
			return ty->Accept(vF);
		}
	};
	if (typeid(*(typePlayer)) == typeid(*(new Water))) {
		for (const Type* ty : types)
		{
			return ty->Accept(vW);
		}
	};
	/*Je ne sait pas pourquoi ca ne marche pas.
	if (typeid(*(typePlayer)) == typeid(*(new Grass))) {
		for (const Type* ty : types)
		{
			return ty->Accept(vG);
		}
	};
	*/

	//Pour nettoyer
	for (const Type* ty : types)
	{
		delete ty;
	}

	delete vF;
	delete vW;
	delete vG;
	
	/* Marche pas car ca ne fait que dire vrai.
	bool operator==( Type* typePlayer, Fire); {
		
	};
	bool operator==(Type* typePlayer, Water); {
		
	};
	bool operator==(Type* typePlayer, Grass); {
		
	};
	*/
	/*
	if (typePlayer == new Type ty)
	{
		typePlayer->Accept(v1);
	}
	if (typePlayer == new Water)
	{
		typePlayer->Accept(v2);
	}
	if (typePlayer == new Grass)
	{
		typePlayer->Accept(v3);
	}
	*/
};

//Test pour le Design Pattern Visitor
/*
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
*/