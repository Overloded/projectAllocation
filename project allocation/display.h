#pragma once
#include <vector>
#include "projectPlanner.h"
class Display
{
public:
	Display();

	void printProjects(std::vector <Project> projects);
	void printStudents(std::vector <Student> students);
	void printSupervisors(std::vector <Supervisor> supervisors);
};