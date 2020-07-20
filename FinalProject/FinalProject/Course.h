#ifndef COURSE_H
#define COURSE_H
#include <string>

using namespace std;

class Course {
public:
	Course();
	void setTitle(string title);
	void setDescription(string description);
	void setCredit(string credit);
	void setCourseNum(string courseNumber);
	void setSemester(string semester);

	string getTitle();
	string getDescription();
	string getCredit();
	string getCourseNum();
	string getSemester();

protected:
	string title;
	string description;
	string credit;
	string courseNumber;
	string semester;
};
#endif // !COURSE_H


