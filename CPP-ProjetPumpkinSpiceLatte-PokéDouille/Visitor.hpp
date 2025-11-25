#pragma once

#include <iostream>
#include <string>

class Fire;
class Water;
class Grass;

class Visitor
{
public:
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
		return "Fire";
	};
};

class Water : public Type
{
public:
	virtual void Accept(Visitor* visitor) const override {
		visitor->VisitWater(this);
	};
	std::string WaterFunc() const {
		return "Water";
	};
};

class Grass : public Type
{
public:
	virtual void Accept(Visitor* visitor) const override {
		visitor->VisitGrass(this);
	};
	std::string GrassFunc() const {
		return "Grass";
	};
};

class VisitorFire : public Visitor
{
public:
	void VisitFire(const Fire* som) const {
		std::cout << "visited" << som->FireFunc() << "from Fire\n";
	};
	void VisitWater(const Water* som) const {
		std::cout << "visited" << som->WaterFunc() << "from Fire\n";
	};
	void VisitGrass(const Grass* som) const {
		std::cout << "visited" << som->GrassFunc() << "from Fire\n";
	};
};

class VisitorWater : public Visitor
{
public:
	void VisitFire(const Fire* som) const {
		std::cout << "visited" << som->FireFunc() << "from Water\n";
	};
	void VisitWater(const Water* som) const {
		std::cout << "visited" << som->WaterFunc() << "from Water\n";
	};
	void VisitGrass(const Grass* som) const {
		std::cout << "visited" << som->GrassFunc() << "from Water\n";
	};
};

class VisitorGrass : public Visitor
{
public:
	void VisitFire(const Fire* som) const {
		std::cout << "visited" << som->FireFunc() << "from Grass\n";
	};
	void VisitWater(const Water* som) const {
		std::cout << "visited" << som->WaterFunc() << "from Grass\n";
	};
	void VisitGrass(const Grass* som) const {
		std::cout << "visited" << som->GrassFunc() << "from Grass\n";
	};
};