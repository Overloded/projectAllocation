#include "fileReader.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::string;
using std::endl;

void writeToErrorLog(std::string errorMessage)
{
	std::ofstream errorFile("Errors.txt", std::ofstream::app);

	errorFile << errorMessage;
}

std::vector<Project> FileReader::readProjects(std::string path)
{
	std::string line, title, p_id, s_id;
	std::vector<Project> temp;

	//input file
	std::ifstream file;
	std::stringstream ss;
	openFile(path, file);

	//File format: title,project ID,supervisor ID
	int i = 0, p,d ;
	while (!file.eof()){
		temp.push_back(Project());
		getline(file, line); //Extract line to sstream

		ss.clear();
		ss << line.c_str();

		getline(ss, title, ','); //set title
		//cout << title << endl;
		temp[i].set_title(title);

		getline(ss, p_id, ','); //set project ID
		//cout << p_id << endl;
		p = atoi(p_id.c_str());
		temp[i].set_projectID(p);

		getline(ss, s_id, ','); //set supervisor ID
		d = atoi(s_id.c_str());
		temp[i].set_supervisorID(d); //in person or project class?
		//cout << s_id << endl;
		i++;
	}
	file.close();
	return temp;
}

std::vector<Student> FileReader::readStudents(std::string path, std::vector<Project>& projectVector, Project* errorProject)
{
	std::vector<Student> temp;

	std::ifstream file;
	openFile(path, file);

	std::stringstream ss;
	std::string line, name, reg_no, p_title;

	int i = 0, p;

	/*File format:
	 name,reg_no,project preference 001,project preference 002,....
	*/
	while (!file.eof()){
		temp.push_back(Student());
		getline(file, line); //Extract line to sstream
		ss.clear();
		ss << line;

		getline(ss, name, ','); //set name
		//cout << name << endl;
		temp[i].setName(name);

		getline(ss, reg_no, ','); //set reg no
		//cout << reg_no << endl;
		p = atoi(reg_no.c_str());
		temp[i].setStudentNumber(p);


		//readList(file); //set vector of preferences
		for (int x = 0; x < 5; ++x)
		{
			std::string title;
			getline(ss, title, ',');

			bool isFound = false;
			for (std::vector<Project>::iterator it = projectVector.begin(); it != projectVector.end(); ++it)
			{
				if (it->getTitle() == title)
				{
					temp[i].addProject(&(*it));
					isFound = true;
					break;
				}
			}
			if (!isFound)
			{
				temp[i].addProject(errorProject);
				std::string error = "The project title " + title +  " for student: " + temp[i].getName() + " is not a valid project\n"; 
				writeToErrorLog(error);
			}
		}
		++i;
	}
	file.close();
	
	return temp;

}

std::vector<Supervisor> FileReader::readSupervisors(std::string path)
{
	std::vector<Supervisor> temp;
	std::ifstream file;
	openFile(path, file);
	std::stringstream ss;
	/*File format:
	'name,supervisor_id,research_group
	*/
	std::string line, name, superv_id, res_grp;
	int i = 0, p;
	while (!file.eof()){
		temp.push_back(Supervisor());
		getline(file, line); //Extract line to sstream
		ss << line;

		getline(ss, name, ','); //set name
		//cout << name << endl;
		temp[i].setName(name);

		getline(ss, superv_id, ','); //set supervisor ID
		//cout << superv_id << endl;
		p = atoi(superv_id.c_str());
		temp[i].setSupervisorNumber(p); //in person or project class?

		getline(ss, res_grp, ','); //set research group
		temp[i].setResearchGroup(res_grp); 
		//cout << res_grp << endl;
		i++;
	}
	file.close();
	return temp;

}


void FileReader::openFile(std::string path, std::ifstream& file)
{
	file.open(path);
	if (file.is_open())
	{
		return;
	}
	else
	{
		std::cout << "File: " << path << " could not be found."<<std::endl;
	}
	file.close();

}