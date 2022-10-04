#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include<algorithm>

#include "userData.h"
using namespace std;

userData::userData()
{
    rows=0;
    salary=0.0;
    string fileName="noName";
    headerSaved.clear();
    dataSaved.clear();
    dataLength.clear();
    outputManager.clear();
    duplicatedID.clear();
    totalData=0;
    errorEmpty=0;
    errorDuplicated=0;
    errorTotal=0;
    moneyRaise.clear();
    moneyNew.clear();
}
//constructor
userData::userData(int rows, string fileName, double salary, vector<string> headerSaved,
                   vector<vector<string>> dataSaved, vector<vector<int>> dataLength, vector<int> outputManager,
                   vector<string> duplicatedID, int totalData, int errorEmpty, int errorDuplicated, int errorTotal,
                   vector<double> moneyRaise, vector<double> moneyNew)
{
this ->rows=rows;
this->fileName=fileName;
this->salary=salary;
this->headerSaved=headerSaved;
this->dataSaved=dataSaved;
this->dataLength=dataLength;
this->outputManager=outputManager;
this->duplicatedID=duplicatedID;
this->totalData=totalData;
this->errorEmpty=errorEmpty;
this->errorDuplicated=errorDuplicated;
this->errorTotal=errorTotal;
this->moneyRaise=moneyRaise;
this->moneyNew=moneyNew;


}
//set file name
void userData::SetFileName(string Name)
{
    fileName=Name;
}
string userData::GetFileName()
{
    return fileName;
}

//get data and separate the data and save individually.
void userData::DataTable(string fileName)
{
    userData();           //clear all data
    SetFileName(fileName);//set file name
    string header;
    vector<string> lines; // all data will be saved in here. (ex line.at(0)=ooo,oo,ooo,oo,...)
    lines.clear();        // clear the data
    int numbRows;
    std::stringstream lineStream(header);
    numbRows = ReadCSV(fileName, header, lines); //read the data from csv file
    SetRows(numbRows);    //Set number of rows
    if(numbRows==-1)      //if no data then return to main Menu.
    {
        return;
    }
    SetHeader(header, ','); //divide and save the header individually.
    SetDataInfo(lines);             //divide the data and save the data individually.
    SetOutputLength();              //find the maximum length of individual column.
}

//call the file. Code Originally from Professor Andy Cameron.
int userData:: ReadCSV(string filename, string& header, vector<string>& records) {
    ifstream inFS;
    string record;
    int numbRows = 0;
    inFS.open(filename);
    if (!inFS.is_open()) { // check for successful open
        cout << "Could not open file. Please Check your file and try again." << endl<<endl;
        return -1;   // return error
    }

    getline(inFS, header); // read the header
    while (!inFS.eof()) {         // read all the rows
        inFS >> record;
        if (!inFS.fail()) {
            records.push_back(record); // store the input (complete line)
            numbRows++;                    // count the number of rows
        }
    }
    //close file when it is done reading.
    inFS.close();
    return numbRows;  // return the number of rows read
}

//Count the rows of data and save
void userData::SetRows(int value)
{
    this->rows=value;
}
int userData::GetRows()
{
    return rows;
}

//divide the header line and save.
void userData::SetHeader(string input, char delimiter)
{
    headerSaved.clear();
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, delimiter))
    {
        headerSaved.push_back(temp);
    }
    headerSaved.resize(headerSaved.size()+1);
}

//get header
vector<string> userData::GetHeader()
{
    return headerSaved;
}

//get string that has one line of csv data
//divide them and save individually by using 2D vector
void userData::SetDataInfo(vector<string>lines)
{
    dataSaved.clear();
    dataLength.clear();
    vector<string> tmp;
    vector<int> tmp2;
    //save the data into 1D vector tmp and tmp2
    for (int i = 0; i < rows; ++i)
    {
        tmp.clear(); //clear the vector to only save the new separated data.
        tmp2.clear();
        istringstream ss(lines.at(i));
        string stringBuffer;
        while (getline(ss, stringBuffer, ',') )
        {
            tmp.push_back(stringBuffer);
            tmp2.push_back(stringBuffer.length());
        }
        //save the data into 2D vector
        dataSaved.push_back(tmp);
        dataSaved.at(i).resize(dataSaved.at(i).size()+1);
        dataLength.push_back(tmp2);
        dataLength.at(i).resize(dataLength.at(i).size()+1);
    }
}

