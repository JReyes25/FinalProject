#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

#include "Course.h"
#include "CourseTaken.h"
#include "CourseInProgress.h"

using namespace std;

int const CURRENT_SEMESTER = 3;
string const STUDENT_NAME = "Jorge Reyes";

//Calculates a grade based on a letter grade and credits
double GetPointFromLetter(char letterGrade, int credits);

int main() {
	ifstream InProgressCourses;
	ifstream takenCourses;

	string course;
	string temp;

	vector<CourseTaken> coursesTaken;
	vector<CourseInProgress> coursesInProgress;

	CourseInProgress tempInProgressCourse;
	CourseTaken tempTakenCourse;

	//Will count total credits
	int entriesCount = 0;

	//Will count credits in one semester
	int semesterCreditCount = 0;

	int i = 0;
	int j = 0;

	//Will be used to calculate total GPA
	double totalGradePoints = 0.0;
	//Will be used to calculate GPA for one semester
	double semesterGradePoints = 0.0;

	//Opens file with Required Courses
	InProgressCourses.open("InProgress_Courses.txt");
	if (InProgressCourses.is_open()) {
		cout << "In-Progress Courses file opened." << endl;

		//Goes through file until it reaches end
		while (!InProgressCourses.eof()) {
			//Puts every entry in a string course
			getline(InProgressCourses, course);

			//Adds every data member to object tempInProgressCourse
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

			//Adds tempInProgressCourse to the vector with all courses in progress
			coursesInProgress.push_back(tempInProgressCourse);

			entriesCount++;
		}
		cout << entriesCount << " In-Progress Courses Loaded." << endl;
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

			//Adds every data member to object tempInProgressCourse
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

			//Adds tempInProgressCourse to the vector with all courses in progress
			coursesTaken.push_back(tempTakenCourse);

			entriesCount++;
		}
		cout << entriesCount << " Taken Courses Loaded." << endl;
	}
	else {
		cout << "Fail to open \"Required_Courses.txt\".\nAborting program." << endl;
		return 0;
	}

	cout << endl << "Transcript for " + STUDENT_NAME << endl << endl;

	entriesCount = 0;

	cout << "Courses Taken for Credit:" << endl;
	cout << "Sem CourseID Course Name     Credits Grade" << endl;

	for (i = 1; i < CURRENT_SEMESTER; i++){
		semesterCreditCount = 0;
		semesterGradePoints = 0.0;

		for (j = 0; j < coursesTaken.size(); j++) {
			if (stoi(coursesTaken.at(j).getSemester()) == i) {
				
				//Updates semester grade and total grade
				semesterGradePoints += GetPointFromLetter(coursesTaken.at(j).getGrade().at(0), stoi(coursesTaken.at(j).getCredit()));
				totalGradePoints += GetPointFromLetter(coursesTaken.at(j).getGrade().at(0), stoi(coursesTaken.at(j).getCredit()));
				
				//Displays courses information
				cout << " " << setw(3) << left << coursesTaken.at(j).getSemester();
				cout << setw(10) << left << coursesTaken.at(j).getCourseNum();
				cout << setw(18) << left << coursesTaken.at(j).getTitle();
				cout << setw(8) << left << coursesTaken.at(j).getCredit();
				cout << coursesTaken.at(j).getGrade() << endl;
				semesterCreditCount += stoi(coursesTaken.at(j).getCredit());
			}
		}

		cout << setw(32) << left << "";
		cout << setw(24) << left << "Semester credit: ";
		cout << semesterCreditCount << endl;

		entriesCount += semesterCreditCount;

		cout << setw(32) << left << "";
		cout << setw(24) << left << "Semester GPA: ";
		cout << fixed << setprecision(2) <<  (semesterGradePoints)/ (double)semesterCreditCount << endl;
	}

	cout << "Courses In Progress:" << endl;
	for ( i = 0; i < coursesInProgress.size(); i++){
		cout << " ";
		cout << setw(3) << left << coursesInProgress.at(i).getSemester();
		cout << setw(10) << left << coursesInProgress.at(i).getCourseNum();
		cout << setw(18) << left << coursesInProgress.at(i).getTitle();
		cout << coursesInProgress.at(i).getCredit() << endl;
	}
	cout << endl;
	cout << setw(32) << "";
	cout << setw(24) << left << "Total credits: " << entriesCount << endl;
	cout << setw(32) << "";
	cout << setw(24) << left << "Total GPA: ";
	cout << fixed << setprecision(2) << (totalGradePoints)/ (double)entriesCount << endl;
	
	return 0;
}

double GetPointFromLetter(char letterGrade, int credits) {
	double points;

	switch (letterGrade) {
	case 'A':
		points = 4.0;
		break;
	case 'B':
		points = 3.0;
		break;
	case 'C':
		points = 2.0;
		break;
	default:
		points = 0.0;
		break;
	}

	points *= credits;
	return points;
}