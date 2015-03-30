#pragma once

class Person
{
private:
	std::string name;
    std::string email;
	int IDnumber;
public:
	std::string getName() {return name;}
    void setName(std::string n) { name = n; }

    int getIDnumber() { return IDnumber; }
    void setIDnumber(int id) { IDnumber = id; }

    std::string getEmail() { return email; }
    void setEmail(std::string e) { email = e; }
};