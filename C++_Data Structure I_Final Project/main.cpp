#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

class userData
{
public:
    userData();

    int ReadCSV(string filename, string& header, vector<string>& records);
    void DataTable(string fileName);

    void SetFileName(string fileName);
    string GetFileName();

    void SetRows(int value);
    int GetRows();

    vector<string> GetHeader(string input, char delimiter);
    void SetDataInfo(vector<string>lines);
    vector<vector<string>>GetData();
    vector<vector<int>>GetDataLength();
    void SetOutputLength();
    vector<int>GetOutputLength();

    void EmployeePhoneNumberList();

    void DataQualityReport();

    void PrintDataQualityReport();
    void PrintHeader();
    void PrintData();
    void PrintNoError();

    void EmployeeFindFamily();
    void EmployeeClusterReport();

    int SetTest();
    void PrintTest1();
    void EmployeePayRaiseReport();
    void RegionalRaisesReport();
    double CalculateEmployeeRaise(double money);
private:
    int rows;
    string fileName;
    int testRows;
    double salary;
    //헤더를 따로따로 저장하는 백터값.
    vector<string> headerSaved;
    //데이터를 처리하기 위한 백터 2개
    vector<vector<string>> dataSaved;
    vector<vector<int>> dataLength;
    //표를 예쁘게 만들기 위한 백터 1개
    vector<int>outputManager;
    //catch error
    vector<string>duplicatedID;
    int totalData,errorEmpty,errorDuplicated,errorTotal;

    vector<double>moneyRaise;
    vector<double>moneyNew;
};

userData::userData()
{ rows=0;
  testRows=0;
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

void userData::SetFileName(string Name)
{
    fileName=Name;
}
string userData::GetFileName()
{
    return fileName;
}

void userData::DataTable(string fileName)
{
    userData();
    SetFileName(fileName);
    string header;
    vector<string> lines; // 정보가 여기에 다 ㅁㅁ,ㅁㅁ,ㅁㅁ,로 들어가있음
    lines.clear();
    int numbRows;
    std::stringstream lineStream(header);
    numbRows = ReadCSV(fileName, header, lines);
    SetRows(numbRows);
    if(numbRows==-1)
    {
        return;
    }
    GetHeader(header, ',');
    SetDataInfo(lines);
    SetOutputLength();
}

//건들지마!-파일 불러오기
int userData:: ReadCSV(string filename, string& header, vector<string>& records) {
    ifstream inFS;
    string record;
    int numbRows = 0;
    inFS.open(filename);
    cout << "Reading: " << filename << endl<<endl;
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
    inFS.close();
    return numbRows;  // return the number of rows read
}

void userData::SetRows(int value)
{
    this->rows=value;
}

int userData::GetRows()
{
    return rows;
}

//건들지마!-헤더를 따로따로 저장하기.
vector<string>userData::GetHeader(string input, char delimiter)
{
    headerSaved.clear();
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, delimiter))
    {
        headerSaved.push_back(temp);
    }
    headerSaved.resize(headerSaved.size()+1);
    return headerSaved;
}

void userData::SetDataInfo(vector<string>lines)
{
    dataSaved.clear();
    dataLength.clear();
    vector<string> tmp;
    vector<int> tmp2;
    for (int i = 0; i < rows; ++i)
    {
        tmp.clear();
        tmp2.clear();
        istringstream ss(lines.at(i));
        string stringBuffer;
        while (getline(ss, stringBuffer, ',') )
        {
            tmp.push_back(stringBuffer);
            tmp2.push_back(stringBuffer.length());
        }
        dataSaved.push_back(tmp);
        dataSaved.at(i).resize(dataSaved.at(i).size()+1);
        dataLength.push_back(tmp2);
        dataLength.at(i).resize(dataLength.at(i).size()+1);
    }
}


vector<vector<string>>userData::GetData()
{
    return dataSaved;
}

vector<vector<int>>userData::GetDataLength()
{
    return dataLength;
}

void userData::SetOutputLength() {

    int tmpValue;
    outputManager.clear();
    for (int i = 0; i < headerSaved.size()-1; ++i)
    {
        tmpValue = headerSaved.at(i).length();
        for (int j = 0; j < rows; ++j)
        {
            if (tmpValue < dataLength.at(j).at(i))
            {
                tmpValue = dataLength.at(j).at(i);
            }
        }
        outputManager.push_back(tmpValue);
    }
}

vector<int>userData::GetOutputLength()
{
    return outputManager;
}

