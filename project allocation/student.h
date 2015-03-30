#pragma once
#include <vector>

#include "person.h"
class Student : public Person
{
public:
    Student();

    int getStudentNumber() { return studentNumber; }
    void setStudentNumber(int sNum) { studentNumber = sNum; }

    std::string getRegStatus() { return regStatus; }
    void setRegStatus(std::string rs) { regStatus = rs; }

    int getSelections() { return selections; }
    void setSelections(int s) { selections = s; }
	
	void addProject(Project* p);
	Project* getProject(int n) { return projectList[n];}
	

private:
    int studentNumber;
    int selections;
    std::string regStatus;
	std::vector<Project*> projectList;
};