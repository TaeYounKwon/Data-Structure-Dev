#include <iostream>
#include <iomanip>              // For setprecision
#include <vector>               // Include vector library
using namespace std;

int main()
{
    vector<double> userWeight;
    int numWeight=5;
    double totalWeight=0;
    double maxWeight=0;
    unsigned int i;

    userWeight.resize(numWeight); //Allocate elements

    //getting the data from the users
    for(i=0;i<userWeight.size();++i)
    {
        cout<<"Enter weight "<<i+1<<":"<<endl;
        cin>>userWeight.at(i);
    }

    //show the data that users typed
    cout<<"You entered: ";
    for(i=0; i<userWeight.size();++i)
    {
        cout<<fixed<<setprecision(2)<<userWeight.at(i)<<" ";
    }

    cout<<endl;

    //show the Total weight of the data
    cout<<"\n"<<"Total weight: ";
    for(i=0; i<userWeight.size();++i)
    {
        totalWeight=totalWeight+userWeight.at(i);
    }
    cout<<fixed<<setprecision(2)<<totalWeight<<endl;

    //show the Average weight of the data
    cout<<"Average weight: "<<fixed<<setprecision(2)<<totalWeight/numWeight<<endl;

    //show the Max weight of the data
    cout<<"Max weight: ";
    for(i=0; i<5;++i)
    {
        if(userWeight.at(i)>=maxWeight)
        {
            maxWeight=userWeight.at(i);
        }
    }
    cout<<fixed<<setprecision(2)<<maxWeight<<endl;

    return 0;
}