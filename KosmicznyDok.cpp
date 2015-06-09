// KosmicznyDok.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <time.h>
#include "Module.h"
#include "SpecificModules.h"
#include "Slot.h"
#include "CoreOfShip.h"
#include "SpecificBuilders.h"
#include "Parking.h"
#include "Magazine.h"
#include "Dock.h"

using namespace std;

#define LASERGUN "LaserGun"
#define SHIELD "Shield"
#define AFTERBURNER "Afterburner"
#define MACHINEGUN "MachineGun"
#define FLARES "Flares"
#define NAVIGATIONSYSTEM "NavigationSystem"
#define NOCTOVISION "Noctovision"
#define MISSILE "Missile"

#define NOMODULEBEINGMADE -1

#define NUMBEROFMODULESINMAGAZINEINITIALLY 5
#define NROFMODULESINITIALLY 10

#define NUMBEROFSLOTS 6

#define LEFTWINGSLOT 0
#define RIGHTWINGSLOT 1
#define INTERIORSLOT 2
#define BOTTOMSLOT 3
#define FRONTSLOT 4
#define REARSLOT 5

#define ATTACH 1
#define DISATTACH 2
#define ACTIVATE 3
#define DISACTIVATE 4

class Workshop
{
private:
	ModuleBuilder *builder;

	std::vector< ModuleBuilder* > listOfModuleBuilders;
	std::vector< Dock* > listOfDocks;
	std::vector< Order* > listOfOrders;

	Magazine *magazine;
	Parking *parking;

	bool isAnyDockFree;

	int lookForUnusedDock()
	{
		int aux = 0;
		for (int aux = 0; aux < listOfDocks.size(); aux++)
		{
			if (!listOfDocks.at(aux)->checkIfBusy())
			{
				return aux;
			}
			
		}
 
		return -1;
	}

	int assignTaskToDocks(Order *myOrder)
	{
		int chosenDock;
		chosenDock = lookForUnusedDock();
		if (chosenDock == -1)
		{
			cout << endl << "All docks Busy" << endl;
			listOfOrders.push_back(myOrder);
			return -1;
		}

		listOfDocks.at(chosenDock)->getToModyfing(myOrder);
		return chosenDock;
	}


public:
	Workshop(Magazine *myMag, Parking *myPark)
	{
		builder = new LaserGunBuilder();

		magazine = myMag;
		parking = myPark;

		LaserGunBuilder *laserBuilder = new LaserGunBuilder();
		ShieldBuilder *shieldBuilder = new ShieldBuilder();
		AfterburnerBuilder *afterburnerBuilder = new AfterburnerBuilder();
		MachineGunBuilder *machinegunBuilder = new MachineGunBuilder();
		FlaresBuilder *flaresBuilder = new FlaresBuilder();
		NavigationsystemBuilder *navigationsystemBuilder = new NavigationsystemBuilder();
		NoctovisionBuilder *noctovisionBuilder = new NoctovisionBuilder();
		MissileBuilder *missileBuilder = new MissileBuilder();

		listOfModuleBuilders.push_back(laserBuilder);
		listOfModuleBuilders.push_back(shieldBuilder);
		listOfModuleBuilders.push_back(afterburnerBuilder);
		listOfModuleBuilders.push_back(machinegunBuilder);
		listOfModuleBuilders.push_back(flaresBuilder);
		listOfModuleBuilders.push_back(navigationsystemBuilder);
		listOfModuleBuilders.push_back(noctovisionBuilder);
		listOfModuleBuilders.push_back(missileBuilder);

		Dock *dockOne, *dockTwo, *dockThree, *dockFour, *dockFive;
		dockOne = new Dock();
		dockTwo = new Dock();
		dockThree = new Dock();
		dockFour = new Dock();
		dockFive = new Dock();
		listOfDocks.push_back(dockOne);
		listOfDocks.push_back(dockTwo);
		listOfDocks.push_back(dockThree);
		listOfDocks.push_back(dockFour);
		listOfDocks.push_back(dockFive);

		int aux = 0;
		for (aux; aux < 5; aux++)
		{
			dockStatus[aux] = false;
		}

		/* Initially supplying magazine with modules */
		for (int aux = 0; aux < listOfModuleBuilders.size(); aux++)
		{
			this->builderSetter(listOfModuleBuilders.at(aux));
			for (int pom = 0; pom < NROFMODULESINITIALLY; pom++) // wwwwwwwwwwwwoooooooooooooo
			{
				Module *tempModule = this->createModule();
				magazine->addModule(tempModule);
			}
		}
	}

