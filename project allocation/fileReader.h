#pragma once
#include <vector>
#include "project.h"
#include "student.h"
#include "supervisor.h"

class FileReader
{
public:
	//Read in data from file
	std::vector<Project> readProjects(std::string path);
	std::vector<Student> readStudents(std::string path, std::vector<Project>& projectVector, Project* errorProject);
	std::vector<Supervisor> readSupervisors(std::string path);

	//output final results
	void writeResults(/*take in vector of results*/);
private:
	void openFile(std::string path, std::ifstream& file);
	void readList(std::ifstream& file);
};