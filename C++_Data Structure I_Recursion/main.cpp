#include <iostream>
#include <string>
#include <vector>

using namespace std;

void AllPermutations(const vector<string> &permList, const vector<string> &nameList)
{
    if(nameList.empty())
    {
        for(string permString : permList)
        {
            cout << permString << " ";
        }
        cout << endl;
        return;
    }
    for(int i=0; i<nameList.size(); i++)
    {
        vector<string> perm = permList;
        perm.push_back(nameList[i]);
        vector<string> name = nameList;
        name.erase(name.begin() + i);
        AllPermutations(perm, name);
    }
}

int main(int argc, char* argv[])
{
    vector<string> nameList;
    vector<string> permList;
    string name;

    while(cin >> name)
    {
        if(name == "-1")
        {
            break;
        }
        nameList.push_back(name);
    }
    AllPermutations(permList, nameList);
    return 0;
}