#pragma once

#include <iostream>
#include <string>

/*
* J'ai essayé de faire à ce que chaques classes aient leurs scriptes.
* Mais je n'arrivais pas à ce que les classes puissent intéragir entre elles.
*/

class Fire;
class Water;
class Grass;
class Type;

class Visitor
{
public:
	virtual ~Visitor() {}
	virtual void VisitFire(const Fire* ty) const = 0;
	virtual void VisitWater(const Water* ty) const = 0;
	virtual void VisitGrass(const Grass* ty) const = 0;
};

class Type
{
public:
	virtual ~Type() {}
	virtual void Accept(Visitor* visitor) const = 0;
};

class Fire : public Type
{
public:
	virtual void Accept(Visitor* visitor) const override {
		visitor->VisitFire(this);
	};
	std::string FireFunc() const {
		return "Feu";
	};
};

class Water : public Type
{
public:
	virtual void Accept(Visitor* visitor) const override {
		visitor->VisitWater(this);
	};
	std::string WaterFunc() const {
		return "Eau";
	};
};

class Grass : public Type
{
public:
	virtual void Accept(Visitor* visitor) const override {
		visitor->VisitGrass(this);
	};
	std::string GrassFunc() const {
		return "Plante";
	};
};

class VisitorFire : public Visitor
{
public:
	void Visitor::VisitFire(const Fire* som) const {
		std::cout << "L'attaque n'etait pas tres efficace contre le type " << som->FireFunc() << "\n";
	};
	void Visitor::VisitWater(const Water* som) const {
		std::cout << "L'attaque n'etait pas tres efficace contre le type " << som->WaterFunc() << "\n";
	};
	void Visitor::VisitGrass(const Grass* som) const {
		std::cout << "L'attack etait tres efficace contre le type " << som->GrassFunc() << "\n";
	};
};

class VisitorWater : public Visitor
{
public:
	void Visitor::VisitFire(const Fire* som) const {
		std::cout << "L'attack etait tres efficace contre le type " << som->FireFunc() << "\n";
	};
	void Visitor::VisitWater(const Water* som) const {
		std::cout << "L'attaque n'etait pas tres efficace contre le type " << som->WaterFunc() << "\n";
	};
	void Visitor::VisitGrass(const Grass* som) const {
		std::cout << "L'attaque n'etait pas tres efficace contre le type " << som->GrassFunc() << "\n";
	};
};

class VisitorGrass : public Visitor
{
public:
	void Visitor::VisitFire(const Fire* som) const {
		std::cout << "L'attaque n'etait pas tres efficace contre le type " << som->FireFunc() << "\n";
	};
	void Visitor::VisitWater(const Water* som) const {
		std::cout << "L'attack etait tres efficace contre le type " << som->WaterFunc() << "\n";
	};
	void Visitor::VisitGrass(const Grass* som) const {
		std::cout << "L'attaque n'etait pas tres efficace contre le type " << som->GrassFunc() << "\n";
	};
};

class CheckTypes {
public:
	void CheckTypesMatchup(const Type* typePlayer,const Type* typeEnnemi);
};
