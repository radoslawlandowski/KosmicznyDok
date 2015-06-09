#define LASERGUN "LaserGun"
#define SHIELD "Shield"
#define AFTERBURNER "Afterburner"
#define MACHINEGUN "MachineGun"
#define FLARES "Flares"
#define NAVIGATIONSYSTEM "NavigationSystem"
#define NOCTOVISION "Noctovision"
#define MISSILE "Missile"

class CoreOfShip /* a.k.a Command Module. The skeleton of the ship. It contains the slots */
{
private:
	std::vector< Slot* > *listOfSlots;
	Slot *leftWingSlot, *rightWingSlot, *interiorSlot, *bottomSlot, *frontSlot, *rearSlot;

public:
	CoreOfShip()
	{
		leftWingSlot = new Slot("Leftwing slot");						/* define the slot and restrict types of modules that can be attached to the slot */
		leftWingSlot->addAllowedModule(LASERGUN);
		leftWingSlot->addAllowedModule(MACHINEGUN);
		leftWingSlot->addAllowedModule(MISSILE);

		rightWingSlot = new Slot("Rightwing slot");
		rightWingSlot->addAllowedModule(LASERGUN);
		rightWingSlot->addAllowedModule(MACHINEGUN);
		rightWingSlot->addAllowedModule(MISSILE);

		interiorSlot = new Slot("Interrior slot");
		interiorSlot->addAllowedModule(NAVIGATIONSYSTEM);
		interiorSlot->addAllowedModule(NOCTOVISION);

		bottomSlot = new Slot("Bottom slot");
		bottomSlot->addAllowedModule(FLARES);

		frontSlot = new Slot("Front slot");
		frontSlot->addAllowedModule(LASERGUN);
		frontSlot->addAllowedModule(MACHINEGUN);
		frontSlot->addAllowedModule(SHIELD);

		rearSlot = new Slot("Rear slot");
		rearSlot->addAllowedModule(AFTERBURNER);

		listOfSlots = new std::vector < Slot* >;      /* get slots into a vector to keep them organised */
		listOfSlots->push_back(leftWingSlot);
		listOfSlots->push_back(rightWingSlot);
		listOfSlots->push_back(interiorSlot);
		listOfSlots->push_back(bottomSlot);
		listOfSlots->push_back(frontSlot);
		listOfSlots->push_back(rearSlot);

	}

	bool checkIfSlotEmpty(int slotNr)
	{
		return listOfSlots->at(slotNr)->checkIfEmpty();
	}

	void addModuleToSlot(Module *myModule, int slotNumber)
	{
		listOfSlots->at(slotNumber)->addModule(myModule);
		return;
	};

	void removeModule(int slotNumber)
	{
		listOfSlots->at(slotNumber)->removeModule();
		return;
	}

	std::string getDescriptionOfTheSlot(int slotNumber)
	{
		return listOfSlots->at(slotNumber)->getDescriptionOfTheSlot();
	}

	std::vector <std::string> *getAllowedModules(int slotNumber)
	{
		return listOfSlots->at(slotNumber)->getAllowedModules();
	}

	Module *getToModule(int slotNumber)
	{
		return listOfSlots->at(slotNumber)->getToModule();
	}

	std::string getAttachedModuleDescription(int slotNumber)
	{
		return listOfSlots->at(slotNumber)->getAttachedModuleDescription();
	}
};