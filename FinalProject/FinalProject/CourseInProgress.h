#ifndef COURSEINPROGRESS_H
#define COURSEINPROGRESS_H

#include <string>
#include "Course.h"

using namespace std;

class CourseInProgress : public Course {
public:
	CourseInProgress();

	void setInstructorName(string instructor);
	string getInstructorName();
private:
	string instructorName;
};


#endif // !COURSEINPROGRESS_H