void userData::PrintHeader()
{
    cout << "Reading the data from: " << fileName << endl;
    cout << "|";
    cout << left << setw(outputManager.at(0)) << headerSaved.at(0) << "   |";
    for (int i = 1; i < headerSaved.size()-1; ++i)
    {
        cout << left << setw(outputManager.at(i)) << headerSaved.at(i) << "|";
    }
    cout << endl;


}

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


void userData::EmployeePhoneNumberList() {
    DataQualityReport();

    if(rows==-1)
    {

        return;
    }
    if(rows==0||headerSaved.size()==0)
    {

        return;
    }
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
    cout << left << setw(outputManager.at(0)) << headerSaved.at(0) << "   |";
    for (int i = 1; i < location.size(); ++i)
    {
            cout << left << setw(outputManager.at(location.at(i))) << headerSaved.at(location.at(i)) << "|";
    }
    cout<<endl;
    //print data
    int totalRow=0;
    for (int i = 0; i < rows; ++i)
    { try {
            if (dataSaved.at(i).at(0) == "*D")
                throw i;
            if (dataSaved.at(i).at(0)=="*E")
                throw i;
            if(dataSaved.at(i).at(17)=="*E")
                throw i;

            cout << "|";
            for (int j = 0; j < location.size(); ++j)
            {
                cout << left << setw(outputManager.at(location.at(j))) << dataSaved.at(i).at(location.at(j)) << "|";
            }
            cout<<endl;
            totalRow++;
            }catch(int duplicate )
            {
            }


    }
    cout << "\nTotal "<<totalRow << " data rows found." << endl << endl;

}