//Get the data
vector<vector<string>>userData::GetData()
{
    return dataSaved;
}

//Get the length of data
vector<vector<int>>userData::GetDataLength()
{
    return dataLength;
}

//calculate the maximum data length (include the length of header)
void userData::SetOutputLength()
{
    int tmpValue;
    outputManager.clear(); // clear the data
    for (int i = 0; i < headerSaved.size()-1; ++i)
    {
        tmpValue = headerSaved.at(i).length(); // put header length to compare the length of sepecific data.
        for (int j = 0; j < rows; ++j)
        {
            if (tmpValue < dataLength.at(j).at(i))
            {
                tmpValue = dataLength.at(j).at(i);
            }
        }
        outputManager.push_back(tmpValue); //save the maximum data length
    }
}

//Get the maximum data length of individual column
vector<int>userData::GetOutputLength()
{
    return outputManager;
}

//print the headers
void userData::PrintHeader()
{
    cout << "Reading the data from: " << fileName << endl;
    cout << "|";

    cout << left << setw(outputManager.at(0)) << headerSaved.at(0) << "   |"; //I put out the first header(which is user_ID) because it keep moves depends on the excel file...
                                                                                       //If header data pushed because of this...Please remove the line this and

    for (int i = 1; i < headerSaved.size()-1; ++i)                                     // change int i=1 to int i=0
    {
        cout << left << setw(outputManager.at(i)) << headerSaved.at(i) << "|";
    }
    cout << endl;
}

//print the data
void userData::PrintData()
{
    for (int i = 0; i < rows; ++i)
    {
        cout << "|";
        for (int j = 0; j < headerSaved.size()-1; ++j)
        {
            cout << left << setw(outputManager.at(j)) << dataSaved.at(i).at(j) << "|";
        }
        cout << endl;
    }
    cout << "\nTotal "<<rows << " data rows found." << endl << endl;
}

//Remove duplicates and empty data
void userData::DataQualityReport()
{
    //if data is empty or file does not get read then it will go back to main menu.
    if(rows==-1)
    {
        cout<<"\nCannot open the file. Please Check your file and try again."<<endl<<endl;
        return;
    }
    if(rows==0||headerSaved.size()==0)
    {
        cout<<"\nData is Empty. Please Check your file and try again."<<endl<<endl;
        return;
    }
    //for test file
    if(fileName!="Test Number 1")
    {
        string file = GetFileName();
        DataTable(file);
    }

    //manage empty data first
    int numbEmpty=0;
    int numbTotal=0;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < headerSaved.size()-1; ++j)
        {
            if(dataSaved.at(i).at(j)=="") //If data is Empty
            {
                dataSaved[i][j] = "*E";   //Then change the data into *E
                numbEmpty++;              //count the number of errors and total data
                numbTotal++;
            }
            else
            {
                numbTotal++;
            }
        }
    }
    errorEmpty=numbEmpty;
    totalData=numbTotal;

    //manage duplicates
    duplicatedID.clear();
    int errorDupli=0;
    for (int i = 0; i < rows-1; ++i)
    {
        try
        {
            for(int j=i+1;j<rows;j++)
            {
                if (dataSaved.at(i).at(0) == dataSaved.at(j).at(0))              //compare the data with data+1
                {
                    if(dataSaved.at(i).at(0)!="*D"&&dataSaved.at(i).at(0)!="*E") //If data duplicated without being *D and *E
                        throw j;                                                       //throw the location of user ID number.
                }
            }
        }catch(int duplicatedRow)
        {   duplicatedID.push_back(dataSaved.at(duplicatedRow).at(0));              //Save the Duplicated ID
            dataSaved[duplicatedRow][0] = "*D";                                        //Change duplicated ID into *D
            errorDupli++;                                                              //count the numbers of duplicated IDs.
        }
    }
    errorDuplicated=errorDupli*headerSaved.size();    //Calculate total duplicated data depends on line..
                                                      //If ID get duplicated then it will treat entire duplicate ID line as duplicated.
    errorTotal=errorDuplicated+errorEmpty;            //Calculate the total errors
    sort(dataSaved.begin(),dataSaved.end()); //Sort the data saved.
}

