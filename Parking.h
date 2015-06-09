#define NUMBEROFSLOTS 6

class Parking
{
private:
	std::vector<CoreOfShip*> listOfShips;
public:
	void addToParking(CoreOfShip *myShip)
	{
		listOfShips.push_back(myShip);
		return;
	}

	void viewShips()
	{
		for (int aux = 0; aux < listOfShips.size(); aux++)
		{
			cout << endl << "Ship nr: " << aux << endl << "{";
			for (int pom = 0; pom < NUMBEROFSLOTS; pom++)
			{
				cout << endl << listOfShips.at(aux)->getAttachedModuleDescription(pom);
				cout << " Status: ";
				if (!listOfShips.at(aux)->checkIfSlotEmpty(pom))
				{
					if (listOfShips.at(aux)->getToModule(pom)->checkIfActive()) cout << "ACTIVE";
					else cout << "NOT ACTIVE";

				}
				
			}

			cout << endl << " }" << endl << endl;
		}
	}

	CoreOfShip *getShipFromParking(int shipNumber)
	{
		if ((shipNumber < 0) || (shipNumber > listOfShips.size()) || (listOfShips.size() == 0))
		{
			return NULL;
		}

		CoreOfShip *temp = listOfShips.at(shipNumber);
		listOfShips.erase(listOfShips.begin() + shipNumber);
		return temp;
	}

	int getNumberOfShips()
	{
		return listOfShips.size();
	}

};
