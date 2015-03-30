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
		temp[i].set_title(title);

		getline(ss, p_id, ','); //set project ID
		p = atoi(p_id.c_str());
		temp[i].set_projectID(p);

		getline(ss, s_id, ','); //set supervisor ID
		d = atoi(s_id.c_str());
		temp[i].set_supervisorID(d); //in person or project class?
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

	
	std::string line, sTemp;

	int i = 0, p;

	/*File format:
	Student ID,Student Name,Registration Number,Registration Status,Email,Selections
	*/
	while (!file.eof()){
		temp.push_back(Student());
		getline(file, line); //Extract line to sstream

        std::stringstream ss(line);

        getline(ss, sTemp, ','); //set student id
        p = atoi(sTemp.c_str());
        temp[i].setIDnumber(p);

        getline(ss, sTemp, ','); //set name
        temp[i].setName(sTemp);

        getline(ss, sTemp, ','); //set registration number
        p = atoi(sTemp.c_str());
        temp[i].setStudentNumber(p);

        getline(ss, sTemp, ','); //set registration status
        temp[i].setRegStatus(sTemp);

        getline(ss, sTemp, ','); //set email
        temp[i].setEmail(sTemp);

        getline(ss, sTemp, ','); //set selections
        p = atoi(sTemp.c_str());
        temp[i].setSelections(p);

        i++;
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
	Personnel ID,Name,Job Title,Dept,Email,Projects,Available Projects
	*/
    std::string line, tempString;
	int i = 0, p;
	while (!file.eof()){
		temp.push_back(Supervisor());
		getline(file, line); //Extract line to sstream

        ss.clear();
		ss << line;

        getline(ss, tempString, ','); //set supervisor ID
        p = atoi(tempString.c_str());
		temp[i].setIDnumber(p);

        getline(ss, tempString, ','); //set name
        temp[i].setName(tempString);

        getline(ss, tempString, ','); //set job title
        temp[i].setJobTitle(tempString);

        getline(ss, tempString, ','); //set department
        temp[i].setDepartment(tempString);

        getline(ss, tempString, ','); //set email
        temp[i].setEmail(tempString);

        getline(ss, tempString, ','); //set projects
        p = atoi(tempString.c_str());
        temp[i].setProjects(p);

        getline(ss, tempString, ','); //set available projects
        p = atoi(tempString.c_str());
        temp[i].setAvailableProjects(p);


		//getline(ss, res_grp, ','); //set research group
		//temp[i].setResearchGroup(res_grp); 
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