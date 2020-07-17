#include <iostream>
#include "Course.h"

using namespace std;

class CourseTaken:Course {
public:
	CourseTaken();
private:
	string instructor;
	double grade;

};