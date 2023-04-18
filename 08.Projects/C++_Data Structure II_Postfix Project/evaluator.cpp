#include "evaluator.h"
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;


double Evaluate(const string& postfix, bool& error){
stack<double> dataStack;
vector<string> dataSaved;
double _calVal;

char findError[postfix.size()];
//에러 찾기 위해 char val에 값을 대입함
for(size_t i=0; i<postfix.size(); ++i)
{
    findError[i]=postfix.at(i);
}
//글자가 들어오면 에러
for(size_t i=0; i<postfix.size();++i)
{
if(findError[i]!='+'
   &&findError[i]!='-'
   &&findError[i]!='*'
   &&findError[i]!='/'
   &&findError[i]!='^'
   &&findError[i]!=' '
   &&findError[i]!='.'
   &&isdigit(findError[i])==false)
{
    error=true;
    return -1;
}
}

char* _dataDiv=strtok((char*)postfix.c_str()," ");
while(_dataDiv)
{
    dataSaved.push_back(_dataDiv);
    _dataDiv=strtok(nullptr," ");
}



for(size_t i=0; i<dataSaved.size();i++)
{
    if(atoi(dataSaved.at(i).c_str())!=0&&(dataSaved.at(i).find("+")==true||dataSaved.at(i).find("-")==true||dataSaved.at(i).find("*")==true
                                                                                                            ||dataSaved.at(i).find("/")==true
                                                                                                              ||dataSaved.at(i).find("^")==true
    ))
    {
        error=true;
        return -1;
    }

    else if( dataSaved.at(i)=="+" || dataSaved.at(i)=="-" || dataSaved.at(i)=="*" || dataSaved.at(i)=="/" || dataSaved.at(i)=="^")
    {
        double _val1=dataStack.top();
        dataStack.pop();

        if(dataStack.empty())
        {
            error=true;
            return -1;
        }

        double _val2=dataStack.top();
        dataStack.pop();

        if(dataSaved.at(i)=="+") {
            dataStack.push(_val2+_val1  );
        }
        else if(dataSaved.at(i)=="-") {
            dataStack.push( _val2-_val1 );
        }
        else if(dataSaved.at(i)=="*") {
            dataStack.push( _val2*_val1 );
        }
        else if(dataSaved.at(i)=="/") {
            dataStack.push(_val2 / _val1);
        }
        else if(dataSaved.at(i)=="^") {
            dataStack.push(pow(_val2, _val1));
        }
    }
    else
    {
        dataStack.push(stod(dataSaved.at(i)));
    }
}

    dataSaved.clear();
    error=false;
    _calVal= dataStack.top();
    dataStack.pop();
    return _calVal;

}
