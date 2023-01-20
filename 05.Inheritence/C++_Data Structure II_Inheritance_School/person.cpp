/**
 * Title:		professor.cpp
* Purpose:		Build functions for person.cpp
* Author:		Jack Kweon
 * Date:		4/28 2021
 */

#include <string>
#include <iostream>
#include <sstream>
#include "person.h"

using std::istream;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::ostream;
using std::string;
using std::stringstream;
/**
 * Date Default Constructor
 * By default a name will be noName, and the birthday will be current time
 */
Person::Person():_name("noName"),_birthDay(Date::Now())
{

}
/**
 * Person Constructor
 * Creates a name, and birthDay given its parameter. If the date is invalid it sets
 * the year, the month and the day to zero(from the Date class).
 */
Person::Person(string name, const Date &birthDay): _name(std::move(name)), _birthDay(birthDay)
{

}
/**
 * Person Constructor
 * getting specific dates values from the user.
 * Creates a name, and birthDay given its parameter. If the date is invalid it sets
 * the year, the month and the day to zero(from the Date class).
 */
Person::Person(string name, size_t year, size_t month, size_t day)
        : _name(std::move(name)), _birthDay(Date(year, month, day)) {

}
/**
 * String representation of person
 * Creates a string that represents the person. The string will have the format:
 * name yyyy mm dd  name is name. yyyy is the year. mm is the month, dd is the day,
 *  If the day has a single digit, the day will be filled with a space.
 * Relies in asctime function of ctime
 * @return the string representation of the person.
 */
string Person::ToString() const {
    stringstream retVal;
    retVal <<"{name: " << _name << ", birthday: " << _birthDay.ToString()<<"}";
    return retVal.str();
}
/**
 * name Accessor
 * @return the name of the date
 */
string Person::GetName() const {
    return _name;
}
/**
 * age Accessor
 * @return the age of the date
 */
size_t Person::GetAge() const {
    Date date;
    size_t _age=(date.Difference(_birthDay)/365);
    return _age;
}
/**
 * read the file from the user
 * if input fails, then it will not have any value.
 */
void Person::Read(istream &input)
{string _nameCheck;
 Date _dateCheck;
    input>>_nameCheck;
    if(input.fail())
    {
        input.clear();
        input.ignore(255,'n');
    }
    else{
        _name=_nameCheck;
    }
    input>>_dateCheck;
    if(input.fail())
    {
        input.clear();
        input.ignore(255,'n');
    }
    else
    {
        _birthDay=_dateCheck;
    }
}

/**
 * write the file from the user
 */
void Person::Write(ostream &output) const {
    output << _name << " " << _birthDay;
}