	void checkDockStatus()
	{
		for (int aux = 0; aux < 5; aux++)
		{
			dockStatus[aux] = listOfDocks.at(aux)->getProgress();
		}
	}

	void supplyMag()
	{
		for (int aux = 0; aux < listOfModuleBuilders.size(); aux++)
		{
			this->builderSetter(listOfModuleBuilders.at(aux));
			for (int pom = 0; pom < NROFMODULESINITIALLY; pom++)
			{
				Module *tempModule = this->createModule();
				magazine->addModule(tempModule);
			}
		}
		return;
	}

	bool checkIfReadyToTakeOut(int dockNr)
	{

		if (listOfDocks.at(dockNr)->checkIfBusy())
		{
			return false;
		}
		else
		{
			return true;
		}
	}


	CoreOfShip *getShipOutOfDock(int dockSignature)
	{

		if (checkIfReady(dockSignature))
		{
			return NULL;
		}
		int aux = 0;
		return listOfDocks.at(dockSignature)->takeShipOut();

	}

	int dockStatus[5]; /* just for now to check the behavior */


	void checkMagazine()
	{
		magazine->checkMagazine();
		return;
	}

	bool checkIfReady(int dockNumber)
	{
		if (((dockNumber < 0) || (dockNumber > listOfDocks.size())))
		{
			cout << endl << endl << "Wrong dock nr!" << endl << endl;
		}
		else
		{
			if (listOfDocks.at(dockNumber)->getProgress() == -1) return false;
			dockStatus[dockNumber] = listOfDocks.at(dockNumber)->checkIfBusy();
		}

		if (dockStatus[dockNumber] == 1)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	void builderSetter(ModuleBuilder *myBuilder)
	{
		builder = myBuilder;
	}


	Module *createModule(std::string moduleSignature)
	{
		if (moduleSignature == LASERGUN)
		{
			builder = listOfModuleBuilders.at(0);
		}

		if (moduleSignature == SHIELD)
		{
			builder = listOfModuleBuilders.at(1);
		}

		if (moduleSignature == AFTERBURNER)
		{
			builder = listOfModuleBuilders.at(2);
		}

		if (moduleSignature == MACHINEGUN)
		{
			builder = listOfModuleBuilders.at(3);
		}

		if (moduleSignature == FLARES)
		{
			builder = listOfModuleBuilders.at(4);
		}

		if (moduleSignature == NAVIGATIONSYSTEM)
		{
			builder = listOfModuleBuilders.at(5);
		}

		if (moduleSignature == NOCTOVISION)
		{
			builder = listOfModuleBuilders.at(6);
		}

		if (moduleSignature == MISSILE)
		{
			builder = listOfModuleBuilders.at(7);
		}

		builderSetter(builder);

		return builder->createModule();
	}

	Module *createModule()
	{
		return builder->createModule();
	}

	void createModuleAndAddToMagazine(std::string moduleSignature)
	{
		magazine->addModule(createModule(moduleSignature));
		return;
	}

	bool modifyTheShip(Order *myOrder)
	{

		bool status = magazine->checkForAvalilability(myOrder->getOpInfo());
		if (status == false)
		{
			cout << endl << endl << "Not enough modules in a Magazine!!!" << endl << endl;
			//createModuleAndAddToMagazine()
			return false;
		}
		status = magazine->getModules(&(myOrder->getOpInfo()));
		if (status == false)
		{
			cout << endl << endl << "Not Enough Modules!!!" << endl << endl << endl;
			return false;
		}

		assignTaskToDocks(myOrder);
		return true;
	}


};

int _tmain(int argc, _TCHAR* argv[])
{
	Magazine *myMagazine = new Magazine();
	Parking *myParking = new Parking();
	Workshop *myWorkshop = new Workshop(myMagazine, myParking);

	while (1)
	{
		cout << endl << endl << endl << "1 - Create a ship" << endl << "2 - View ships" << endl << "3 - View modules" << endl << "4 - Dock status" << endl << "5 - Supply magazine with modules" << endl << "6 - Take ready ships out of docks" << endl << "7 - Modify the ship" << endl << "8 - Exit" << endl;

		int menu;
		cin >> menu;

		switch (menu)
		{
		case 1:
		{
			CoreOfShip *tempShip = new CoreOfShip();
			Order *newOrder = new Order();

			for (int aux = 0; aux < NUMBEROFSLOTS; aux++)
			{
				OperationInformation *newInfo = new OperationInformation();
				newOrder->addConcreteShip(tempShip);

				cout << endl << "Choose the slot you want to add a module to" << endl;
				cout << "1-Left wing" << endl << "2-Right wing" << endl << "3-Interrior" << endl << "4-Bottom" << endl << "5-Front" << endl << "6-Rear" << endl << "0 - Done. Send to a dock." << endl;
				int chosenSlot, chosenModule;
				cin >> chosenSlot;
				if (chosenSlot == 0) break;

				chosenSlot--;
				cout << endl << "This slot can take: " << tempShip->getDescriptionOfTheSlot(chosenSlot) << endl;
				cout << "Type in the name of module" << endl;
				std::string tempName;
				int checkIfNameValid = 0;
				while (!checkIfNameValid)
				{
					cin >> tempName;
					std::vector<std::string> *myStr = tempShip->getAllowedModules(chosenSlot);

					for (int aux = 0; aux < myStr->size(); aux++)
					{
						if (tempName == myStr->at(aux))
						{
							checkIfNameValid = 1;
							break;
						}
					}

					if (checkIfNameValid == 0)
					{
						cout << endl << "Invalid module name, try again!" << endl;
					}

				}

				newInfo->moduleSignature = tempName;
				newInfo->operationType = ATTACH;
				newInfo->slotSignature = chosenSlot;
				newOrder->addOperationInfo(newInfo);
			}

			if (!myWorkshop->modifyTheShip(newOrder)) cout << "Failure" << endl;
			break;

		}

		case 2:
		{
			cout << "The list of ships on the parking:" << endl << endl;
			if (myParking->getNumberOfShips() == 0) cout << "No ships on the Parking!!!!!!" << endl;

			else
			{
				myParking->viewShips();
			}
			break;
		}

		case 3:
		{
			myWorkshop->checkMagazine();
			break;

		}

		case 4:
		{
			myWorkshop->checkDockStatus();
			for (int aux = 0; aux < 5; aux++)
			{
				string message;
				if (myWorkshop->dockStatus[aux] == -1)
				{
					message = "No Ship being modified";
				}
				if (myWorkshop->dockStatus[aux] == 0)
				{
					message = "Ship is ready to be taken out";
				}
				if (myWorkshop->dockStatus[aux] != -1 && myWorkshop->dockStatus[aux] != 0)
				{
					message = "Ship is being modified";
					message.append(". Percent done: ");
					message.append(to_string(myWorkshop->dockStatus[aux]));
				}
				cout << endl << "Dock nr" << aux << " " << message;
			}
			break;
		}

		case 5:
		{
			myWorkshop->supplyMag();
			break;
		}

		case 6:
		{
			for (int aux = 0; aux < 5; aux++)
			{
				if (myWorkshop->dockStatus[aux] == 0)
				{
					myParking->addToParking(myWorkshop->getShipOutOfDock(aux));
				}
			}
			break;
		}

		case 7:
		{
			cout << "Choose the number of the ship" << endl;
			int chosenShip;
			cin >> chosenShip;
			while (chosenShip >= myParking->getNumberOfShips() || chosenShip < 0)
			{
				cout << endl << "Wrong ship number! Try again:" << endl;
				cin >> chosenShip;
			}

			CoreOfShip *tempShip = new CoreOfShip();
			tempShip = myParking->getShipFromParking(chosenShip);
			Order *newOrder = new Order();

			for (int aux = 0; aux < NUMBEROFSLOTS; aux++)
			{
				OperationInformation *newInfo = new OperationInformation();
				newOrder->addConcreteShip(tempShip);

				cout << endl << "Choose a slot" << endl;
				cout << "1-Left wing" << endl << "2-Right wing" << endl << "3-Interrior" << endl << "4-Bottom" << endl << "5-Front" << endl << "6-Rear" << endl << "0 - Done. Send to a dock" << endl;
				int chosenSlot, chosenModule;
				cin >> chosenSlot;
				if (chosenSlot == 0) break;

				chosenSlot--;
				cout << " Choose what you want to do:" << endl << "1- Add Module" << endl << "2-Remove Module" << endl << "3-Activate Module" << endl << "4- Disactivate module" << endl;
				int chosenOperation;
				cin >> chosenOperation;

				switch (chosenOperation)
				{
				case 1:
				{
					cout << "Enter what module you want to attach. This slot can take:" << tempShip->getAttachedModuleDescription(chosenSlot) << endl;
					cout << endl << "This slot can take: " << endl;

					std::vector <std::string> *tempVector = tempShip->getAllowedModules(chosenSlot);
					for (int aux = 0; aux < tempVector->size(); aux++)
					{
						cout << tempVector->at(aux) << ", ";
					}
					cout << endl;
					cout << "Type in the name of module" << endl;
					std::string tempName;
					int checkIfNameValid = 0;
					while (!checkIfNameValid)
					{
						cin >> tempName;
						std::vector<std::string> *myStr = tempShip->getAllowedModules(chosenSlot);

						for (int aux = 0; aux < myStr->size(); aux++)
						{
							if (tempName == myStr->at(aux))
							{
								checkIfNameValid = 1;
								break;
							}
						}

						if (checkIfNameValid == 0)
						{
							cout << endl << "Invalid module name, try again!" << endl;
						}
					}
					newInfo->moduleSignature = tempName;
					newInfo->operationType = ATTACH;
					newInfo->slotSignature = chosenSlot;
					newOrder->addOperationInfo(newInfo);
					break;
				}

				case 2:
				{
					if (tempShip->checkIfSlotEmpty(chosenSlot))
					{
						cout << endl << "This slot is empty" << endl;
						break;
					}

					if (tempShip->getToModule(chosenSlot)->checkIfActive())
					{
						cout << "You must disactivate the module first!" << endl;
						break;
					}

					newInfo->operationType = DISATTACH;
					newInfo->slotSignature = chosenSlot;
					newOrder->addOperationInfo(newInfo);
					break;
				}

				case 3:
				{
					if (tempShip->checkIfSlotEmpty(chosenSlot)) break;

					newInfo->operationType = ACTIVATE;
					newInfo->slotSignature = chosenSlot;
					newOrder->addOperationInfo(newInfo);
					break;
				}

				case 4:
				{
					if (tempShip->checkIfSlotEmpty(chosenSlot)) break;

					newInfo->operationType = DISACTIVATE;
					newInfo->slotSignature = chosenSlot;
					newOrder->addOperationInfo(newInfo);
					break;
				}
				}
			}
			if (!myWorkshop->modifyTheShip(newOrder)) cout << "Failure" << endl;
			break;

		}

		case 8:
		{
			return 0;
		}
		}
	 
	}

}