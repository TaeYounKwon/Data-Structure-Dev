/**
 * Title:		professor.cpp
* Purpose:		Build functions for professor.cpp
* Author:		Jack Kweon
 * Date:		4/28 2021
 */

#include "date.h"
#include "person.h"
#include "professor.h"
#include <string>
#include <sstream>
using std::string ;
using std::stringstream ;
using std::endl;


/**
 * Professor Default Constructor
 * same default value as parents class, undecided for the default department value
 * and hireDate will be current day for the default value
 * rank will be ASSISTANT_PROFESSOR, and salary will be 60000 for the default value.
 */
Professor::Professor():Person("noName",Date::Now()),_department("Undecided"),_hireDate(Date::Now()),_rank(ASSISTANT_PROFESSOR),_salary(60000)
{

}
/**
 * Professor Constructor
 * Creates a name, and birthDay given its parameter. If the date is invalid it sets
 * the year, the month and the day to zero(from the Date class).
 */
Professor::Professor(const string& name, const Date& birthDay, const string& department)
:Person(name,birthDay), _department(department)
{

}
/**
 * Professor Constructor
 * get each values from the user and set the data inside of the program.
 * if the hireDate is less than 5 years then the rank and salary will be ASSISTANT_PROFESSOR,60000
 * or if it's more or equal to than 5 years, then rank and salary will be ASSOCIATE_PROFESSOR, 70000
 * else it will be PROFESSOR, AND 75000
 */
Professor::Professor(const string& name, const Date& birthDay, string  department, const Date &hireDate)
: Person(name,birthDay), _department(std::move(department)), _hireDate(Date(hireDate))
{

    Date date;
    if ((date.Difference(_hireDate)/365)<5)
    {
        _rank=ASSISTANT_PROFESSOR;
        _salary=60000;
    }
    else if (date.Difference(_hireDate) / 365 < 10) {
        _rank = ASSOCIATE_PROFESSOR;
        _salary = 70000;
    } else {
        _rank = PROFESSOR;
        _salary = 75000;
    }

}
/**
 * Professor Constructor
 * get each values from the user and set the data inside of the program.
 * Specifically made it in order to read and save the user file.
 */
Professor::Professor(const string &name, const Date& birthDay, const string& department, const Date &hireDate, Rank rank, float salary)
:Person(name, birthDay), _department(department),_hireDate(Date(hireDate)),_rank(rank), _salary(salary)
{
    Date date;
    if ((date.Difference(_hireDate)/365)<5)
    {
        _rank=ASSISTANT_PROFESSOR;
        _salary=60000;
    }
    else if (date.Difference(_hireDate) / 365 < 10) {
        _rank = ASSOCIATE_PROFESSOR;
        _salary = 70000;
    } else {
        _rank = PROFESSOR;
        _salary = 75000;
    }
}
/**
 * String representation of Professor
 * Creates a string that represents the Professor. The string will have the format:
 * name yyyy mm dd  name is name. yyyy is the year. mm is the month, dd is the day,
 *  If the day has a single digit, the day will be filled with a space.
 *  and then, it will print out department, rank, hire-date, and the salary.
 * @return the string representation of the Professor.
 */
string Professor::ToString()const{
    stringstream retVal;
    retVal<< "{Person: "<<Person::ToString() << ", department: " << _department
       << ", rank: " << _rank<<", hire-date: "<<_hireDate.ToString()<<", salary: "<<_salary<<"}";
    return  retVal.str();
}
/**
 * Rank Accessor
 * @return the Rank of the professor
 */
Rank Professor::GetRank()const {
return _rank;
}
/**
 * Salary Accessor
 * @return the Salary of the professor
 */
float Professor::GetSalary()const{
   return _salary;
}
/**
 * department Accessor
 * @return the department of the professor
 */
string Professor::GetDepartment() const {
    return _department;
}
/**
 * raise the professor's salary
 * it will get the % rate from the user
 * and will calculate the increased salary and save the value.
 */
void Professor::Raise(float percentage){
    _salary=_salary+(_salary*percentage)/100;
}
/**
 * Promote the professor's rank;
 * after user decide who to promote
 * it will incrase that person's rank and the salary
 * however, if the person is already a PROFESSOR
 * then there will be no change in rank and the salary.
 */
void Professor::Promote(){
    if(_rank==ASSISTANT_PROFESSOR)
    {
        _rank = static_cast<Rank>(_rank + 1);
        _salary=70000;
    }
    else if(_rank==ASSOCIATE_PROFESSOR)
    {
        _rank=static_cast<Rank>(_rank+1);
        _salary=75000;
    }
    else
    {
        _rank=static_cast<Rank>(_rank);
        _salary=75000;
    }

}

/**
 * read the file from the user
 * if input fails, then it will not have any value.
 * also, depends on the user input value, rank will be decided.
 * also if the user does not have or wrong rank value then
 * it will be set as default value(ASSISTANT_PROFESSOR)
 */
void Professor::Read(istream& input){
    size_t _rankValue;
    Person::Read(input);
    input >> _department >>  _rankValue >> _hireDate >> _salary;

    if (_rankValue==0)
    {
        _rank=ASSISTANT_PROFESSOR;
    }
    else if(_rankValue==1)
    {
        _rank=PROFESSOR;
    }
    else if(_rankValue==2)
    {
        _rank=ASSOCIATE_PROFESSOR;
    }
    else
        _rank=ASSISTANT_PROFESSOR;
}
/**
 * write the file for the user
 * it will print out the data from the parent class(PERSON)
 * and it will print out professor values
 */
void Professor::Write(ostream& output)const{
    output <<"R"<<" ";
    Person::Write(output);
    output<< " " << _department
          << " " << _rank<<" "<<_hireDate<<" "<<_salary;
}



