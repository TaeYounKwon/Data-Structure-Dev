# include<vector>
# include <iostream>
# include <string>
using namespace std;
#ifndef MAIN_CPP_TEST_H
#define MAIN_CPP_TEST_H

#include "userData.h"

class userTest:public userData // inherit from userData
{
public:
    userTest();
    userTest(int testRows); // constructor
    int SetTest();
    void PrintTest1();
    void Test2();
private:
    int testRows;
};


#endif //MAIN_CPP_TEST_H
