#include "Machine.h"


VendingMachine::VendingMachine(uint16_t const& num)
{
	__numSlots = num;
	__currNumSlots = 0;

	for (uint16_t i = 0; i < __numSlots; ++i)
		__snackSlots.push_back(nullptr);

}


std::unique_ptr<Snack> VendingMachine::popFromSlot(Snack::SnackType const& type)
{

	for (uint16_t i = 0; i < __numSlots; ++i)
	{
		if (!__snackSlots[i])
			continue;
		auto rez = __snackSlots[i]->popSnack(type);
		if (rez != nullptr)
		{
			return std::move(rez);
		}
	}
	return nullptr;
}

std::unique_ptr<Snack> VendingMachine::popFromSlot(std::string const& name)
{
	for (uint16_t i = 0; i < this->__numSlots; ++i)
	{
		if (!__snackSlots[i])
			continue;
		auto rez = __snackSlots[i]->popSnack(name);
		if (rez != nullptr)
		{
			return std::move(rez);
		}
	}
	return nullptr;
}

uint16_t VendingMachine::getEmptySlotsCount() const
{
	return __numSlots - __currNumSlots;
}

uint16_t VendingMachine::getSlotsCount() const
{
	return __numSlots;
}


BOOLEAN VendingMachine::addSlot(std::unique_ptr<SnackSlot>&& snackSlot)
{
	if (__currNumSlots >= __numSlots)
		return false;

	for (uint16_t i = 0; i < __numSlots; ++i)
	{
		if (!__snackSlots[i])
		{
			__snackSlots[__currNumSlots] = std::move(snackSlot);
			++__currNumSlots;
			return true;
		}
	}

}

BOOLEAN VendingMachine::addSlot(SnackSlot* snackSlot)
{
	if (__currNumSlots >= __numSlots)
		return false;

	for (uint16_t i = 0; i < __numSlots; ++i)
	{
		__snackSlots[i] = std::move(std::make_unique<SnackSlot>(*snackSlot));
		++__currNumSlots;
		return true;
	}
}


std::unique_ptr<SnackSlot> VendingMachine::popSlot(uint16_t const& num)
{
	if (num < 0 || num >= __numSlots)
		return nullptr;

	--__currNumSlots;
	return std::move(__snackSlots[num]);

}