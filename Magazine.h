#include "OpInfo.h"

#define ATTACH 1

class Magazine
{
private:
	int capacity;
	std::vector <Module*> moduleList;
	int noLaserguns = 0, noShields = 0, noAfterburners = 0, noMachineguns = 0, noFlares = 0, noNaviagtionsystem = 0, noNoctovision = 0, noMissile = 0;

	int checkIfEnough(std::string myType, int NOtype) /* returns 0 if there is enough modules of a certain type or how much is lacking if necessary */
	{
		int aux = 0, available = 0;
		for (aux; aux < moduleList.size(); aux++)
		{
			if (moduleList.at(aux)->getType() == myType)
			{
				available++;
			}
			if (NOtype == available)
			{
				return 0;
			}
		}
		if (NOtype >= available)
		{
			return (NOtype - available);
		}
	}

public:

	bool getModules(std::vector <OperationInformation*> *myInfo)
	{
		bool status = checkForAvalilability(*myInfo);
		if (!status)
		{
			return false;
		}
		else
		{
			int aux = 0, pom = 0;

			for (pom; pom < myInfo->size(); pom++)
			{
				if ( (myInfo->at(pom)->operationType == ATTACH) )
				{
					aux = 0;
					while (!(moduleList.at(aux)->getType() == myInfo->at(pom)->moduleSignature) && !(aux == moduleList.size())) // zmiana
					{
						aux++;
					}
					myInfo->at(pom)->module = moduleList.at(aux);
					moduleList.erase(moduleList.begin() + aux);
				}
			}
		}

		return true;
	}

	void addModule(Module *myModule)
	{

		if (myModule->getType() == LASERGUN)
		{
			noLaserguns++;
		}
		if (myModule->getType() == SHIELD)
		{
			noShields++;
		}
		if (myModule->getType() == AFTERBURNER)
		{
			noAfterburners++;
		}
		if (myModule->getType() == MACHINEGUN)
		{
			noMachineguns++;
		}
		if (myModule->getType() == FLARES)
		{
			noFlares++;
		}
		if (myModule->getType() == NAVIGATIONSYSTEM)
		{
			noNaviagtionsystem++;
		}
		if (myModule->getType() == NOCTOVISION)
		{
			noNoctovision++;
		}
		if (myModule->getType() == MISSILE)
		{
			noMissile++;
		}

		moduleList.push_back(myModule);

		return;
	}

	Module *removeModule(std::string moduleType) /* watch out here! */
	{

		int aux = 0;
		while (!(moduleList.at(aux)->getType() == moduleType) && !(aux == (1 + moduleList.size())))
		{
			aux++;

			if (aux == (1 + moduleList.size()))
			{
				return NULL;
			}
			else
			{
				Module *tempPointer = moduleList.at(aux);
				moduleList.erase(moduleList.begin() + aux);
				return tempPointer;
			}
		}
	}

	void checkMagazine()
	{
		int aux = 0;
		noLaserguns = 0, noShields = 0, noAfterburners = 0, noMachineguns = 0, noFlares = 0, noNaviagtionsystem = 0, noNoctovision = 0, noMissile = 0;
		for (aux; aux < moduleList.size(); aux++) /* check how much of each type is needed for the order*/
		{
			if (moduleList.at(aux)->getType() == LASERGUN)
			{
				noLaserguns++;
			}
			if (moduleList.at(aux)->getType() == SHIELD)
			{
				noShields++;
			}
			if (moduleList.at(aux)->getType() == AFTERBURNER)
			{
				noAfterburners++;
			}
			if (moduleList.at(aux)->getType() == MACHINEGUN)
			{
				noMachineguns++;
			}
			if (moduleList.at(aux)->getType() == FLARES)
			{
				noFlares++;
			}
			if (moduleList.at(aux)->getType() == NAVIGATIONSYSTEM)
			{
				noNaviagtionsystem++;
			}
			if (moduleList.at(aux)->getType() == NOCTOVISION)
			{
				noNoctovision++;
			}
			if (moduleList.at(aux)->getType() == MISSILE)
			{
				noMissile++;
			}
		}

		cout << endl << LASERGUN << ": " << noLaserguns;
		cout << endl << SHIELD << ": " << noShields;
		cout << endl << MACHINEGUN << ": " << noMachineguns;
		cout << endl << FLARES << ": " << noFlares;
		cout << endl << AFTERBURNER << ": " << noAfterburners;
		cout << endl << NOCTOVISION << ": " << noNoctovision;
		cout << endl << MISSILE << ": " << noMissile;
		cout << endl << NAVIGATIONSYSTEM << ": " << noNaviagtionsystem;

		cout << endl << "ModuleList size:" << moduleList.size() << endl;
		return;


	}


	bool checkForAvalilability(std::vector <OperationInformation*> myInfo)
	{
		int NOLaserguns = 0, NOShields = 0, NOAfterburners = 0, NOMachineguns = 0, NOFlares = 0, NONavigationsystem = 0, NONoctovision = 0, NOMissile = 0; /* NO = "Number Of" */

		int aux = 0;

		for (aux; aux <= myInfo.size(); aux++) /* check how much of each type is needed for the order*/
		{
			if (myInfo.at(aux)->moduleSignature == LASERGUN)
			{
				NOLaserguns++;
			}
			if (myInfo.at(aux)->moduleSignature == SHIELD)
			{
				NOShields++;
			}
			if (myInfo.at(aux)->moduleSignature == AFTERBURNER)
			{
				NOAfterburners++;
			}
			if (myInfo.at(aux)->moduleSignature == MACHINEGUN)
			{
				NOMachineguns++;
			}
			if (myInfo.at(aux)->moduleSignature == FLARES)
			{
				NOFlares++;
			}
			if (myInfo.at(aux)->moduleSignature == NAVIGATIONSYSTEM)
			{
				NONavigationsystem++;
			}
			if (myInfo.at(aux)->moduleSignature == NOCTOVISION)
			{
				NONoctovision++;
			}
			if (myInfo.at(aux)->moduleSignature == MISSILE)
			{
				NOMissile++;
			}

			noLaserguns = checkIfEnough(LASERGUN, NOLaserguns);  /* check if there is enough of each type in the magazine */
			noShields = checkIfEnough(SHIELD, NOShields);
			noAfterburners = checkIfEnough(AFTERBURNER, NOAfterburners);
			noMachineguns = checkIfEnough(MACHINEGUN, NOMachineguns);
			noFlares = checkIfEnough(FLARES, NOFlares);
			noNaviagtionsystem = checkIfEnough(NAVIGATIONSYSTEM, NONavigationsystem);
			noNoctovision = checkIfEnough(NOCTOVISION, NONoctovision);
			noMissile = checkIfEnough(MISSILE, NOMissile);

			if ((noLaserguns < 0) || (noShields < 0) || (noAfterburners < 0) || (noMachineguns < 0) || (noFlares < 0) || (noNaviagtionsystem < 0) || (noNoctovision < 0) || (noMissile < 0))
			{
				return false;
			}

			else
			{
				return true;
			}

		}
	}

};
