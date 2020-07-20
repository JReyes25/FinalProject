#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Course.h"
#include "CourseTaken.h"
#include "CourseInProgress.h"

using namespace std;

int const CURRENT_SEMESTER = 3;
string const STUDENT_NAME = "Jorge Reyes";

int main() {
	ifstream InProgressCourses;
	ifstream takenCourses;

	string course;
	string temp;

	vector<CourseTaken> coursesTaken;
	vector<CourseInProgress> coursesInProgress;

	CourseInProgress tempInProgressCourse;
	CourseTaken tempTakenCourse;

	int entriesCount = 0;
	int i = 0;
	int j = 0;

	//Opens file with Required Courses
	InProgressCourses.open("InProgress_Courses.txt");
	if (InProgressCourses.is_open()) {
		cout << "In Progress Courses file opened." << endl;

		//Goes through file until it reaches end
		while (!InProgressCourses.eof()) {
			//Puts every entry in a string course
			getline(InProgressCourses, course);

			j = course.find(',');
			temp = course.substr(0, j);
			course = course.substr(j + 1);
			tempInProgressCourse.setTitle(temp);

			j = course.find(',');
			temp = course.substr(0, j);
			course = course.substr(j + 1);
			tempInProgressCourse.setDescription(temp);

			j = course.find(',');
			temp = course.substr(0, j);
			course = course.substr(j + 1);
			tempInProgressCourse.setCourseNum(temp);

			j = course.find(',');
			temp = course.substr(0, j);
			course = course.substr(j + 1);
			tempInProgressCourse.setSemester(temp);

			j = course.find(',');
			temp = course.substr(0, j);
			course = course.substr(j + 1);
			tempInProgressCourse.setCredit(temp);

			j = course.find(',');
			temp = course.substr(0, j);
			course = course.substr(j + 1);
			tempInProgressCourse.setInstructorName(temp);

			coursesInProgress.push_back(tempInProgressCourse);

			entriesCount++;
		}
		cout << entriesCount << " In Progress Courses Loaded." << endl;
	}
	else {
		cout << "Fail to open \"InProgress_Courses.txt\".\nAborting program." << endl;
		return 0;
	}


	entriesCount = 0;

	//Opens file with Taken Courses
	takenCourses.open("Taken_Courses.txt");
	if (takenCourses.is_open()) {
		cout << "Taken Courses file opened." << endl;

		//Goes through file until it reaches end
		while (!takenCourses.eof()) {
			//Puts every entry in a string course
			getline(takenCourses, course);

			j = course.find(',');
			temp = course.substr(0, j);
			course = course.substr(j + 1);
			tempTakenCourse.setTitle(temp);

			j = course.find(',');
			temp = course.substr(0, j);
			course = course.substr(j + 1);
			tempTakenCourse.setDescription(temp);

			j = course.find(',');
			temp = course.substr(0, j);
			course = course.substr(j + 1);
			tempTakenCourse.setCourseNum(temp);

			j = course.find(',');
			temp = course.substr(0, j);
			course = course.substr(j + 1);
			tempTakenCourse.setSemester(temp);

			j = course.find(',');
			temp = course.substr(0, j);
			course = course.substr(j + 1);
			tempTakenCourse.setCredit(temp);

			j = course.find(',');
			temp = course.substr(0, j);
			course = course.substr(j + 1);
			tempTakenCourse.setInstructorName(temp);

			j = course.find(',');
			temp = course.substr(0, j);
			course = course.substr(j + 1);
			tempTakenCourse.setGrade(temp);

			coursesTaken.push_back(tempTakenCourse);

			entriesCount++;
		}
		cout << entriesCount << " Taken Courses Loaded." << endl;
	}
	else {
		cout << "Fail to open \"Required_Courses.txt\".\nAborting program." << endl;
		return 0;
	}

	cout << endl << "Transcript for " + STUDENT_NAME << endl;

	cout << "Sem CourseID Course Name     Credits Grade" << endl;
	for (i = 1; i < CURRENT_SEMESTER; i++){
		for (j = 0; j < coursesTaken.size(); i++) {
			if (stoi(coursesTaken.at(j).getSemester()) == i) {
				cout << coursesTaken.at(j).getSemester() + " " + coursesTaken.at(j).getCourseNum() + " ";
				cout << coursesTaken.at(j).getTitle() + " " + coursesTaken.at(j).getCredit() + " " + coursesTaken.at(j).getGrade();
			}
		}
	}
	
	return 0;
}