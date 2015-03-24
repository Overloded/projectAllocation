#pragma once
#include <vector>

#include "person.h"
class Student : public Person
{
public:
	int getStudentNumber() {return IDnumber;}
	void setStudentNumber(int sNum) {IDnumber = sNum;}
	~Student();
	void addProject(Project* p);
	Project* getProject(int n) { return projectList[n];}
	

private:
	std::vector<Project*> projectList;
};