#include "Machine.h"

int main()
{
	using std::cout;

	setlocale(LC_ALL, "rus");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 0xb);

	uint16_t slotCount = 5;
	Snack* bounty = new Snack("Bounty");
	Snack* snickers = new Snack("Snickers");
	SnackSlot* slot = new SnackSlot(10);
	slot->addSnack(bounty); 
	slot->addSnack(snickers);
	VendingMachine* machine = new VendingMachine(slotCount);
	machine->addSlot(slot);

	cout << machine->getEmptySlotsCount();
	delete machine;
	delete slot;
	delete snickers;
	delete bounty;


	CloseHandle(hConsole);

	return 0;
}