/*
 * Title:		professor.cpp
* Purpose:		proclaim what I will use for person class
* Author:		Jack Kweon
 * Date:		4/28 2021
 */
#include <string>
#include "date.h"
#include <iostream>
using std::string;
using std::ostream;
using std::istream;
#ifndef SCHOOL_INHERITANCE_PERSON_H
#define SCHOOL_INHERITANCE_PERSON_H

class Person {
string _name;
Date _birthDay;
public:
    Person();
    Person(string  _name,const Date& birthDay);
    Person(string name, size_t year, size_t month, size_t day);
    virtual Date GetBirthday()const
    {
        return Date(_birthDay);///birthDay accessor
                               ///@return the birth date of the person
    }

    virtual string ToString()const;
    virtual string GetName()const;
    virtual size_t GetAge()const;
    virtual void Read(istream& input);
    virtual void Write(ostream& output)const;

};


#endif