//Print out DataQualityReport.
void userData::PrintDataQualityReport()
{
    //if there are no data or file could not be read then return to main Menu.
    if(rows==-1)
    {
        return;
    }
    if(rows==0||headerSaved.size()==0)
    {

        return;
    }

    //print data without Errors in userID.
    cout<<"<<DataQualityReport>>"<<endl;
    PrintHeader();
    PrintData();
    cout<<"<<Exceptions Section Summary>>"<<endl;
    cout<<"Total Number of Data in this file is: "<<totalData<<endl;
    cout<<"Total Number of Empty Data is: "<<errorEmpty<<endl;
    cout<<"Duplicated IDs are: ";
    if(duplicatedID.size()==0)
        cout<<"None.";
    else
    {
        for (int i = 0; i < duplicatedID.size(); ++i) {
            cout << duplicatedID.at(i) << " ";
        }
    }
    cout<<endl;
    cout<<"Total Number of Duplicated Data is: "<<errorDuplicated<<endl;
    cout<<"Total Number of Errors is: "<<errorEmpty+errorDuplicated<<endl;
    cout<<"Total Number of Good Data is: "<<totalData-errorTotal<<endl;
    cout<<endl<<endl;
}

//print data without error immediately.
void userData::PrintNoError()
{
    DataQualityReport();  //call DataQualityReport to manage the data.

    //if there are no data or file could not be read then return to main Menu.
    if(rows==-1)
    {
        return;
    }
    if(rows==0||headerSaved.size()==0)
    {

        return;
    }

    cout<<"<<PrintDataWithoutError>>"<<endl;
    PrintHeader();
    int totalrows=0;
    for (int i = 0; i < rows; ++i)
    {
        try
        {  if (dataSaved.at(i).at(0) == "*D")
                throw i;
            if (dataSaved.at(i).at(0) == "*E")
                throw i;
            cout << "|";
            for (int j = 0; j < headerSaved.size()-1; j++)
            {
                cout << left << setw(outputManager.at(j)) << dataSaved.at(i).at(j) << "|";
            } cout << endl;
            totalrows++;   //count total rows
        } catch (int duplicatedRow)
        {
            cout<<"";
        }
    }
    cout << "\nTotal "<<totalrows << " data rows found." << endl << endl;
}

//Employ phone number list after removing duplicates and empty IDs.
void userData::EmployeePhoneNumberList() {

    DataQualityReport();   //call DataQualityReport to manage the data.

    //if there are no data or file could not be read then return to main Menu.
    if(rows==-1)
    {
        return;
    }
    if(rows==0||headerSaved.size()==0)
    {

        return;
    }

    //save the location(column number) of data in specific columns.
    vector<int> location;
    location.clear();
    location.push_back(0);
    location.push_back(4);
    location.push_back(2);
    location.push_back(17);

    //print header
    cout<<"<<EmployeePhoneNumberList>>"<<endl;
    cout << "Reading the data from: " << fileName << endl ;
    cout << "|";
    cout << left << setw(outputManager.at(0)) << headerSaved.at(0) << "   |";                       //Again...If header get pushed because of this line
    for (int i = 1; i < location.size(); ++i)                                                                //Please remove the line and change <int i=1> to <int i=0>
    {
        cout << left << setw(outputManager.at(location.at(i))) << headerSaved.at(location.at(i)) << "|";  // print out the headers in specific column
    }
    cout<<endl;

    //print data
    int totalRow=0;
    for (int i = 0; i < rows; ++i)
    { try {
            if (dataSaved.at(i).at(0) == "*D")    // if data is duplicated throw error
                throw i;
            if (dataSaved.at(i).at(0)=="*E")      //if data is empty then throw error
                throw i;
            if(dataSaved.at(i).at(17)=="*E")      //if there are no phone number then throw error
                throw i;

            cout << "|";
            for (int j = 0; j < location.size(); ++j)
            {
                cout << left << setw(outputManager.at(location.at(j))) << dataSaved.at(i).at(location.at(j)) << "|";
            }
            cout<<endl;
            totalRow++;       //count the valid rows printed.
        }catch(int errors)
        {
        }
    }
    cout << "\nTotal "<<totalRow << " data rows found." << endl << endl;
}

