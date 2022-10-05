/**
 * Title:		professor.cpp
* Purpose:		Build functions for student.cpp
* Author:		Jack Kweon
 * Date:		4/28 2021
 */

#include "date.h"
#include "person.h"
#include "student.h"
#include <string>
#include <sstream>
using std::string ;
using std::endl;
using std::stringstream ;
/**
 * Student Default Constructor
 * By default a name will be noName, the birthday will be current time,
 * the major will be undecided, credit and gpa will be 0;
 */
Student::Student():Person("noName",Date::Now()),_major("undecided"),_credits(0),_gpa(0.0)
{

}
/**
 * Student Constructor
 * Creates a name, and birthDay given its parameter. If the date is invalid it sets
 * the year, the month and the day to zero(from the Date class).
 */
Student::Student(const string &name,const Date &birthDay):Person(name, birthDay)
{

}
/**
 * Student Constructor
 * Creates a name, birthDay, and major given its parameter. If the date is invalid it sets
 * the year, the month and the day to zero(from the Date class).
 */
Student::Student(const string &name, const Date& birthDay, const string& major)
:Person(name, birthDay),_major(major){

}
/**
 * Student Constructor
 * Creates a name, birthDay, and major given its parameter. If the date is invalid it sets
 * the year, the month and the day to zero(from the Date class).
 * especailly maded it up to recieve the data from txt file
 */
Student::Student(const string &name, const Date &birthDay, const string &major, const float &gpa,
                 const size_t &credit) {

}
/**
 * calculate the GPA
 * it will get GPA, and credit from the user and will automatically calculate the gpa.
 * if _credit is 0, then it will show the message below
 */
void Student::AddGrade(float grade, size_t credits){
    if(_credits !=0)
    {
        float _oldGradeTotal = _gpa * _credits;
        float _newGradeTotal = grade * credits;
        _credits = credits + _credits;
        _gpa = (_oldGradeTotal + _newGradeTotal) / _credits;

    }
    else
        std::cout<<"There is no credit from student"<<endl;
}

/**
 * GPA Accessor
 * @return the GPA of the student
 */
float Student::GetGPA()const{
    return _gpa;
}
/**
 * Credit Accessor
 * @return the Credit of the student
 */
size_t Student::GetCredits()const{
    return _credits;
}
/**
 * String representation of student
 * Creates a string that represents the student. The string will have the format:
 * name yyyy mm dd  name is name. yyyy is the year. mm is the month, dd is the day,
 *  If the day has a single digit, the day will be filled with a space.
 *  and then, it will print out student's major, gpa and the credits.
 * @return the string representation of the student.
 */
string Student::ToString()const{
    stringstream retVal;
    retVal<< "{Person: "<<Person::ToString() << ", major: " << _major
       <<", gpa: "<<_gpa<< ", credits: " << _credits<<"}";
    return  retVal.str();
}
/**
 * read the file from the user
 * if input fails, then it will not have any value.
 */
void Student::Read(istream& input){
    Person::Read(input);
    input>>_major>>_gpa>>_credits;

}
/**
 * write the file from the user
 */
void Student::Write(ostream& output)const{
    output <<"S"<<" ";
    Person::Write(output);
    output<<" "<<_major<<" "<<_gpa<<" "<< _credits;
}
/**
 * Major Accessor
 * @return the major of the student
 */
string Student::GetMajor() const {
    return _major;
}


