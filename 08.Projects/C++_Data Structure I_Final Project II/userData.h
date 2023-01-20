# include<vector>
# include <iostream>
# include <string>
using namespace std;
#ifndef MAIN_CPP_USERDATA_H
#define MAIN_CPP_USERDATA_H


class userData
{
public:
    userData();
    userData( int rows, string fileName, double salary, vector<string> headerSaved, vector<vector<string>> dataSaved, vector<vector<int>> dataLength,
    vector<int>outputManager, vector<string>duplicatedID, int totalData, int errorEmpty, int errorDuplicated, int errorTotal, vector<double>moneyRaise, vector<double>moneyNew);

    //read the data from csv file
    void DataTable(string fileName);
    int ReadCSV(string filename, string& header, vector<string>& records);

    //set file name
    void SetFileName(string fileName);
    string GetFileName();

    //set number of rows in the data
    void SetRows(int value);
    int GetRows();

    //Get header and data
    void SetHeader(string input, char delimiter);
    vector<string> GetHeader();
    void SetDataInfo(vector<string>lines);
    vector<vector<string>>GetData();
    vector<vector<int>>GetDataLength();
    void SetOutputLength();
    vector<int>GetOutputLength();

    //all the reports
    void DataQualityReport();
    void PrintDataQualityReport();
    void EmployeePhoneNumberList();
    void EmployeeFindFamily();
    int EmployeeClusterReport();
    void EmployeePayRaiseReport();
    void RegionalRaisesReport();
    double CalculateEmployeeRaise(double money);

    //print out data
    void PrintHeader();
    void PrintData();
    void PrintNoError();

protected: // use protect to use functions again for child class

    int rows;
    string fileName;
    double salary;
    vector<string> headerSaved; // separate and save the header
    vector<vector<string>> dataSaved;//separate and save the data
    vector<vector<int>> dataLength;//count the data length
    vector<int>outputManager;//count the maximum data length and save it
    //for error handler
    vector<string>duplicatedID;
    int totalData;
    int errorEmpty;
    int errorDuplicated;
    int errorTotal;
    //for salary reports
    vector<double>moneyRaise;
    vector<double>moneyNew;

};


#endif //MAIN_CPP_USERDATA_H
