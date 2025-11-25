#pragma once

#include <iostream>
#include <string>

class Fire;
class Water;
class Grass;

class Visitor
{
public :
	virtual void VisitFire(const Fire *ty) const = 0;
	virtual void VisitWater(const Water *ty) const = 0;
	virtual void VisitGrassC(const Grass *ty) const = 0;
};

class Type
{
public :
	virtual ~Type() {}
	virtual void Accept(Visitor* visitor) const = 0;
};

class Fire : public Type
{
public :
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

class Visitor1 : public Visitor 
{
public:
	void VisitFire(const Fire* som) const {
		std::cout << "visited" << som->FireFunc() << "from Visitor1\n";
	};
	void VisitWater(const Water* som) const {
		std::cout << "visited" << som->WaterFunc() << "from Visitor1\n";
	};
	void VisitGrass(const Grass* som) const {
		std::cout << "visited" << som->GrassFunc() << "from Visitor1\n";
	};
};

class Visitor2 : public Visitor
{
public:
	void VisitFire(const Fire* som) const {
		std::cout << "visited" << som->FireFunc() << "from Visitor2\n";
	};
	void VisitWater(const Water* som) const {
		std::cout << "visited" << som->WaterFunc() << "from Visitor2\n";
	};
	void VisitGrass(const Grass* som) const {
		std::cout << "visited" << som->GrassFunc() << "from Visitor2\n";
	};
};

class Visitor3 : public Visitor
{
public:
	void VisitFire(const Fire* som) const {
		std::cout << "visited" << som->FireFunc() << "from Visitor3\n";
	};
	void VisitWater(const Water* som) const {
		std::cout << "visited" << som->WaterFunc() << "from Visitor3\n";
	};
	void VisitGrass(const Grass* som) const {
		std::cout << "visited" << som->GrassFunc() << "from Visitor3\n";
	};
};
