#define ATTACH 1
#define DISATTACH 2
#define ACTIVATE 3
#define DISACTIVATE 4
#define NOMODULEBEINGMADE -1

class Dock
{
private:
	CoreOfShip *modifiedShip;

	bool isBusy; /* tells if the dock is working on a ship*/
	bool isShipInside; /* tells if the ship is inside the Dock. Checking those two is crucial to find out the status of the Dock. The ship i.e. might be already modified but still not taken away from the dock */

	int progress; /* percentage of accomplishment of current modification */
	static const int operationTime = 15; /* a time for one operation to be done in seconds */
	int timeForTheShip;

	time_t start, finish;

	void setBusy()
	{
		isBusy = true;
	}

	void setFree()
	{
		isBusy = false;
	}

	void attachModuleToShip(CoreOfShip *myShip, int slotSignature, Module *myModule)
	{
		myShip->addModuleToSlot(myModule, slotSignature);
		myShip->getToModule(slotSignature)->activate();
		return;
	}

	void removeModule(CoreOfShip *myShip, int slotNumber)
	{
		myShip->removeModule(slotNumber);
		return;
	}

	void activateTheModule(CoreOfShip *myShip, int slotNumber)
	{
		myShip->getToModule(slotNumber)->activate();
		return;
	}

	void disactivateTheModule(CoreOfShip *myShip, int slotNumber)
	{
		myShip->getToModule(slotNumber)->deactivate();
		return;
	}

	void setShipInside()
	{
		isShipInside = true;
	}

	void setShipAway()
	{
		isShipInside = false;
	}

	bool checkIfShipInside()
	{
		return isShipInside;
	}

public:

	Dock()
	{
		modifiedShip = NULL;
		isBusy = false;
		isShipInside = false;
	}

	void setFree1()
	{
		isBusy = false;
	}

	CoreOfShip *takeShipOut()
	{
		if (checkIfBusy() || !checkIfShipInside())
		{
			return NULL;
		}
		setShipAway();
		CoreOfShip *tempShip = modifiedShip;
		modifiedShip = NULL; /* Release the ship from the dock */
		return tempShip;
	}

	void getToModyfing(Order *myOrder)
	{
		modifiedShip = myOrder->getShip();

		int nrOfOperationsToDo = myOrder->getOpInfo().size();

		int aux = 0;
		int operationType;

		for (aux; aux < myOrder->getOpInfo().size(); aux++)
		{
			operationType = myOrder->getOpInfo().at(aux)->operationType;
			switch (operationType)
			{
			case ATTACH:
			{
				attachModuleToShip(myOrder->getShip(), myOrder->getOpInfo().at(aux)->slotSignature, myOrder->getOpInfo().at(aux)->module);
				break;

			}
			case DISATTACH:
			{
				removeModule(myOrder->getShip(), myOrder->getOpInfo().at(aux)->slotSignature);
				break;
			}
			case ACTIVATE:
			{
				activateTheModule(myOrder->getShip(), myOrder->getOpInfo().at(aux)->slotSignature);
				break;
			}
			case DISACTIVATE:
			{
				disactivateTheModule(myOrder->getShip(), myOrder->getOpInfo().at(aux)->slotSignature);
				break;
			}
			default:
			{
				cout << endl << "BAD OPERATION TYPE" << endl;
				break;
			}
			}


		}

		time(&start);
		setBusy();
		setShipInside();

		timeForTheShip = nrOfOperationsToDo * operationTime;
	}

	int checkIfBusy() /* modify this func*/
	{
		if (isBusy)
		{
			return 1;
		}

		else
		{
			return 0;
		}
	}

	int getProgress() /* Calculates the progress of the operation in percent. Returns current percentage or '-1' if no module being made */
	{
		int percentage = 0;

		if (checkIfBusy())
		{
			time_t finish;
			time(&finish);

			int difference = difftime(start, finish);

			percentage = ((abs(difference)) / (double)timeForTheShip) * 100;

			if (percentage >= 100)
			{
				percentage = 100;
				setFree();
				return 0;
			}

			return percentage;
		}

		else
		{
			if (checkIfShipInside()) return 0;
			return NOMODULEBEINGMADE;
		}
	}

};

