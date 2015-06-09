
class LaserGun : public Module
{
private:
	int power, range, reloadTime;
public:
	void setDescription(std::string myDesc) { description = myDesc; };
	void setPower(int myPower) { power = myPower; };
	void setRange(int myRange) { range = myRange; };
	void setReloadTime(int myReloadTime) { reloadTime = myReloadTime; };

};

class Shield : public Module
{
private:
	int durability;
public:
	void setDescription(std::string myDesc) { description = myDesc; };
	void setDurability(int myDurability) { durability = myDurability; };
};

class Afterburner : public Module
{
private:
	int powerIncreaseFactor, workingTime, reloadTime;
public:
	void setDescription(std::string myDesc) { description = myDesc; };
	void setPowerIncreaseFactor(int myFactor){ powerIncreaseFactor = myFactor; };
	void setWorkingTime(int myWorkingTime) { workingTime = myWorkingTime; };
	void setReloadTime(int myReloadTime) { reloadTime = myReloadTime; };
};

class MachineGun : public Module
{
private:
	int power, range, reloadTime;
public:
	void setDescription(std::string myDesc) { description = myDesc; };
	void setPower(int myPower) { power = myPower; };
	void setRange(int myRange) { range = myRange; };
	void setReloadTime(int myReloadTime) { reloadTime = myReloadTime; };
};

class Flares : public Module
{
private:
	int reloadTime, numberOfFlareSets;
public:
	void setDescription(std::string myDesc) { description = myDesc; };
	void setReloadTime(int myReloadTime) { reloadTime = myReloadTime; };
	void setNumberOfFlareSets(int myNumberOfSets) { numberOfFlareSets = myNumberOfSets; };
};

class Missile : public Module
{
private:
	int reloadTime, numberOfMissiles;
public:
	void setDescription(std::string myDesc) { description = myDesc; };
	void setReloadTime(int myReloadTime) { reloadTime = myReloadTime; };
	void setNumberOfMissiles(int myNumOfMissiles) { numberOfMissiles = myNumOfMissiles; };
};

class NavigationSystem : public Module
{
private:
	int range, accuracy, scanningFrequency;
public:
	void setDescription(std::string myDesc) { description = myDesc; };
	void setRange(int myRange) { range = myRange; };
	void setAccuracy(int myAccuracy) { accuracy = myAccuracy; };
	void setScanningFrequency(int myFrequency) { scanningFrequency = myFrequency; };
};

class Noctovision : public Module
{
private:
	int clarity, time, reloadTime;
public:
	void setDescription(std::string myDesc) { description = myDesc; };
	void setClarity(int myClarity) { clarity = myClarity; };
	void setTime(int myTime) { time = myTime; };
	void setReloadTime(int myReloadTime) { reloadTime = myReloadTime; };
};
