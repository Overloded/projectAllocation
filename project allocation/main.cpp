#include <iostream>
#include <string>
#include <fstream>

#include "projectPlanner.h"

int main()
{
	Project errorProject;
	errorProject.set_title("INVALID PROJECT");	
	
    FileReader fr;

	Display display;
	std::vector<Project> projects;
	std::vector<Supervisor> supervisors;
	std::vector<Student> students;

	int state;
	bool complete = false;

	do
	{
	std::cout << "What do you want to do: " << std::endl
			  << "1. Assign student projects" << std::endl
			  << "2. View projects, supervisors, students" << std::endl
			  << "3. Exit" << std::endl;
	
	std::cin >> state;
	switch (state)
	{
	case 1:
		{
			std::string filePath;
			std::cout << "Enter project file path: ";

			std::cin.ignore();
			std::getline(std::cin, filePath);
			projects = fr.readProjects(filePath);

			std::cout << "Enter supervisor file path: ";
			std::getline(std::cin, filePath);
            supervisors = fr.readSupervisors(filePath);

			std::cout << "Enter student file path: ";
			std::getline(std::cin, filePath);
            students = fr.readStudents(filePath, projects, &errorProject);
			break;
		}
	case 2:
		{
			display.printProjects(projects);
			display.printSupervisors(supervisors);
			display.printStudents(students);
		break;
		}
	case 3:
		{
			complete = true;
		}
	default:
		std::cout << "Invalid input. Please choose one of the options" << std::endl;
	}
	}while (complete == false);
	
	return 0;
}