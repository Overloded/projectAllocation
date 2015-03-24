#pragma once

class Person
{
private:
	std::string name;
protected:
	int IDnumber;
public:
	std::string getName() {return name;}
	void setName(std::string n) {name = n;}
};