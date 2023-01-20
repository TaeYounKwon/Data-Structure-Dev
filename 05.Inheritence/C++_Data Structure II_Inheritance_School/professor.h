/*
 * Title:		professor.cpp
* Purpose:		proclaim what I will use for professor class
* Author:		Jack Kweon
 * Date:		4/28 2021
 */

#include <string>
#include <iostream>
using std::string;
using std::ostream;
using std::istream;
#include "date.h"
#include "person.h"
#ifndef SCHOOL_INHERITANCE_PROFESSOR_H
#define SCHOOL_INHERITANCE_PROFESSOR_H

enum Rank {ASSISTANT_PROFESSOR, ASSOCIATE_PROFESSOR, PROFESSOR};

class Professor:public Person {
    string _department;
    Date _hireDate;
    Rank _rank;
    float _salary;
public:
    Professor();
    Professor(const string& name, const Date& birthDay, const string& department);
    Professor(const string& name, const Date& birthDay, string  department, const Date &hireDate);
    Professor(const string &name, const Date& birthDay, const string& department, const Date &hireDate, Rank rank, float salary);
    string ToString()const;
    string GetDepartment()const;
    Date GetHiredDay()const
    {
        return Date(_hireDate); ///HiredDay accessor
                               ///@return the hired date of the professor
    }
    void Read(istream& input);
    void Write(ostream& output)const;
    void Raise(float percentage);
    void Promote();
    Rank GetRank()const;
    float GetSalary()const;
};



#endif