void userData::DataQualityReport()
{
    //exception
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
    if(fileName!="Test Number 1")
    {
        string file = GetFileName();
        DataTable(file);
    }

    //manage empty data
    int numbEmpty=0;
    int numbTotal=0;
    for (int i = 0; i < rows; ++i)
    {
       for (int j = 0; j < headerSaved.size()-1; ++j)
        {
            if(dataSaved.at(i).at(j)=="")
            {
                dataSaved[i][j] = "*E";
                numbEmpty++;
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
    duplicatedID.clear();
    //manage duplicates
     int errorDupli=0;
    for (int i = 0; i < rows; ++i)
    {
        try
        {
            for(int j=i+1;j<rows-1;j++)
            {
                if (dataSaved.at(i).at(0) == dataSaved.at(j).at(0))
                {
                    if(dataSaved.at(i).at(0)!="*D"&&dataSaved.at(i).at(0)!="*E")
                        throw j;
                }
            }
        }catch(int duplicatedRow)
        {   duplicatedID.push_back(dataSaved.at(duplicatedRow).at(0));
            dataSaved[duplicatedRow][0] = "*D";
            errorDupli++;
        }
    }

    errorDuplicated=errorDupli*headerSaved.size();
    errorTotal=errorDuplicated+errorEmpty;
    sort(dataSaved.begin(),dataSaved.end());
}
void userData::PrintDataQualityReport()
{
    if(rows==-1)
    {
        return;
    }
    if(rows==0||headerSaved.size()==0)
    {

        return;
    }
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

void userData::PrintNoError()
{
    DataQualityReport();
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
            totalrows++;
        } catch (int duplicatedRow)
        {
            cout<<"";
        }
    }
    cout << "\nTotal "<<totalrows << " data rows found." << endl << endl;

}

void userData::EmployeeFindFamily()
{
    DataQualityReport();
    //save the ID if employees have same family.
    vector<int>findFamily;
    findFamily.clear();
    for (int i = 0; i < rows-1; ++i)
    {
        try {
            if (dataSaved.at(i).at(0) == "*D")
                throw i;
            if (dataSaved.at(i).at(0) == "*E")
                throw i;
            if(dataSaved.at(i).at(7) == "*D")
                throw i;
            if(dataSaved.at(i).at(7)=="*E")
                throw i;
            if(dataSaved.at(i).at(8) == "*D")
                throw i;
            if(dataSaved.at(i).at(8)=="*E")
                throw i;
            if(dataSaved.at(i).at(9) == "*D")
                throw i;
            if(dataSaved.at(i).at(9)=="*E")
                throw i;

            for (int j = i + 1; j < rows; j++)
            {
                if(dataSaved.at(j).at(0) == "*D")
                    throw i;
                if(dataSaved.at(j).at(0)=="*E")
                    throw i;
                if (dataSaved.at(j).at(7) == dataSaved.at(i).at(7)
                && dataSaved.at(j).at(8) == dataSaved.at(i).at(8)
                && dataSaved.at(j).at(9) == dataSaved.at(i).at(9))
                    {
                    findFamily.push_back(i);
                    findFamily.push_back(j);
                    }
            }
        } catch (int duplicatedRow) {
            cout << "";
        }
    }
    //remove all the duplicated numbers;
    if(findFamily.size()==0)
    {
        cout<<"There are no Employees that have same parents."<<endl<<endl;
        return;
    }
    findFamily.erase(unique(findFamily.begin(),findFamily.end()),findFamily.end());
    int findrows;
    findrows=findFamily.size();

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
        }
        cout << "\nTotal "<<findrows << " data rows found." << endl << endl;
}


void userData::EmployeeClusterReport()
{
    DataQualityReport();
    if(dataSaved.size()==0||rows==0||rows==-1)
    {
        return;
    }
    vector<int> location;
    int totalRow=0;
    location.clear();
    location.push_back(22);
    location.push_back(20);
    location.push_back(21);
    vector<string>tmp;
    vector<vector<string>>zip;
    zip.clear();

    for (int i = 0; i < rows; ++i)
    {try {
            tmp.clear();
            if(dataSaved.at(i).at(0)=="*D")
                throw i;
            if(dataSaved.at(i).at(0)=="*E")
                throw i;
            if(dataSaved.at(i).at(22)=="*E")
                throw i;
            for (int j = 0; j < location.size(); ++j) {
                tmp.push_back(dataSaved.at(i).at(location.at(j)));
            }
            zip.push_back(tmp);
        }catch(int error)
         {}
    }
    sort(zip.begin(),zip.end());
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
    for (int i = zip.size()-1; i >=0; --i)
    {
        cout<<"|";
        countrows++;
            if(i==0)
            {
               if(zip.at(i).at(0)==zip.at(i+1).at(0))
                {   count++;
                    cout<<left<<setw(5)<<count<<"|";
                    cout<<left<<setw(outputManager.at(location.at(0)))<<zip.at(i).at(0)<<"|";
                    cout<<left<<setw(outputManager.at(location.at(1)))<<zip.at(i).at(1)<<"|";
                    cout<<left<<setw(outputManager.at(location.at(2)))<<zip.at(i).at(2)<<"|";
                }
                else
                {   count++;
                    cout<<left<<setw(5)<<count<<"|";
                    cout<<left<<setw(outputManager.at(location.at(0)))<<zip.at(i).at(0)<<"|";
                    cout<<left<<setw(outputManager.at(location.at(1)))<<zip.at(i).at(1)<<"|";
                    cout<<left<<setw(outputManager.at(location.at(2)))<<zip.at(i).at(2)<<"|";
                    count=0;
                }
            }
            else if(zip.at(i).at(0)!=zip.at(i-1).at(0))
            {   count++;
                cout<<left<<setw(5)<<count<<"|";
                cout<<left<<setw(outputManager.at(location.at(0)))<<zip.at(i).at(0)<<"|";
                cout<<left<<setw(outputManager.at(location.at(1)))<<zip.at(i).at(1)<<"|";
                cout<<left<<setw(outputManager.at(location.at(2)))<<zip.at(i).at(2)<<"|";
                count=0;
            }
            else
            {   count++;
                cout<<left<<setw(5)<<count<<"|";
                cout<<left<<setw(outputManager.at(location.at(0)))<<" "<<"|";
                cout<<left<<setw(outputManager.at(location.at(1)))<<zip.at(i).at(1)<<"|";
                cout<<left<<setw(outputManager.at(location.at(2)))<<zip.at(i).at(2)<<"|";
            }

        cout<<endl;
    }

    cout << "\nTotal "<<countrows << " data rows found." << endl << endl;
};

int userData::SetTest() {
    userData();
    string testHeader="Emp_ID,Name_Prefix,First_Name,MI,Last_Name,Gender,E_Mail,Father's_Name,Mother's_Name,Mother's_Maiden_Name,"
                      "Date_of_Birth,Age,Weight_in_Kgs.,Date_of_Joining,Salary,Last_%_Hike,SSN,Phone_No._,Place_Name,County,City,State,Zip,Region,User_Name";
    string data1 = "969964,Mr.,Jack,T,Kweon,M,tempest0211@gmail.com,Paul_Kweon,Alice_Kweon,Perez,"
                   "1/12/1980,37.57,56,8/23/2016,147641,25%,733-26-1976,010-4432-4690,Nowhere,Seoul,Seoul,OR,97230,Midwest,kweont";
    string data2 = "278556,Prof.,James,,Moriarty,M,villainthebest@amazon.net,Peter_Moriarty,Andrea_Moriarty,Flores,"
                   "7/28/1993,24.02,81,8/18/2016,122226,14%,013-94-5886,205-621-4872,Ohatchee,Calhoun,Ohatchee,AL,36271,South,villain";
    string data3 = "639892,Dr.,who,,Mystery,M,englishman@hotmail.com,Carlos_Mystery,Anna_Mystery,Hayes,"
                   "10/8/1994,22.82,89,7/9/2016,129774,15%,171-86-3825,228-245-5000,Biloxi,Harrison,Biloxi,MS,39532,South,monsterHunter";
    string filename = "Test Number 1";

    cout<<"Pre-set data is written below."<<endl;
    cout<<"First Data: "<<data1<<endl;
    cout<<"Second Data: "<<data2<<endl;
    cout<<"Third Data: "<<data3<<endl<<endl;
    vector<string> test;
    test.clear();
    test.push_back(data1);
    test.push_back(data2);
    test.push_back(data3);

    SetFileName(filename);

    int numb = test.size();
    SetRows(numb);
    GetHeader(testHeader,',');
    SetDataInfo(test);
    SetOutputLength();
    testRows=numb;
    return testRows;
}
void userData::PrintTest1()
{
    cout<<"<<PrintTest 1>>"<<endl;
    cout << "Reading the data from: " << fileName << endl ;

    cout << "|";
    for (int i = 0; i < headerSaved.size()-1; ++i)
    {
        cout << left << setw(outputManager.at(i)) << headerSaved.at(i) << "|";
    }
    cout << endl;

    PrintData();
    if (testRows == dataSaved.size()) {
        cout << "Right number of Data printed!" << endl << endl;
    }
    else {
        cout << "Wrong number of Data printed..." << endl << endl;
    }
}

void userData::EmployeePayRaiseReport()
{
    DataQualityReport();

    if(dataSaved.size()==0||rows==0||rows==-1)
    {
        return;
    }
    vector<int> location;
    location.clear();
    location.push_back(1);
    location.push_back(2);
    location.push_back(3);
    location.push_back(4);
    location.push_back(14);
    vector<string>tmp;
    vector<vector<string>>dataNeed;
    dataNeed.clear();
    int totalRow=0;

    for (int i = 0; i < rows; ++i)
    {try {
            tmp.clear();
            if(dataSaved.at(i).at(0)=="*D")
                throw i;
            if(dataSaved.at(i).at(0)=="*E")
                throw i;
            if(dataSaved.at(i).at(14)=="*E")
                throw i;
            for (int j = 0; j < location.size(); ++j)
            {
                tmp.push_back(dataSaved.at(i).at(location.at(j)));
            }
            dataNeed.push_back(tmp);
        }catch(int error)
        {}
    }
    moneyRaise.clear();
    moneyNew.clear();
    double salaryNew;
    double salaryRaise;
    double percentRaise=0.025;
    for(int i=0;i<dataNeed.size();++i)
    {
        salary=0;
        salaryNew=0;
        salary=stod(dataNeed.at(i).at(4));
        salaryNew=CalculateEmployeeRaise(percentRaise);
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
double userData::CalculateEmployeeRaise(double percentRaise)
{   double salaryNew=0;
    salaryNew=salary+salary*percentRaise;
    return  salaryNew;
}

void userData::RegionalRaisesReport()
{
    DataQualityReport();

    if(dataSaved.size()==0||rows==0||rows==-1)
    {
        return;
    }
    vector<int> location;
    location.clear();
    location.push_back(22);
    location.push_back(20);
    location.push_back(21);
    location.push_back(14);
    vector<string>tmp;
    vector<vector<string>>dataNeed;
    dataNeed.clear();
    int totalRow=0;

    for (int i = 0; i < rows; ++i)
    {
        try {
            tmp.clear();
            if(dataSaved.at(i).at(0)=="*D")
                throw i;
            if(dataSaved.at(i).at(0)=="*E")
                throw i;
            if(dataSaved.at(i).at(14)=="*E")
                throw i;
            if(dataSaved.at(i).at(22)=="*E")
                throw i;
            for (int j = 0; j < location.size(); ++j)
            {
                tmp.push_back(dataSaved.at(i).at(location.at(j)));
            }
            dataNeed.push_back(tmp);
        }catch(int error)
        {}
    }
    sort(dataNeed.begin(),dataNeed.end());
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
            if(dataNeed.at(i).at(0)==dataNeed.at(i+1).at(0))
            {   count++;

                cout<<left<<setw(5)<<count<<"|";
                riseTotal=riseTotal+moneyRaise.at(i);
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
                riseTotal=riseTotal+moneyRaise.at(i);

                cout<<left<<setw(5)<<count<<"|";
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
            riseTotal=riseTotal+moneyRaise.at(i);

            cout<<left<<setw(5)<<count<<"|";
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
            riseTotal=riseTotal+moneyRaise.at(i);

            cout<<left<<setw(5)<<count<<"|";
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

void userMenu()
{   userData data;
    char menuOption;
    string csvFileName="../data_v1.csv";
    string userFile;
    string fileName;
    cout<<"\nWELCOME TO JACK'S PROJECT!"<<endl;

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
                cout<<"Welcome to Phone Number List."<<endl;
                data.EmployeePhoneNumberList();
                break;

            case 'D':
            case 'd':
                cout<<"Welcome to Data Quality Report."<<endl;
                cout<<"The Empty data will be printed out \"*E\" on the Table."<<endl;
                cout<<"The Duplicated data will be printed out \"*D\" on the Table."<<endl;
                data.DataQualityReport();
                data.PrintDataQualityReport();
                break;
            case 'E':
            case 'e':
                cout<<"Welcome to Data Report without Duplicate or Empty ID."<<endl;
                cout<<"The Empty data will be printed out \"*E\" on the Table."<<endl;
                data.DataQualityReport();
                data.PrintNoError();
                    break;
            case 'Y':
            case 'y':
                cout<<"Welcome to Find the employee with Same parents Report."<<endl;
                cout<<"This report will show the employees who have the Parents.\n"<<endl;
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
                cout<<"Duplicated or empty ID or People without current salary will not be shown."<<endl;
                data.EmployeePayRaiseReport();
                break;

            case 'R':
            case 'r':
                cout<<"Welcome to Regional Raises Report."<<endl;
                cout<<"In this section, it will show the New salary related to zipcode."<<endl;
                cout<<"Duplicated or empty ID or People without current salary or Zipcode not be shown."<<endl;
                data.RegionalRaisesReport();
                break;

            case 'S':
            case 's':
                cout<<"Welcome to Sequence of All Reports (order: N, D, Y, C, P, R)"<<endl;
                cout<<"WARNING! Before you try, make sure read the File first by using \"F\" or \"I\"."<<endl;
                cout<<"In this section, it will show all the previous Report."<<endl;
                data.EmployeePhoneNumberList();
                data.PrintDataQualityReport();
                data.EmployeeFindFamily();
                data.EmployeeClusterReport();
                data.EmployeePayRaiseReport();
                data.RegionalRaisesReport();
                break;

            case '1':
                cout<<"Welcome to Test 1 Menu"<<endl;
                cout<<"This section will test if right number of raws printed out with set of data."<<endl<<endl;
                data.SetTest();
                data.PrintTest1();
                break;

            case '2':
                cout<<"Welcome to Test 2 Menu"<<endl;
                cout<<"WARNING! Before you try, make sure read the File first by using \"F\" or \"I\"."<<endl;
                cout<<"This section will use the same data as Test 1, but it will show the \"Employee Cluster Report\" with the Data from Test 1."<<endl<<endl;
                data.SetTest();
                data.EmployeeClusterReport();
                break;

            case 'T':
            case 't':
                cout<<"Welcome to \"Test 1\" and \"Test 2\" Menu"<<endl;
                cout<<"This section will use the same data as Test 1, but it will show the \"Test 1\" and \"Test 2\" output."<<endl<<endl;
                data.SetTest();
                data.PrintTest1();
                data.EmployeeClusterReport();
                break;

            case 'A':
            case 'a':
                cout<<"This is All Reports and All Tests Menu(order: S,T)"<<endl;
                data.EmployeePhoneNumberList();
                data.PrintDataQualityReport();
                data.EmployeeFindFamily();
                data.EmployeeClusterReport();
                data.EmployeePayRaiseReport();
                data.RegionalRaisesReport();
                data.SetTest();
                data.PrintTest1();
                data.EmployeeClusterReport();
                break;

            case 'Q':
            case 'q':
                goto EndOfLoop;

            default: cout<<"YOU PUT INVALID VALUE!!"<<endl<<endl;


        }
    }
    EndOfLoop:
    cout<<"Thanks for using Jack's Project! See you again.\n";
}



int main()
{   userMenu();
    return 0;
}

