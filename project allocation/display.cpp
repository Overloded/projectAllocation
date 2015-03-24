#include "display.h"
#include <iostream>

Display::Display()
{
}

void Display::printProjects(std::vector<Project> projects)
{
	for (std::vector<Project>::iterator it = projects.begin(); it != projects.end(); ++it)
		{
		std::cout << "Name: " << it->getTitle()
					<< " ID number: " << it->getSupervisorID() 
					<< "." 
			<< it->getProjectID() << std::endl;
	}
}
void Display::printSupervisors(std::vector<Supervisor> supervisors)
{

	for (std::vector<Supervisor>::iterator it = supervisors.begin(); it != supervisors.end(); ++it)
	{
		std::cout << "Name: " << it->getName()
				  << " ID number: " << it->getSupervisorNumber()
				  << " Research Group: "
				  << it->getResearchGroup() << std::endl;
	}
}

void Display::printStudents(std::vector<Student> students)

{
	for (std::vector<Student>::iterator it = students.begin(); it != students.end(); ++it)
		{
		std::cout << "Name: " << it->getName()
				  << " Student number: " << it->getStudentNumber() << std::endl;
			for (int x = 0; x < 5; ++x)
			{
				std::cout << "Projects: " << it->getProject(x)->getTitle() << ", ";
			}
		std::cout << std::endl;
	}
}