#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Course.h"
#include "CourseTaken.h"

using namespace std;

int const CURRENT_SEMESTER = 3;
string const STUDENT_NAME = "Jorge Reyes";

int main() {
	ifstream courses;
	ifstream takenCourses("Taken_Courses.txt");

	string course;

	vector<Course> coursesRequired;
	vector<CourseTaken> coursesTaken;
	vector<Course> coursesInProgress;

	int entriesCount = 0;

	courses.open("Reuired_Courses.txt");
	if (courses.is_open()) {
		cout << "Required Courses file opened." << endl;
	}
	else {
		cout << "Fail to open \"Required_Courses.txt\".\nAborting program.";
		return 0;
	}


	cout << "Transcript for " + STUDENT_NAME << endl;

	if (takenCourses.is_open()) {
		cout << "Taken Courses file opened." << endl;
		while (!takenCourses.eof()) {
			cout << course << endl;
			getline(takenCourses, course);
			entriesCount++;
		}
		cout << entriesCount << " Taken Courses Loaded." << endl;

	}
	
	return 0;
}