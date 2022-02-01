#pragma once

class Human
{
private:
	std::string firstName;
	std::string secondName;
	std::string lastName;
public:

	Human(std::string firstName, std::string secondName, std::string lastName)
	{
		this->firstName = firstName;
		this->secondName = secondName;
		this->lastName = lastName;
	}

	std::string getFullName()
	{
		std::string fullName = lastName + " " + firstName + " " + secondName;
		return fullName;
	}
	virtual std::string getInfo() = 0;
};
