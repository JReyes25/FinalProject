#include <iostream>

using namespace std;

class Course {
public:
	Course() {
		this->courseNumber = "0";
	}

private:
	string title;
	string description;
	int credit;
	string courseNumber;
	string semester;
};