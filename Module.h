
class Module
{
protected:
	std::string description;
	std::string type;
	bool isActive = true;

public:

	virtual void setDescription(std::string myDesc) = 0;
	std::string getDescription() { return description; };

	void setType(std::string myType) { type = myType; };
	std::string getType() { return type; };

	void activate() { isActive = true; };
	void deactivate() { isActive = false; };
	bool checkIfActive() { return isActive; };
};