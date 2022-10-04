#include <iostream>
using namespace std;


int main()
{
    int a=3;
    int* p=nullptr;
    p=&a;
    cout<<a<<endl;
    cout<<&a<<endl;
    cout<<p<<endl;
    cout<<*p<<endl;
    return 0;


}