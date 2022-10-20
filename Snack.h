#pragma once
#include <string>
#include <iostream>

class Snack
{
public:
	enum SnackType
	{
		Milka = 0,
		Bounty,
		Snickers,
		Mars,
	};

	class UndefineType {};

	friend std::ostream& operator<<(std::ostream& os, Snack const& snack);
	friend std::istream& operator>>(std::istream& is, Snack& snack);
	Snack& operator=(Snack const& snack);

	SnackType getType() const;
	std::string getName() const;


private:
	std::string         __name;
	float               __price;
	float               __calories;
	SnackType           __type;

	SnackType defineType(std::string str) const;


public:
	Snack() = default;
	Snack(std::string name);
	Snack(SnackType ST);

	Snack(std::string name, float price, float calories) :
		__name(name), __price(price), __calories(calories),
		__type(defineType(name)) {}

	Snack(Snack const& snack) :
		__name(snack.__name), __price(snack.__price),
		__calories(snack.__calories),
		__type(defineType(snack.__name)) {}


};