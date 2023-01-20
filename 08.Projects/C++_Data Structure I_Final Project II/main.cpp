#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include "userData.h"
#include "userTest.h"


void userMenu()
{   userData data;
    userTest test;
    char menuOption; // for user to choose the menu
    string csvFileName="../data_v1.csv"; //preset csv file name
    string userFile;
    string fileName;

    //Prompt user to select the menu
    cout<<"\nWELCOME TO JACK'S FINAL PROJECT!"<<endl;
    while(true)
    {   cout<<"Please select the Menu below.\n"<<endl;
        cout << "F - Read <data.csv> File" << endl;
        cout << "I - Read other data File" << endl;
        cout << "N - Phone Number List" << endl;
        cout << "D - Data Quality Report" << endl;
        cout << "E - Data Without Duplicates or Empty ID"<<endl;
        cout << "Y - Find the Employees that has Same Parents Report(My Custom Report)" << endl;
        cout << "C - Employee Cluster Report" << endl;
        cout << "P - Employee Pay Raise Report" << endl;
        cout << "R - Regional Raises Report" << endl;
        cout << "S - Sequence of All Reports (order: N,D,Y,C,P,R)" << endl;
        cout << "1 - Test01" << endl;
        cout << "2 - Test02" << endl;
        cout << "T - All Tests(order:1,2)" << endl;
        cout << "A - All Reports and All Tests(order: S,T)" << endl;
        cout << "Q - Quit" << endl;
        cout << "\nSelect the Menu: ";
        cin >> menuOption;
        cout << "\n\n";

        switch(menuOption)
        {
            case 'f':
            case 'F':
                cout<<"Welcome to Read <data.csv> File Menu."<<endl;
                data.DataTable(csvFileName);
                data.PrintHeader();
                data.PrintData();
                break;

            case 'i':
            case 'I':
                cout<<"Welcome to Read other File Menu."<<endl;
                cout<<"Please type the file name (Ex:JackData)."<<endl;
                cin.ignore();
                getline(cin,userFile);
                fileName="../"+userFile+".csv";
                cout<<"\n\n";
                data.DataTable(fileName);
                data.PrintHeader();
                data.PrintData();
                break;

            case 'N':
            case 'n':
                cout<<"Welcome to Phone Number List."<<endl<<endl;
                data.EmployeePhoneNumberList();
                break;

            case 'D':
            case 'd':
                cout<<"Welcome to Data Quality Report."<<endl;
                cout<<"The Empty data will be printed out \"*E\" on the Table."<<endl;
                cout<<"The Duplicated data will be printed out \"*D\" on the Table."<<endl<<endl;
                data.DataQualityReport();
                data.PrintDataQualityReport();
                break;
            case 'E':
            case 'e':
                cout<<"Welcome to Clean Data Report."<<endl;
                cout<<"This report will print out user information without Duplicate or Empty ID"<<endl;
                cout<<"The Empty data will be printed out \"*E\" on the Table."<<endl<<endl;
                data.DataQualityReport();
                data.PrintNoError();
                break;
            case 'Y':
            case 'y':
                cout<<"Welcome to Find the employee with Same parents Report."<<endl;
                cout<<"This report will show the employees who have same parents name.\n"<<endl;
                data.EmployeeFindFamily();
                break;

            case 'C':
            case 'c':
                cout<<"Welcome to Employee Cluster Report."<<endl;
                cout<<"This report will show the number of Employees living in each Zipcode."<<endl;
                cout<<"People without Zipcode will be not counted.\n"<<endl;
                data.EmployeeClusterReport();
                break;

            case 'P':
            case 'p':
                cout<<"Welcome to Employee Pay Raise Report."<<endl;
                cout<<"In this section, it will show all Employee's New salary that are increased by 2.5%."<<endl;
                cout<<"Duplicated or empty ID or People without current salary will not be shown.\n"<<endl;
                data.EmployeePayRaiseReport();
                break;

            case 'R':
            case 'r':
                cout<<"Welcome to Regional Raises Report."<<endl;
                cout<<"In this section, it will show the New salary related to zipcode."<<endl;
                cout<<"Duplicated or empty ID or People without current salary or Zipcode will not be shown."<<endl<<endl;
                data.RegionalRaisesReport();
                break;

            case 'S':
            case 's':
                cout<<"Welcome to Sequence of All Reports (order: N, D, Y, C, P, R)"<<endl;
                cout<<"WARNING! Before you try, make sure read the File first by using \"F\" or \"I\"."<<endl;
                cout<<"In this section, it will show all the previous Report."<<endl<<endl;
                data.EmployeePhoneNumberList();
                data.PrintDataQualityReport();
                data.EmployeeFindFamily();
                data.EmployeeClusterReport();
                data.EmployeePayRaiseReport();
                data.RegionalRaisesReport();
                break;

            case '1':
                cout<<"Welcome to Test 1 Menu"<<endl;
                cout<<"This section will test if right number of raws printed out with set of data."<<endl;
                cout<<"There are 3 rows of data already set in the \"Pre-set\" file."<<endl<<endl;
                test.SetTest();
                test.PrintTest1();
                break;

            case '2':
                cout<<"Welcome to Test 2 Menu"<<endl;
                cout<<"This section will show \"Employee Cluster Report\" with the Data set from \"Test 1\"."<<endl<<endl;
                test.Test2();
                break;

            case 'T':
            case 't':
                cout<<"Welcome to \"Test 1\" and \"Test 2\" Menu"<<endl;
                cout<<"This section will show both \"Test 1\" and \"Test 2\" outputs."<<endl<<endl;
                test.SetTest();
                test.PrintTest1();
                test.Test2();
                break;

            case 'A':
            case 'a':
                cout<<"Welcome to print out all!"<<endl;
                cout<<"This is All Reports and All Tests Menu(order: S,T)"<<endl<<endl;
                data.EmployeePhoneNumberList();
                data.PrintDataQualityReport();
                data.EmployeeFindFamily();
                data.EmployeeClusterReport();
                data.EmployeePayRaiseReport();
                data.RegionalRaisesReport();
                test.SetTest();
                test.PrintTest1();
                test.Test2();
                break;

            case 'Q':
            case 'q':
                goto EndOfLoop;//it will go out of the loop

            //default output for user putting an invalid letter
            default: cout<<"YOU PUT INVALID VALUE!!"<<endl;
                     cout<<"Please Try again."<<endl<<endl;


        }
    }
    //end of loop
    EndOfLoop:
    cout<<"Thanks for using Jack's Final Project! See you again.\n";
}

int main()
{
    userMenu();
    cout<<"\nCode <<Read RSV file>>originally from Professor Andy Cameron."<<endl;
    cout<<"Thanks for this an amazing class and Super Fun (quite challenging) project!!"<<endl;
    return 0;
}

