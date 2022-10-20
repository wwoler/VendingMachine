#include "Snack.h"

Snack::Snack(std::string name)
{
	if (!name.compare("Milka"))
	{
		__name.assign(name);
		__calories = 500;
		__price    = 100;
		__type     = defineType(name);
	}
	else if (!name.compare("Bounty"))
	{
		__name.assign(name);
		__calories = 450;
		__price    = 90;
		__type     = defineType(name);
	}
	else if (!name.compare("Snickers"))
	{
		__name.assign(name);
		__calories = 475;
		__price    = 105;
		__type     = defineType(name);
	}
	else if (!name.compare("Mars"))
	{
		__name.assign(name);
		__calories = 550;
		__price    = 120;
		__type     = defineType(name);
	}
	else
		throw Snack::UndefineType();
}

Snack::Snack(SnackType ST)
{
	if (ST < 0 || ST > 3)
		throw UndefineType();
	
	switch (ST)
	{
	case Snack::Milka:
		__name.assign("Milka");
		__calories = 500;
		__price    = 100;
		__type     = SnackType(0);
		break;
	case Snack::Bounty:
		__name.assign("Bounty");
		__calories = 450;
		__price    = 90;
		__type     = SnackType(1);
		break;
	case Snack::Snickers:
		__name.assign("Snickers");
		__calories = 475;
		__price    = 105;
		__type     = SnackType(2);
		break;
	case Snack::Mars:
		__name.assign("Mars");
		__calories = 550;
		__price    = 120;
		__type     = SnackType(3);
		break;
	}
}



std::ostream& operator<<(std::ostream& os, Snack const& snack)
{
	os  << "Наименование: " << snack.__name     << '\n'
		<< "Цена: "         << snack.__price    << '\n'
		<< "Калории: "      << snack.__calories << '\n'
		<< "ID: "           << snack.__type     << '\n';
	   

	return os;
}

std::istream& operator>>(std::istream& is, Snack& snack)
{
	std::cout << "Наименование: "; is >> snack.__name;
	std::cout << "Цена: ";         is >> snack.__price;
	std::cout << "Калории: ";      is >> snack.__calories;
	snack.__type = snack.defineType(snack.__name);
	return is;
}


Snack& Snack::operator=(Snack const& snack)
{
	__name.assign(snack.__name);
	__price    = snack.__price;
	__calories = snack.__calories;
	__type     = snack.__type;
	return *this;
}


Snack::SnackType Snack::defineType(std::string str) const
{
	if (!str.compare("Milka"))
	{
		return SnackType(0);
	}
	else if (!str.compare("Bounty"))
	{
		return SnackType(1);
	}
	else if (!str.compare("Snickers"))
	{
		return SnackType(2);
	}
	else if (!str.compare("Mars"))
	{
		return SnackType(3);
	}
	throw UndefineType();
}

Snack::SnackType  Snack::getType() const
{
	return __type;
}

std::string Snack::getName() const
{
	return __name;
}