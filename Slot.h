using namespace std;

class Slot /* A sub unit of a CoreOfShip. It is a container for the specific module. The types of module that can be attached are definied in allowedModules vector */
{
private:
	std::string description; /* tells us what types of modules the slot can take */
	std::string name;
	std::vector<std::string> *allowedModules;
	Module *attachedModule;
	bool isEmpty;

	void attachModule(Module *myModule)
	{
		attachedModule = myModule;
		setAttached();
		return;
	};

	void setEmpty()
	{
		isEmpty = true;
		return;
	}

	void setAttached()
	{
		isEmpty = false;
		return;
	}

public:
	Slot()
	{
		allowedModules = new std::vector < std::string >;
		description.append(" ");
		setEmpty();
	};

	Slot(std::string myName)
	{
		allowedModules = new std::vector < std::string >;
		description.append(" ");
		setEmpty();
		this->name = myName;
	};


	std::vector<std::string> *getAllowedModules()
	{
		return allowedModules;
	};

	bool checkIfEmpty()
	{
		return isEmpty;
	}

	void addAllowedModule(std::string allowedModule) /* add an element to the vector cotaining what types of modules can be attached to the slot */
	{
		allowedModules->push_back(allowedModule);
		description.append(allowedModule);
		description.append(" ");
	}

	void addModule(Module *myModule) /* assign myModule to the slot, provided there is no module already attached and that myModule suits the restrictions of the slot*/
	{
		if (!(checkIfEmpty()))
		{
			cout << endl << "The Slot has already had a module!" << endl;
			return;
		}

		int aux = 0;
		while (!(allowedModules->size() == aux)) /* check through the vector of allowedModules if myModule suits this slot */
		{
			if (allowedModules->at(aux) == myModule->getType())
			{
				attachModule(myModule);

				cout << endl << "Module added" << endl;
				setAttached();
				break;
			}

			aux++;
			if (allowedModules->size() == aux) /* reached the end of vector with no matching results */
			{
				std::cout << endl << "This module cannot be added!" << endl; /* error that is displayed when user tries to attach a forbidden type of module*/
			}

		}
		return;
	}

	void removeModule()
	{
		setEmpty();
		attachedModule = NULL;
	}

	std::string getDescriptionOfTheSlot()
	{
		return description;
	}

	Module *getToModule() /* returns a pointer to the attached module to allow doing opeartions on it*/
	{
		if (checkIfEmpty())
		{
			cout << endl << "No Module connected!!" << endl;
			return NULL;
		}
		return attachedModule;
	}

	std::string getAttachedModuleDescription()
	{
		if (!checkIfEmpty())
		{
			std::string desc = name;
			desc.append(" has ");
			desc.append(attachedModule->getDescription());
			return desc;
		}
		else
		{
			std::string desc = name;
			desc.append(" is empty");
			return desc;
		}
	}

	~Slot();
};