#include <iostream>

using namespace std;

#include "Course.h"

Course::Course() {
	this->title = "none";
	this->courseNumber = "none";
	this->credit = "none";
	this->description = "none";
	this->semester = "none";
}
void Course::setTitle(string title) {
	this->title = title;
}
void Course::setDescription(string description) {
	this->description = description;
}
void Course::setCredit(string credit) {
	this->credit = credit;
}
void Course::setCourseNum(string courseNum) {
	this->courseNumber = courseNum;
}
void Course::setSemester(string semester) {
	this->semester = semester;
}

string Course::getTitle() {
	return this->title;
}
string Course::getDescription() {
	return this->description;
}
string Course::getCredit() {
	return this->credit;
}
string Course::getCourseNum() {
	return this->courseNumber;
}
string Course::getSemester() {
	return this->semester;
}
