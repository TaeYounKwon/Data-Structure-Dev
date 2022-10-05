/*
 * Title:		professor.cpp
* Purpose:		proclaim what I will use for student class
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
#ifndef SCHOOL_INHERITANCE_STUDENT_H
#define SCHOOL_INHERITANCE_STUDENT_H



class Student:public Person {
    string _major;
    size_t _credits;
    float _gpa;
public:
    Student();
    Student(const string& name, const Date& birthDay);
    Student(const string &name, const Date& birthDay, const string& major);
    Student(const string &name, const Date& birthDay, const string& major, const float& gpa, const size_t& credit);
    string ToString()const;
    string GetMajor()const;
    void Read(istream& input);
    void Write(ostream& output)const;
    void AddGrade(float grade, size_t credits);
    float GetGPA()const;
    size_t GetCredits()const;
};



#endif
