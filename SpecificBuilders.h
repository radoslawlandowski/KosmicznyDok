class ModuleBuilder
{
public:
	virtual Module *createModule() = 0;
};

class LaserGunBuilder : public ModuleBuilder
{
private:
	LaserGun *module;

	std::string createDescription(int power, int range, int reloadTime)
	{
		std::string tempDescription;

		tempDescription.append("LaserGun - Power: ");
		tempDescription.append(to_string(power));
		tempDescription.append(", Range: ");
		tempDescription.append(to_string(range));
		tempDescription.append(", Reload time: ");
		tempDescription.append(to_string(reloadTime));
		tempDescription.append(".");

		return tempDescription;
	}

public:
	LaserGun *createModule()
	{
		return (createModule(5, 3, 2));
	}

	LaserGun *createModule(int myPower, int myRange, int myReloadTime)
	{
		module = new LaserGun;

		module->setPower(myPower);
		module->setRange(myRange);
		module->setReloadTime(myReloadTime);
		module->setType(LASERGUN);
		module->setDescription(createDescription(myPower, myRange, myReloadTime));

		return module;
	}

};

class ShieldBuilder : public ModuleBuilder
{
private:
	Shield *module;

	std::string createDescription(int myDurability)
	{
		std::string tempDescription;

		tempDescription.append("Shield - durability: ");
		tempDescription.append(to_string(myDurability));
		tempDescription.append(".");

		return tempDescription;
	}

public:
	Shield *createModule()
	{
		return (createModule(5));
	}

	Shield *createModule(int myDurability)
	{
		module = new Shield;

		module->setDurability(myDurability);

		module->setType(SHIELD);
		module->setDescription(createDescription(myDurability));

		return module;
	}

};

class AfterburnerBuilder : public ModuleBuilder
{
private:
	Afterburner *module;

	std::string createDescription(int myWorkingTime, int myFactor, int myReloadTime)
	{
		std::string tempDescription;

		tempDescription.append("Afterburner - working time: ");
		tempDescription.append(to_string(myWorkingTime));
		tempDescription.append(", power increase factor: ");
		tempDescription.append(to_string(myFactor));
		tempDescription.append(", Reload time: ");
		tempDescription.append(to_string(myReloadTime));
		tempDescription.append(".");

		return tempDescription;
	}

public:
	Afterburner *createModule()
	{
		return (createModule(5, 3, 2));
	}

	Afterburner *createModule(int myWorkingTime, int myFactor, int myReloadTime)
	{
		module = new Afterburner;

		module->setPowerIncreaseFactor(myFactor);
		module->setReloadTime(myReloadTime);
		module->setWorkingTime(myWorkingTime);
		module->setType(AFTERBURNER);
		module->setDescription(createDescription(myWorkingTime, myFactor, myReloadTime));


		return module;
	}

};


class MissileBuilder : public ModuleBuilder
{
private:
	Missile *module;

	std::string createDescription(int myNrOfMissiles, int myReloadTime)
	{
		std::string tempDescription;

		tempDescription.append("Missile - number of missiles: ");
		tempDescription.append(to_string(myNrOfMissiles));
		tempDescription.append(", reload time: ");
		tempDescription.append(to_string(myReloadTime));
		tempDescription.append(".");

		return tempDescription;
	}

public:
	Missile *createModule()
	{
		return (createModule(5, 3));
	}

	Missile *createModule(int myNrOfMissiles, int myReloadTime)
	{
		module = new Missile;

		module->setNumberOfMissiles(myNrOfMissiles);
		module->setReloadTime(myReloadTime);
		module->setType(MISSILE);
		module->setDescription(createDescription(myNrOfMissiles, myReloadTime));

		return module;
	}

};

class NoctovisionBuilder : public ModuleBuilder
{
private:
	Noctovision *module;

	std::string createDescription(int myClarity, int myTime, int myReloadTime)
	{
		std::string tempDescription;

		tempDescription.append("Noctovision - clarity ");
		tempDescription.append(to_string(myClarity));
		tempDescription.append(", working time: ");
		tempDescription.append(to_string(myTime));
		tempDescription.append(", Reload time: ");
		tempDescription.append(to_string(myReloadTime));
		tempDescription.append(".");

		return tempDescription;
	}

public:
	Noctovision *createModule()
	{
		return (createModule(5, 3, 2));
	}

	Noctovision *createModule(int myClarity, int myTime, int myReloadTime)
	{
		module = new Noctovision;

		module->setClarity(myClarity);
		module->setReloadTime(myReloadTime);
		module->setTime(myTime);
		module->setType(NOCTOVISION);
		module->setDescription(createDescription(myClarity, myTime, myReloadTime));

		return module;
	}

};

class NavigationsystemBuilder : public ModuleBuilder
{
private:
	NavigationSystem *module;

	std::string createDescription(int myRange, int myAccuracy, int myScanningFreq)
	{
		std::string tempDescription;

		tempDescription.append("NavigationSystem - range: ");
		tempDescription.append(to_string(myRange));
		tempDescription.append(", accuracy: ");
		tempDescription.append(to_string(myAccuracy));
		tempDescription.append(", scanning frequency: ");
		tempDescription.append(to_string(myScanningFreq));
		tempDescription.append(".");

		return tempDescription;
	}

public:
	NavigationSystem *createModule()
	{
		return (createModule(5, 3, 2));
	}

	NavigationSystem *createModule(int myRange, int myAccuracy, int myScanningFreq)
	{
		module = new NavigationSystem;

		module->setRange(myRange);
		module->setAccuracy(myAccuracy);
		module->setScanningFrequency(myScanningFreq);
		module->setType(NAVIGATIONSYSTEM);
		module->setDescription(createDescription(myRange, myAccuracy, myScanningFreq));

		return module;
	}

};


class FlaresBuilder : public ModuleBuilder
{
private:
	Flares *module;

	std::string createDescription(int myReloadTime, int myNrOfFlares)
	{
		std::string tempDescription;

		tempDescription.append("Flares - reload time: ");
		tempDescription.append(to_string(myReloadTime));
		tempDescription.append(", number of flares: ");
		tempDescription.append(to_string(myNrOfFlares));
		tempDescription.append(".");

		return tempDescription;
	}

public:
	Flares *createModule()
	{
		return (createModule(5, 2));
	}

	Flares *createModule(int myReloadTime, int myNrOfFlares)
	{
		module = new Flares;

		module->setReloadTime(myReloadTime);
		module->setNumberOfFlareSets(myNrOfFlares);
		module->setType(FLARES);
		module->setDescription(createDescription(myReloadTime, myNrOfFlares));

		return module;
	}

};

class MachineGunBuilder : public ModuleBuilder
{
private:
	MachineGun *module;

	std::string createDescription(int myPower, int myRange, int myReloadTime)
	{
		std::string tempDescription;

		tempDescription.append("MachineGun - power: ");
		tempDescription.append(to_string(myPower));
		tempDescription.append(", range: ");
		tempDescription.append(to_string(myRange));
		tempDescription.append(", Reload time: ");
		tempDescription.append(to_string(myReloadTime));
		tempDescription.append(".");

		return tempDescription;
	}

public:
	MachineGun *createModule()
	{
		return (createModule(5, 3, 2));
	}

	MachineGun *createModule(int myPower, int myRange, int myReloadTime)
	{
		module = new MachineGun;

		module->setPower(myPower);
		module->setReloadTime(myReloadTime);
		module->setRange(myRange);
		module->setType(MACHINEGUN);
		module->setDescription(createDescription(myPower, myRange, myReloadTime));

		return module;
	}

};
