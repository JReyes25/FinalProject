#include "CourseInProgress.h"

using namespace std;

CourseInProgress::CourseInProgress() {
	this->title = "none";
	this->courseNumber = "none";
	this->credit = "none";
	this->description = "none";
	this->semester = "none";
	this->instructorName = "none";
}

void CourseInProgress::setInstructorName(string instructor) {
	this->instructorName = instructor;
}

string CourseInProgress::getInstructorName() {
	return this->instructorName;
}

