#pragma once
#include <string>
#include "person.h"
class Project
{
private:
	int projectID;
	int supervisorID;
	std::string title;
public:
	void set_projectID(int ID){ projectID = ID; }
	void set_supervisorID(int ID){ supervisorID = ID; }
	void set_title(std::string name){ title = name; }

	std::string getTitle() {return title;}
	int getProjectID() {return projectID;}
	int getSupervisorID() {return supervisorID;}
};