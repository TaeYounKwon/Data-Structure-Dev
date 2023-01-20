#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

int main(int argc, char* argv[])
{
    string inputName;
    int age;
    // Set exception mask for cin stream
    cin.exceptions(ios::failbit);

    cin >> inputName;
    while(inputName != "-1")
    {
        try
        {
            cin >> age;
            if(cin.fail())
            {throw runtime_error("");}
            cout << inputName << " " << (age + 1) << endl;
            cin >> inputName;
        }

        catch(runtime_error& excpt)
        {   string iName;
            int inumber;
            cout<<inputName<<" 0"<<endl;
            cin.clear();
            cin>>iName;
            cin>>inumber;
            cin>>inputName;
        }

    }

    return 0;
}