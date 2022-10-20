#pragma once
#include "SnackSlot.h"

class VendingMachine
{
public:
	VendingMachine& operator=(VendingMachine const&) = delete;
	VendingMachine& operator=(VendingMachine const&&) = delete;
	std::unique_ptr<Snack> popFromSlot(Snack::SnackType const& type);
	std::unique_ptr<Snack> popFromSlot(std::string const& name);
	std::unique_ptr<SnackSlot> popSlot(uint16_t const& num);
	BOOLEAN addSlot(std::unique_ptr<SnackSlot>&& snackSlot);
	BOOLEAN addSlot(SnackSlot* snackSlot);
	uint16_t getEmptySlotsCount() const;
	uint16_t getSlotsCount() const;

private:
	uint16_t                                   __numSlots;
	uint16_t                                   __currNumSlots;
	std::vector<std::unique_ptr<SnackSlot> >   __snackSlots;

public:
	VendingMachine() = default;
	VendingMachine(uint16_t const& num);
	VendingMachine(VendingMachine const&) = delete;
	VendingMachine(VendingMachine const&&) = delete;
	~VendingMachine()
	{
	}
};