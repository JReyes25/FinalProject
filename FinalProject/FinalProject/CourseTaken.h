#ifndef COURSETAKEN_H
#define COURSETAKEN_H

#include <string>
#include "Course.h"
using namespace std;

class CourseTaken:public Course {
public:
	CourseTaken();

	void setInstructorName(string instructorName);
	void setGrade(string grade);
	string getInstructorName();
	string getGrade();

private:
	string instructorName;
	string grade;
};
#endif // !COURSETAKEN_H


