#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>

#include "userData.h"
#include "userTest.h"

using namespace std;

userTest::userTest()
{
    testRows=0;
}
//constructor
userTest::userTest(int testRows)
{
    this->testRows=testRows;
}

//function to test 1
int userTest::SetTest() {
    //clear all previous data
    userData();

    //Set up the pre-set values
    string testHeader="Emp_ID,Name_Prefix,First_Name,MI,Last_Name,Gender,E_Mail,Father's_Name,Mother's_Name,Mother's_Maiden_Name,"
                      "Date_of_Birth,Age,Weight_in_Kgs.,Date_of_Joining,Salary,Last_%_Hike,SSN,Phone_No._,Place_Name,County,City,State,Zip,Region,User_Name";
    string data1 = "969964,Mr.,Jack,T,Kweon,M,tempest0211@gmail.com,Paul_Kweon,Alice_Kweon,Perez,"
                   "1/12/1980,37.57,56,8/23/2016,147641,25%,733-26-1976,010-4432-4690,Nowhere,Seoul,Seoul,OR,97230,Midwest,kweont";
    string data2 = "278556,Prof.,James,,Moriarty,M,villainthebest@amazon.net,Peter_Moriarty,Andrea_Moriarty,Flores,"
                   "7/28/1993,24.02,81,8/18/2016,122226,14%,013-94-5886,205-621-4872,Ohatchee,Calhoun,Ohatchee,AL,36271,South,villain";
    string data3 = "639892,Dr.,who,,Mystery,M,englishman@hotmail.com,Carlos_Mystery,Anna_Mystery,Hayes,"
                   "10/8/1994,22.82,89,7/9/2016,129774,15%,171-86-3825,228-245-5000,Biloxi,Harrison,Biloxi,MS,39532,South,monsterHunter";
    string filename = "Test Number 1";
    //print out preset
    cout<<"Pre-set data is written below."<<endl;
    cout<<"First Data: "<<data1<<endl;
    cout<<"Second Data: "<<data2<<endl;
    cout<<"Third Data: "<<data3<<endl<<endl;

    //add the pre-set values into test
    vector<string> test;
    test.clear();
    test.push_back(data1);
    test.push_back(data2);
    test.push_back(data3);

    //Set new file name
    SetFileName(filename);

    //Set new numbers of rows
    int numb = test.size();
    SetRows(numb);

    //Set new header
    SetHeader(testHeader,',');

    //Set new data into userData
    SetDataInfo(test);
    SetOutputLength();

    //testRow will determine if the return rows either have error or no error.
    testRows=numb;
    return testRows;
}

//function to print test1
void userTest::PrintTest1()
{
    cout << "Reading the data from: " << fileName << endl ;
    cout<<"<<PrintTest 1>>"<<endl;
    cout << "|";
    int lineCount=3;
    for (int i = 0; i < headerSaved.size()-1; ++i)
    {
        cout << left << setw(outputManager.at(i)) << headerSaved.at(i) << "|";

    }
    cout << endl;
    PrintData();
    cout<<"It should print out "<<lineCount<<" lines"<<endl;
    if (testRows == lineCount) {
        cout << "Right number of Data printed!" << endl << endl;
    }
    else
    {
        cout << "Wrong number of Data printed..." << endl << endl;
    }
}

//function to call test2
void userTest::Test2()
{
    SetTest();
    int numbRows=EmployeeClusterReport();
    if(numbRows==testRows)
    {
        cout << "Right number of Data printed!" << endl << endl;
    }
    else
    {
        cout << "Wrong number of Data printed..." << endl << endl;
    }

}
