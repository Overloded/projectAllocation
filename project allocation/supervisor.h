#pragma once


#include "person.h"
class Supervisor : public Person
{
public:
	void setResearchGroup(std::string rg) {researchGroup = rg;}
    void setJobTitle(std::string jt) { jobTitle = jt; }
    void setDepartment(std::string d) { department = d; }
    void setProjects(int p) { projects = p; }
    void setAvailableProjects(int ap) { availableProjects = ap; }

	std::string getResearchGroup() {return researchGroup;}
    std::string getJobTitle() { return jobTitle; }
    std::string getDepartment() { return department; }
    int getProjects() { return projects; }
    int getAvailableProjects() { return availableProjects; }
    
private:
    std::string researchGroup, jobTitle, department, email;
    int projects, availableProjects;
};