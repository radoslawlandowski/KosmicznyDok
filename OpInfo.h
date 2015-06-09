struct OperationInformation
{
	int slotSignature;
	Module *module;
	std::string moduleSignature;
	int operationType; /* attach = 1; disattach = 2; activate = 3; disactivate = 4 */
};


class Order /* "zamowienie" . This class handles information about which ship is to be modified and what kind of modification is going to be done.*/
{
private:
	CoreOfShip *modifiedShip;
	std::vector < OperationInformation* > operationInformation;

public:
	void addConcreteShip(CoreOfShip *myShip)
	{
		modifiedShip = myShip;
		return;
	}

	void addOperationInfo(OperationInformation *myInfo)
	{
		operationInformation.push_back(myInfo);
		return;
	}

	CoreOfShip *getShip()
	{
		return modifiedShip;
	}

	std::vector <OperationInformation*> getOpInfo()
	{
		return operationInformation;
	}
};