//search the employees who have same parents name
void userData::EmployeeFindFamily()
{
    DataQualityReport();   //call DataQualityReport to manage the data.

    //if there are no data or file could not be read then return to main Menu.
    if(rows==-1)
    {
        return;
    }
    if(rows==0||headerSaved.size()==0)
    {

        return;
    }

    //save the ID if employees have same family.
    vector<int>findFamily;
    findFamily.clear();
    for (int i = 0; i < rows-1; ++i)
    {
        try {
            if (dataSaved.at(i).at(0) == "*D") //if ID duplicated throw error.
                throw i;
            if (dataSaved.at(i).at(0) == "*E") //if ID empty throw error.
                throw i;

            //if parents name is  empty then throw error.
            if(dataSaved.at(i).at(7)=="*E")
                throw i;
            if(dataSaved.at(i).at(8)=="*E")
                throw i;
            if(dataSaved.at(i).at(9)=="*E")
                throw i;

            //save all the people who have same parents name.
            for (int j = i + 1; j < rows; j++)
            {
                if(dataSaved.at(j).at(0) == "*D") //if ID duplicated throw error
                    throw i;
                if(dataSaved.at(j).at(0)=="*E")  //if ID empty throw error
                    throw i;
                if (dataSaved.at(j).at(7) == dataSaved.at(i).at(7)     //if father's name, mother's name, and mother's maiden name is same
                    && dataSaved.at(j).at(8) == dataSaved.at(i).at(8)  //then save the data
                    && dataSaved.at(j).at(9) == dataSaved.at(i).at(9))
                {
                    findFamily.push_back(i); //save the location of original
                    findFamily.push_back(j); //save the location of rows who has same parents as original
                }
            }
        } catch (int error) {
        }
    }

    //If no match founded
    if(findFamily.size()==0)
    {
        cout<<"There are no Employees that have same parents."<<endl<<endl;
        return;
    }

    //remove all the duplicated IDs;
    findFamily.erase(unique(findFamily.begin(),findFamily.end()),findFamily.end());

    int findrows=0; // count the total rows

    //print data
    cout<<"<<EmployeeFindFamily>>"<<endl;
    PrintHeader();
    for (int i = 0; i<findFamily.size();++i)
    {
        cout << "|";
        for (int j = 0; j < headerSaved.size()-1; ++j)
        {
            cout << left << setw(outputManager.at(j)) << dataSaved.at(findFamily.at(i)).at(j) << "|";
        }
        cout << endl;
        findrows++;
    }
    cout << "\nTotal "<<findrows << " data rows found." << endl << endl;
}


