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
    std::cin.ignore();
	for (std::vector<Supervisor>::iterator it = supervisors.begin(); it != supervisors.end(); ++it)
	{
        std::cout << "Name: " << it->getName() << std::endl
            << " ID number: " << it->getIDnumber() << std::endl
            << " Job Title: " << it->getJobTitle() << std::endl
            << " Department: " << it->getDepartment() << std::endl
            << " Email:" << it->getEmail() << std::endl
            << " Projects: " << it->getProjects() <<std::endl
            << " Available Projects: " << it->getAvailableProjects() << std::endl;

        std::cin.get();
	}
}

void Display::printStudents(std::vector<Student> students)

{

    std::cin.ignore();
	for (std::vector<Student>::iterator it = students.begin(); it != students.end(); ++it)
	{
        //Student ID, Student Name, Registration Number, Registration Status, Email, Selections

        std::cout << "Name: " << it->getName() << std::endl
            << "ID number: " << it->getIDnumber() << std::endl
            << "Registration number: " << it->getStudentNumber() << std::endl
            << "Registration status: " << it->getRegStatus() << std::endl
            << "Email: " << it->getEmail() << std::endl
            << "Selections: " << it->getSelections() << std::endl;
            
       


        /*NEED TO ASSIGN THIS SOMEWHERE*/
        /*
		    for (int x = 0; x < 5; ++x)
		    {
			    std::cout << "Projects: " << it->getProject(x)->getTitle() << ", ";
		    }
       
	    std::cout << std::endl;
        */
        std::cin.get();
	}
}