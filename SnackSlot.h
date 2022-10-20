#pragma once

#include "Snack.h"
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <memory>
#include <Windows.h>


class SnackSlot
{
public:
	friend std::ostream& operator<<(std::ostream& os, SnackSlot const& slot);
	SnackSlot& operator=(SnackSlot const& snackSlot);
	SnackSlot& operator=(SnackSlot const&&) noexcept = delete;
	BOOLEAN addSnack(std::unique_ptr<Snack> snack);
	BOOLEAN addSnack(Snack* snack);
	std::unique_ptr<Snack> popSnack(Snack::SnackType const& type);
	std::unique_ptr<Snack> popSnack(std::string const& name);
	int16_t findSnack(Snack::SnackType const& type) const;
	int16_t findSnack(std::string const& name) const;
	uint16_t getEmptyPlacesCount() const;
	uint16_t getPlacesCount() const;

private:
    uint16_t                               __numSnacks;
	uint16_t                               __currNum;
	std::vector<std::unique_ptr<Snack> >   __snacks;


public:
	SnackSlot() = default;
	SnackSlot(int const& numSnacks);
	SnackSlot(SnackSlot const& snackSlot);
	SnackSlot(SnackSlot const&&) noexcept = delete;
	~SnackSlot()
	{
	}
};
