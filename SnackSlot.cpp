#include "SnackSlot.h"


SnackSlot::SnackSlot(int const& numSlots)
{
	__currNum   = NULL;
	__numSnacks = numSlots;

	for (uint16_t i = 0; i < __numSnacks; ++i)
		__snacks.push_back(nullptr);
	
}

SnackSlot::SnackSlot(SnackSlot const& snackSlot)
{
	
	__numSnacks = snackSlot.__numSnacks;
	__currNum = snackSlot.__currNum;


	for (uint16_t i = 0; i < __numSnacks; ++i)
		__snacks.push_back(std::make_unique<Snack>());


	for (uint16_t i = 0, j = 0; i < snackSlot.__numSnacks; i++)
	{
		if (snackSlot.__snacks[i])
		{
			std::unique_ptr<Snack>newSnack(std::make_unique<Snack>());
			*newSnack = *snackSlot.__snacks[i];
			std::unique_ptr<Snack> oldSnack(std::move(__snacks[i]));
			__snacks[j] = std::move(newSnack);
			++j;
		}
		else
			__snacks[i] = nullptr;

	}
}

SnackSlot& SnackSlot::operator=(SnackSlot const& snackSlot)
{
	__numSnacks = snackSlot.__numSnacks;
	__currNum = snackSlot.__currNum;
	for (uint16_t i = 0, j = 0; i < snackSlot.__numSnacks; i++)
	{
		if (snackSlot.__snacks[i])
		{
			std::unique_ptr<Snack>newSnack(std::make_unique<Snack>());
			*newSnack = *snackSlot.__snacks[i];
			std::unique_ptr<Snack> oldSnack(std::move(__snacks[i]));
			__snacks[j] = std::move(newSnack);
			++j;
		}

	}
	return *this;
}

BOOLEAN SnackSlot::addSnack(std::unique_ptr<Snack> snack)
{
	if (__currNum >= __numSnacks)
		return false;

	for (uint16_t i = 0; i < __numSnacks; ++i)
	{
		if (!__snacks[i])
		{
			__snacks[i] = (std::move(snack));
			++__currNum;
			return true;

		}
	}

	return false;
}


BOOLEAN SnackSlot::addSnack(Snack* snack)
{
	if (__currNum >= __numSnacks)
		return false;

	for (uint16_t i = 0; i < __numSnacks; ++i)
	{
		if (!__snacks[i])
		{
			__snacks[i] = std::move(std::make_unique<Snack>(*snack));
			++__currNum;
			return true;
		}
	}

	return false;
}

int16_t SnackSlot::findSnack(Snack::SnackType const& type) const
{
	if (type < 0 || type > 3)
		throw Snack::UndefineType();

	for (uint16_t i = 0; i < __numSnacks; ++i)
	{
		if (__snacks[i] && __snacks[i]->getType() == type)
			return i;
	}
	return -1;
}


int16_t SnackSlot::findSnack(std::string const& name) const
{
	for (uint16_t i = 0; i < __numSnacks; ++i)
	{
		if (__snacks[i] && __snacks[i]->getName() == name)
			return i;
	}

	return -1;
}


std::unique_ptr<Snack> SnackSlot::popSnack(Snack::SnackType const& type)
{
	auto positon = findSnack(type);
	if (positon != -1)
	{
		--__currNum;
		return std::move(__snacks[positon]);
	}

	return nullptr;
}


std::unique_ptr<Snack> SnackSlot::popSnack(std::string const& name)
{
	auto positon = findSnack(name);
	if (positon != -1)
	{
		--__currNum;
		return std::move(__snacks[positon]);
	}

	return nullptr;
}

uint16_t SnackSlot::getEmptyPlacesCount() const
{
	return __numSnacks - __currNum;
}


uint16_t SnackSlot::getPlacesCount() const
{
	return __numSnacks;
}

std::ostream& operator<<(std::ostream& os, SnackSlot const& slot)
{
	for (int i = 0; i < slot.__numSnacks; ++i)
	{
		if (slot.__snacks[i] != nullptr)
			os << *slot.__snacks[i] << '\n';
	}
	return os;
}