int userData::EmployeeClusterReport()
{
    DataQualityReport();   //call DataQualityReport to manage the data.

    //if there are no data or file could not be read then return to main Menu.
    if(rows==-1)
    {
        return rows;
    }
    if(rows==0||headerSaved.size()==0)
    {

        return rows;
    }

    //save the location(column number) of data in specific columns.
    vector<int> location;
    int totalRow=0;
    location.clear();
    location.push_back(22);
    location.push_back(20);
    location.push_back(21);
    vector<string>tmp; // file to put the data into 2D vector zip.
    vector<vector<string>>zip;
    zip.clear();

    for (int i = 0; i < rows; ++i)
    {try {
            tmp.clear();                       // clear the vector to add the new data to 2D vector Zip
            if(dataSaved.at(i).at(0)=="*D") // throw the error if ID duplicated
                throw i;
            if(dataSaved.at(i).at(0)=="*E") // throw the error if ID empty
                throw i;
            if(dataSaved.at(i).at(22)=="*E")// throw error if Zip code is empty
                throw i;
            for (int j = 0; j < location.size(); ++j) //save all the valid data
            {
                tmp.push_back(dataSaved.at(i).at(location.at(j)));
            }
            zip.push_back(tmp);
        }catch(int error)
        {

        }
    }

    sort(zip.begin(),zip.end()); // sort the file depends on the zipcode

    //print header
    cout<<"<<EmployeeClusterReport>>"<<endl;
    cout << "Reading the data from: " << fileName << endl ;
    cout << "|Count|";
    for (int i = 0; i < location.size(); ++i)
    {
        cout << left << setw(outputManager.at(location.at(i))) << headerSaved.at(location.at(i)) << "|";
    }
    cout<<endl;

    //print data
    int count=0;
    int countrows=0;
    for (int i = zip.size()-1; i >=0; --i) // print the data backward.
    {
        cout<<"|";
        countrows++;
        if(i==0)
        {
            if(zip.at(i).at(0)==zip.at(i+1).at(0))  // if data at 0 is same as before, then print the total count
            {   count++;
                cout<<left<<setw(5)<<count<<"|";
                cout<<left<<setw(outputManager.at(location.at(0)))<<zip.at(i).at(0)<<"|";
                cout<<left<<setw(outputManager.at(location.at(1)))<<zip.at(i).at(1)<<"|";
                cout<<left<<setw(outputManager.at(location.at(2)))<<zip.at(i).at(2)<<"|";
            }
            else //if data at 0 is not same as data at 1, print print count 1.
            {   count++;
                cout<<left<<setw(5)<<count<<"|";
                cout<<left<<setw(outputManager.at(location.at(0)))<<zip.at(i).at(0)<<"|";
                cout<<left<<setw(outputManager.at(location.at(1)))<<zip.at(i).at(1)<<"|";
                cout<<left<<setw(outputManager.at(location.at(2)))<<zip.at(i).at(2)<<"|";
                count=0;
            }
        }
        else if(zip.at(i).at(0)!=zip.at(i-1).at(0)) //if data is not same as data-1, print the whole data and reset the count.
        {   count++;
            cout<<left<<setw(5)<<count<<"|";
            cout<<left<<setw(outputManager.at(location.at(0)))<<zip.at(i).at(0)<<"|";
            cout<<left<<setw(outputManager.at(location.at(1)))<<zip.at(i).at(1)<<"|";
            cout<<left<<setw(outputManager.at(location.at(2)))<<zip.at(i).at(2)<<"|";
            count=0;
        }
        else // if the data is same as data-1, print the data except zip code.
        {   count++;
            cout<<left<<setw(5)<<count<<"|";
            cout<<left<<setw(outputManager.at(location.at(0)))<<" "<<"|";
            cout<<left<<setw(outputManager.at(location.at(1)))<<zip.at(i).at(1)<<"|";
            cout<<left<<setw(outputManager.at(location.at(2)))<<zip.at(i).at(2)<<"|";
        }
        cout<<endl;
    }

    cout << "\nTotal "<<countrows << " data rows found." << endl << endl;
    return countrows;
};


void userData::EmployeePayRaiseReport()
{
    DataQualityReport();   //call DataQualityReport to manage the data.

    //if there are no data or file could not be read then return to main Menu.
    if(rows==-1)
    {
        return;
    }
    if(rows==0||headerSaved.size()==0)
    {

        return;
    }
    //save the location(column number) of data in specific columns.
    vector<int> location;
    location.clear();
    location.push_back(1);
    location.push_back(2);
    location.push_back(3);
    location.push_back(4);
    location.push_back(14);

    vector<string>tmp;  //vector that will be used to put the data into 2D vector daetaNeed
    vector<vector<string>>dataNeed;
    dataNeed.clear();

    for (int i = 0; i < rows; ++i)
    {
        try
          {
            tmp.clear();  //clear the 1D vector tmp to save the new data.
            if(dataSaved.at(i).at(0)=="*D")  // throw error for the duplicated ID.
                throw i;
            if(dataSaved.at(i).at(0)=="*E")  // throw error for the Empty ID.
                throw i;
            if(dataSaved.at(i).at(14)=="*E") // throw error for empty salary.
                throw i;
            for (int j = 0; j < location.size(); ++j)
            {
                tmp.push_back(dataSaved.at(i).at(location.at(j))); // save valid data into 1D vector tmp
            }
            dataNeed.push_back(tmp);   //save the 1D vector value into 2D vector dataNeed.
          }catch(int error)
        {

        }
    }

    //calculate the raise salary.
    moneyRaise.clear();
    moneyNew.clear();
    double salaryNew=0;
    double salaryRaise=0;
    double percentRaise=0.025;
    for(int i=0;i<dataNeed.size();++i)
    {
        salary=0;
        salaryNew=0;
        salary=stod(dataNeed.at(i).at(4));
        salaryNew=CalculateEmployeeRaise(percentRaise); // call function to calculate the new salary
        moneyNew.push_back(salaryNew);
        salaryRaise=salaryNew-salary;
        moneyRaise.push_back(salaryRaise);
    }

    //print header
    cout<<"<<EmployeePayRaiseReport>>"<<endl;
    cout << "Reading the data from: " << fileName << endl;
    cout << "|";
    for (int i = 0; i < location.size(); ++i)
    {
        cout << left << setw(outputManager.at(location.at(i))) << headerSaved.at(location.at(i)) << "|";
    }
    cout<<"New_Salary|"<<"Raise_Amount|"<<endl;

    //print data
    int countrows=0;
    for (int i =0; i<dataNeed.size(); ++i)
    {
        cout<<"|";
        cout << left << setw(outputManager.at(location.at(0))) << dataNeed.at(i).at(0) << "|";
        cout << left << setw(outputManager.at(location.at(1))) << dataNeed.at(i).at(1) << "|";
        cout << left << setw(outputManager.at(location.at(2))) << dataNeed.at(i).at(2) << "|";
        cout << left << setw(outputManager.at(location.at(3))) << dataNeed.at(i).at(3) << "|";
        cout << left << setw(outputManager.at(location.at(4))) << dataNeed.at(i).at(4) << "|";
        cout<<left<<setw(10)<<moneyNew.at(i)<<"|";
        cout<<left<<setw(12)<<moneyRaise.at(i)<<"|";
        cout<<endl;
        countrows++;
    }
    cout << "\nTotal "<<countrows << " data rows found." << endl << endl;
}

