/**
 * Title:		main.cpp
* Purpose:		operates and runs all the functions from each classes
* Author:		Jack Kweon
 * Date:		4/28 2021
 */
#include "date.h"
#include "person.h"
#include "student.h"
#include "professor.h"
#include <fstream>
#include <iostream>

#include <vector>
using std::ostream;
using std::istream;
using std::ifstream;
using std::ofstream;
using std::cin;
using std::string;
using std::cerr;
using std::cout;
using std::endl;
using std::vector;

size_t Menu();

int main() {
    vector<Person*> people; // This is the only vector you need, remember to release the memory
	int userOption;
    Person person;
    Student student;
    Professor professor;
    size_t _countTotal=0;
	while ( (userOption = Menu()) != 15) {

	    ///add person
        if (userOption == 1)
        {
            string _name;
            size_t _year, _month, _date;
            cout << "Name: ";
            cin >> _name;
            ///Check if the dates are valid
            ///if valid then save the data, and count the number of people inserted
            while(true)
            {
                cout << "Birth date yyyy mm dd: ";
                cin >> _year;
                cin >> _month;
                cin >> _date;
                ///put the user data to person
                people.push_back(new Person(_name, Date(_year, _month, _date)));
                size_t _loopCount=0;
                for (Person *person1: people)
                {
                    ///if its not valid then remove the data
                    ///calculated by the difference between user birthday and the current day
                    ///the difference should be less than 1900
                    if (_countTotal==_loopCount&&person1->GetAge() > 1900)
                    {
                        cout << "Invalid Date!"<<endl;
                        goto endloop1;

                    }
                    ///save the data if it's valid
                    else if(_countTotal==_loopCount&&person1->GetAge() < 1900)
                    {
                        goto outLoop1;
                    }
                    else
                        _loopCount++;
                 }
                endloop1:
                people.pop_back();
            }
            outLoop1:
            cout << "Person inserted in position: " << people.size() - 1<<endl;
            _countTotal++;


        ///ADD STUDENT
        }else if (userOption == 2){
            string _name;
            size_t _year, _month, _date;
            string _major;
            cout<<"Name:";
            cin>>_name;
            ///Check if the datas are valid
            ///same method as above
            while(true)
            {
                cout << "Birth date yyyy mm dd: ";
                cin >> _year;
                cin >> _month;
                cin >> _date;

                people.push_back(new Person(_name, Date(_year, _month, _date)));
                size_t _loopCount=0;
                for (Person *person2: people)
                {
                    if (_countTotal==_loopCount&&person2->GetAge() > 1900)
                    {
                        cout << "Invalid Date!"<<endl;
                        goto endloop2;

                    }
                    else if(_countTotal==_loopCount&&person2->GetAge() < 1900)
                    {
                        goto outLoop2;
                    }
                    else
                        _loopCount++;
                }
                endloop2:
                people.pop_back();
            }
            outLoop2:
            people.pop_back();
            cout<<"Major: ";
            cin>>_major;
            _countTotal++;
            people.push_back(new Student(_name, Date(_year, _month, _date),_major));
            cout<<"Student inserted in position: "<<people.size()-1<<endl;

        ///ADD PROFESSOR
        }else if (userOption == 3){		// Add Professor
            string _name;
            size_t _year, _month, _date, _yearHired, _monthHired, _dateHired;
            string _department;
            cout<<"Name:";
            cin>>_name;
            ///Same method as above
            while(true)
            {
                cout << "Birth date yyyy mm dd: ";
                cin >> _year;
                cin >> _month;
                cin >> _date;
                people.push_back(new Person(_name, Date(_year, _month, _date)));
                size_t _loopCount=0;
                for (Person *person3: people)
                {
                    if (_countTotal==_loopCount&&person3->GetAge() > 1900)
                    {
                        cout << "Invalid Date!"<<endl;
                        goto endloop3;
                    }
                    else if(_countTotal==_loopCount&&person3->GetAge() < 1900)
                    {
                        goto outLoop3;
                    }
                    else
                        _loopCount++;
                }
                endloop3:
                people.pop_back();
            }
            outLoop3:
            people.pop_back();
            cout<<"Department: ";
            cin>>_department;
            ///Check if the hire dates are also valid
            while(true)
            {
                cout<<"Hire date yyyy mm dd: ";
                cin>>_yearHired;
                cin>>_monthHired;
                cin>>_dateHired;
                people.push_back(new Person(_name, Date(_yearHired,_monthHired, _dateHired)));
                size_t _loopCount=0;
                for (Person *person4: people)
                {
                    if (_countTotal==_loopCount&&person4->GetAge() > 1900)
                    {
                        cout << "Invalid Date!"<<endl;
                        goto endloop4;
                    }
                    else if(_countTotal==_loopCount&&person4->GetAge() < 1900)
                    {
                        goto outLoop4;
                    }
                    else
                        _loopCount++;
                }
                endloop4:
                people.pop_back();
            }
            outLoop4:
            people.pop_back();
            ///if valid then save the Data and count the people inserted
            _countTotal++;
            people.push_back(new Professor(_name, Date(_year, _month, _date),_department, Date(_yearHired,_monthHired,_dateHired)));
            cout<<"Professor inserted in position: "<<people.size()-1<<endl;

        ///List all people
        }else if (userOption == 4){
            for (Person *person5: people)   ///if there is a pointer value then print the data
            {
                cout << person5->ToString() << endl;
            }

        ///Print only student
		}else if (userOption == 5){

            for(Person *person5: people)
            {
                if (dynamic_cast<Student *>(person5)!=nullptr)///if there is a pointer value then print the data
                {
                    cout<<person5->ToString()<<endl;
                }

            }

        ///Print only Professor
		}else if (userOption == 6){

            for(Person *person6: people)
            {
                if (dynamic_cast<Professor *>(person6)!=nullptr)///if there is a pointer value then print the data
                {
                    cout<<person6->ToString()<<endl;
                }

            }
        ///Print only person
		}else if (userOption == 7){
            for (Person *person7: people)
            {                           ///if studnet or professor pointer exist then skip
                if (dynamic_cast<Professor *>(person7)!=nullptr||dynamic_cast<Student *>(person7)!=nullptr)
                {
                    continue;
                }
                else
                     cout << person7->ToString() << endl;
            }

        /// Calculate Average GPA
		}else if (userOption == 8){
            float _gpaAverage;
            float _gpaSum=0;
            size_t _count=0;
            for (Person *person8: people)
            {   ///count the number of student and total gpa and calculate the average
                if (dynamic_cast<Student *>(person8) != nullptr)
                {
                    _gpaSum = _gpaSum + dynamic_cast<Student *>(person8)->GetGPA();
                    _count++;
                }
            }
            _gpaAverage=_gpaSum/_count++;
            cout<<"The average GPA of the students is: "<<_gpaAverage<<endl;

        /// Calculate Average Salary
		}else if (userOption == 9){
            float _salaryAverage;
            float _salarySum=0;
            size_t _count=0;
            for (Person *person9: people)
            {   ///count the number of professor and total salary and calculate the average
                if (dynamic_cast<Professor *>(person9) != nullptr)
                {
                    _salarySum = _salarySum + dynamic_cast<Professor *>(person9)->GetSalary();
                    _count++;
                }
            }
            _salaryAverage=_salarySum/_count++;
            cout<<"The average salary of the professors is: "<<_salaryAverage<<endl;

        ///Input Grades for students
		}else if (userOption == 10) {
            size_t _count = 0;
            for (Person *person10: people)  ///show user which position students are located at
            {
                if (dynamic_cast<Student *>(person10) != nullptr)
                {
                    cout << _count << " " << person10->ToString() << endl;
                    _count++;
                }
                else
                    _count++;
            }
            _count = 0;
            size_t _numbStudent;
            ///let user to input the data value
            while(true)
            {
                cout << "Number of student to input grades to: ";
                cin >> _numbStudent;
                if (_numbStudent > people.size()-1)
                {
                    cout << "Position out of range!" << endl;
                    goto middlePoint;
                }
                for (Person *person11: people)
                {
                    if (dynamic_cast<Student *>(person11) != nullptr && _count == _numbStudent)
                    {
                        float _grade;
                        size_t _credit;
                        bool _outLoop=true;

                        while(_outLoop)
                        {
                            cout << "Grade of the student [0.0 to 4.0 scale]: ";
                            cin >> _grade;
                            if (_grade > 4.0 || _grade < 0.0)
                            {
                                cout << "Invalid grade value, make sure [0.0, 4.0]" << endl;
                                cin.clear();
                                cin.ignore(255, '\n');
                            }
                            else if (cin.fail())
                            {
                                cout<< "Incorrect input!" << endl;
                                cin.clear();
                                cin.ignore(255, '\n');
                            }
                            else
                            {
                                _outLoop=false;
                            }
                        }

                        while(!_outLoop)
                        {
                            cout << "Credits {1, 2, 3, 4, 5}: ";
                            cin >> _credit;
                            if(_credit<1||_credit>5)
                            {
                                cout<<"Invalid grade value, make sure {1, 2, 3, 4, 5}"<<endl;
                                cin.clear();
                                cin.ignore(255, '\n');
                            }
                            else if (cin.fail())
                            {
                                cout<< "Incorrect input!" << endl;
                                cin.clear();
                                cin.ignore(255, '\n');

                            }
                            else
                            {
                                _outLoop=true;
                            }
                        }
                        dynamic_cast<Student *>(person11)->AddGrade(_grade, _credit);
                        goto lastPoint;
                    }

                    else if (dynamic_cast<Student *>(person11) == nullptr && _count == _numbStudent)
                    {
                        cout << _count << " " << person11->ToString() << " is not a student" << endl;
                        goto middlePoint;
                    }
                    else
                        _count++;
                }
                middlePoint:
                _count = 0;
            }
            lastPoint:
            cout<<"";
        /// Promote Professor
		}else if (userOption == 11){
            size_t _count = 0;
            for (Person *person12: people)
            {
                if (dynamic_cast<Professor *>(person12) != nullptr)
                {
                    cout << _count << " " << person12->ToString() << endl;
                    _count++;
                }
                else
                    _count++;
            }
            _count = 0;
            size_t _numbProfessor;
            cout << "Number of professor to promote: ";
            cin >> _numbProfessor;
            if(_numbProfessor>people.size()) {
                cout << "Out of Range!! Please try again."<<endl;
                goto endLoop2;
            }
            for (Person *person13: people) {
                if (dynamic_cast<Professor *>(person13) != nullptr && _count == _numbProfessor)
                {
                    dynamic_cast<Professor *>(person13)->Promote();
                    goto endLoop2;
                }
                else if (dynamic_cast<Professor *>(person13) == nullptr && _count == _numbProfessor) {
                    cout << _count << " " << person13->ToString() << " is not a Professor." << endl;
                    _count = 0;
                    goto endLoop2;
                } else
                    _count++;
            }
            endLoop2:
            cout<<"";
        /// Give Raise to Professor
		}else if (userOption == 12){
            size_t _count = 0;
            for (Person *person14: people)
            {
                if (dynamic_cast<Professor *>(person14) != nullptr)
                {
                    cout << _count << " " << person14->ToString() << endl;
                    _count++;
                }
                else
                    _count++;
            }
            _count = 0;
            size_t _numbProfessor;
            float _raise;
            cout << "Number of professor to give raise: ";
            cin >> _numbProfessor;
            if(_numbProfessor>people.size())
            {
                cout << "Out of Range!! Please try again."<<endl;
                goto endLoop3;
            }
            for (Person *person15: people)
            {
                if (dynamic_cast<Professor *>(person15) != nullptr && _count == _numbProfessor)
                {
                    cout<<"Raise to the professor [0.0, 50.0] ";
                    cin>>_raise;
                    dynamic_cast<Professor *>(person15)->Raise(_raise);
                    goto endLoop3;
                }
                else if (dynamic_cast<Professor *>(person15) == nullptr && _count == _numbProfessor)
                {
                    cout << _count << " " << person15->ToString() << " is not a Professor." << endl;
                    _count = 0;
                    goto endLoop3;
                }
                else
                    _count++;
            }
            endLoop3:
            cout<<"";
		}

        ///user read file
        else if (userOption == 13)
        {
            cout<<"Input filename: ";
            Date date;
            string _fileNameIn;
            char _direction;
            cin>>_fileNameIn;
            ifstream readFile(_fileNameIn);

            if (!readFile.is_open())
            {
                cout<<"Unable to open file."<<endl;
                goto endLoop5;
            }

            while(!readFile.eof())
            {
                readFile>>_direction;
                if(_direction=='P'||_direction=='p')
                {
                    person.Read(readFile);
                    people.push_back((new Person(person.GetName(),person.GetBirthday())));
                }
                else if(_direction=='S'||_direction=='s')
                {   student.Read(readFile);
                    people.push_back((new Student(student.GetName(),student.GetBirthday(),student.GetMajor(),student.GetGPA(),student.GetCredits())));
                }
                else if(_direction=='R'||_direction=='r')
                {
                    professor.Read(readFile);
                    people.push_back((new Professor(professor.GetName(),professor.GetBirthday(),professor.GetDepartment(),professor.GetHiredDay(),professor.GetRank(),professor.GetSalary())));
                }

                else {
                    goto endLoop5;
                }
                _direction='A';

            }
            endLoop5:
            readFile.close();

        ///user write File
		}else if (userOption == 14){
		    string _fileName;
            cout<<"Input filename: ";
            cin>>_fileName;
            ofstream outFile(_fileName);
            for(Person *person16: people)
            {
                if (dynamic_cast<Student *>(person16)!=nullptr||dynamic_cast<Professor *>(person16)!=nullptr)
                {
                    person16->Write(outFile);
                }
                else
                {
                    outFile<<"P ";
                    person16->Write(outFile);
                }
                outFile<<endl;
            }
            outFile.close();

		}
	}
	people.clear();
	return 0;
}

size_t Menu(){
	int option = 0;
	while(true){
		cout << "-------------------------------------------" << endl;
		cout << "1. Add a Person" << endl;
		cout << "2. Add a Student" << endl;
		cout << "3. Add a Professor" << endl;
		cout << "4. List all People" << endl;
		cout << "5. Show Students Report" << endl;
		cout << "6. Show Professors Report" << endl;
		cout << "7. Show People (not Professors or Students)" << endl;
		cout << "8. Calculate all Students Average GPA" << endl;
		cout << "9. Calculate all Professors Average Salary" << endl;
		cout << "10. Input Grades to Student" << endl;
		cout << "11. Promote Professor" << endl;
		cout << "12. Give Raise to Professor" << endl;
		cout << "13. Load Data from File" << endl;
		cout << "14. Write Data to File" << endl;
		cout << "15. Exit" << endl;

		cin >> option;
		if (cin.fail()){
			cin.clear();
			cin.ignore(255, '\n');
			cerr << "Incorrect input!" << endl;
			continue;
		}
		if (option < 1 || option > 15){
			cerr << "Incorrect menu option!" << endl;
			continue;
		}
		break;
	}
	cout << endl;
	return static_cast<size_t>(option);

}
