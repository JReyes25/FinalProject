#include "CourseTaken.h"

CourseTaken::CourseTaken() {
	this->title = "none";
	this->courseNumber = "none";
	this->credit = "none";
	this->description = "none";
	this->grade = "none";
	this->semester = "none";
	this->instructorName = "none";
}

void CourseTaken::setInstructorName(string instructorName) {
	this->instructorName = instructorName;
}
void CourseTaken::setGrade(string grade) {
	this->grade = grade;
}


string CourseTaken::getInstructorName() {
	return this->instructorName;
}
string CourseTaken::getGrade() {
	return this->grade;
}