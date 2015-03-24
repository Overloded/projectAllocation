#pragma once


#include "person.h"
class Supervisor : public Person
{
public:
	void setSupervisorNumber(int sNum) {IDnumber = sNum;}
	void setResearchGroup(std::string rg) {researchGroup = rg;}

	std::string getResearchGroup() {return researchGroup;}
	int getSupervisorNumber() {return IDnumber;}
	

private:
	std::string researchGroup;
};