//function that gets the percentRaise then calculate the new salary.
double userData::CalculateEmployeeRaise(double percentRaise)
{   double salaryNew=0;
    salaryNew=salary+salary*percentRaise;
    return  salaryNew;
}

void userData::RegionalRaisesReport()
{
    DataQualityReport();   //call DataQualityReport to manage the data.

    //if there are no data or file could not be read then return to main Menu.
    if(rows==-1)
    {
        return;
    }
    if(rows==0||headerSaved.size()==0)
    {

        return;
    }
    //save the location(column number) of data in specific columns.
    vector<int> location;
    location.clear();
    location.push_back(22);
    location.push_back(20);
    location.push_back(21);
    location.push_back(14);

    //setup 1D vector that will be used to put data into 2D vector
    vector<string>tmp;
    vector<vector<string>>dataNeed;
    dataNeed.clear();

    for (int i = 0; i < rows; ++i)
    {
        try {
            tmp.clear(); // clear the 1D vector to put the new value
            if(dataSaved.at(i).at(0)=="*D") // throw error for duplicated ID
                throw i;
            if(dataSaved.at(i).at(0)=="*E") // throw error for empty ID
                throw i;
            if(dataSaved.at(i).at(14)=="*E")// throw error for empty salary
                throw i;
            if(dataSaved.at(i).at(22)=="*E")// throw error for empty zipcode
                throw i;
            for (int j = 0; j < location.size(); ++j)
            {
                tmp.push_back(dataSaved.at(i).at(location.at(j))); // save the valid data into vector tmp
            }
            dataNeed.push_back(tmp); // save the data saved in vector tmp to 2D vector dataNeed
        }catch(int error)
        {

        }
    }

    sort(dataNeed.begin(),dataNeed.end()); // sort the data depends on the zipcode

    //calculate the money
    moneyRaise.clear();
    moneyNew.clear();
    double salaryNew;
    double salaryRaise;
    double percentRaise=0.025;
    for(int i=0;i<dataNeed.size();++i)
    {
        salary=0;
        salaryNew=0;
        salary=stod(dataNeed.at(i).at(3));
        salaryNew=CalculateEmployeeRaise(percentRaise);
        moneyNew.push_back(salaryNew);
        salaryRaise=salaryNew-salary;
        moneyRaise.push_back(salaryRaise);
    }

    //print header
    cout<<"<<RegionalRaisesReport>>"<<endl;
    cout << "Reading the data from: " << fileName << endl;
    cout << "|Count|";
    for (int i = 0; i < location.size(); ++i)
    {
        cout << left << setw(outputManager.at(location.at(i))) << headerSaved.at(location.at(i)) << "|";
    }
    cout<<"New_Salary|Raise_Amount|Raise_Total|"<<endl;


    //print data
    int countrows=0;
    int count=0;
    double riseTotal=0;
    for (int i =dataNeed.size()-1; i>=0; --i)
    {
        cout<<"|";
        if(i==0)
        {
            if(dataNeed.at(i).at(0)==dataNeed.at(i+1).at(0)) // if data at 0 is data at 1 then print out all the data(total cumululated money and count)
            {   count++;
                cout<<left<<setw(5)<<count<<"|";
                riseTotal=riseTotal+moneyRaise.at(i); // calculate the cumulated money
                cout<<left<<setw(outputManager.at(location.at(0)))<<dataNeed.at(i).at(0)<<"|";
                cout<<left<<setw(outputManager.at(location.at(1)))<<dataNeed.at(i).at(1)<<"|";
                cout<<left<<setw(outputManager.at(location.at(2)))<<dataNeed.at(i).at(2)<<"|";
                cout<<left<<setw(outputManager.at(location.at(3)))<<dataNeed.at(i).at(3)<<"|";
                cout<<left<<setw(10)<<moneyNew.at(i)<<"|";
                cout<<left<<setw(12)<<moneyRaise.at(i)<<"|";
                cout<<left<<setw(11)<<riseTotal<<"|";
            }
            else
            {   count++;
                cout<<left<<setw(5)<<count<<"|";
                riseTotal=riseTotal+moneyRaise.at(i);// calculate the cumulated money
                cout<<left<<setw(outputManager.at(location.at(0)))<<dataNeed.at(i).at(0)<<"|";
                cout<<left<<setw(outputManager.at(location.at(1)))<<dataNeed.at(i).at(1)<<"|";
                cout<<left<<setw(outputManager.at(location.at(2)))<<dataNeed.at(i).at(2)<<"|";
                cout<<left<<setw(outputManager.at(location.at(3)))<<dataNeed.at(i).at(3)<<"|";
                cout<<left<<setw(10)<<moneyNew.at(i)<<"|";
                cout<<left<<setw(12)<<moneyRaise.at(i)<<"|";
                cout<<left<<setw(11)<<riseTotal<<"|";
                count=0;
                riseTotal=0;
            }
        }
        else if(dataNeed.at(i).at(0)!=dataNeed.at(i-1).at(0))
        {   count++;
            cout<<left<<setw(5)<<count<<"|";
            riseTotal=riseTotal+moneyRaise.at(i);// calculate the cumulated money
            cout<<left<<setw(outputManager.at(location.at(0)))<<dataNeed.at(i).at(0)<<"|";
            cout<<left<<setw(outputManager.at(location.at(1)))<<dataNeed.at(i).at(1)<<"|";
            cout<<left<<setw(outputManager.at(location.at(2)))<<dataNeed.at(i).at(2)<<"|";
            cout<<left<<setw(outputManager.at(location.at(3)))<<dataNeed.at(i).at(3)<<"|";
            cout<<left<<setw(10)<<moneyNew.at(i)<<"|";
            cout<<left<<setw(12)<<moneyRaise.at(i)<<"|";
            cout<<left<<setw(11)<<riseTotal<<"|";
            count=0;
            riseTotal=0;
        }
        else
        {   count++;
            cout<<left<<setw(5)<<count<<"|";
            riseTotal=riseTotal+moneyRaise.at(i);// calculate the cumulated money
            cout<<left<<setw(outputManager.at(location.at(0)))<<" "<<"|";
            cout<<left<<setw(outputManager.at(location.at(1)))<<dataNeed.at(i).at(1)<<"|";
            cout<<left<<setw(outputManager.at(location.at(2)))<<dataNeed.at(i).at(2)<<"|";
            cout<<left<<setw(outputManager.at(location.at(3)))<<dataNeed.at(i).at(3)<<"|";
            cout<<left<<setw(10)<<moneyNew.at(i)<<"|";
            cout<<left<<setw(12)<<moneyRaise.at(i)<<"|";
            cout<<left<<setw(11)<<" "<<"|";
        }
        cout<<endl;
        countrows++;
    }
    cout << "\nTotal "<<countrows << " data rows found." << endl << endl;
}