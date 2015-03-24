#include "projectPlanner.h"

void Student::addProject(Project* p){
	projectList.push_back(p);
	
}

Student::~Student(){
	if (!projectList.empty()){
		projectList.clear();
	}
}