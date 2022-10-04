#include <iostream>
#include <vector>// FIXME include vector library
using namespace std;

int main() {

    vector<int> numJersey;
    vector<int> rating;
    int numPlayer=5;
    unsigned int i;
    int newJersey;
    int newrating;
    int renewrating;
    int aboverating;
    int delJersey;
    int numJersey2;
    numJersey.resize(numPlayer); //Allocate elements
    rating.resize(numPlayer);
    char option;

    //getting data(jersey number and rating) from users
    for(i=0;i<numJersey.size();++i)
    {
        cout << "Enter player " << i + 1 << "'s jersey number:" << endl;
        cin >> numJersey.at(i);
        cout << "Enter player " << i + 1 << "'s rating:" << endl;
        cin >> rating.at(i);
        cout<<endl;
    }
    //printing out the ROSTER
    cout << "ROSTER" << endl;
    for (i = 0; i < numJersey.size(); ++i)
    {
        cout << "Player " << i + 1 << " -- Jersey number: " << numJersey.at(i) << ", Rating: " << rating.at(i)
             << endl;
    }
    //menu starts
    while(option!='q')
    {
        cout<<endl<<"MENU"<<endl;
        cout<<"a - Add player"<<endl;
        cout<<"d - Remove player"<<endl;
        cout<<"u - Update player rating"<<endl;
        cout<<"r - Output players above a rating"<<endl;
        cout<<"o - Output roster"<<endl;
        cout<<"q - Quit"<<endl<<endl;
        cout<<"Choose an option:"<<endl;
        cin>>option;
        {
            switch (option)
            { case'a'://Add player
                    cout<<"Enter a new player's jersey number:"<<endl;
                    cin>>newJersey;
                    numJersey.push_back(newJersey);
                    cout<<"Enter the player's rating:"<<endl;
                    cin>>newrating;
                    rating.push_back(newrating);
                    break;
                case'd'://Remove Player
                    cout<<"Enter a jersey number:"<<endl;
                    cin>>delJersey;
                    for(i=0;i<numJersey.size();++i)
                    {
                        if(delJersey==numJersey.at(i))
                        {
                            numJersey.erase(numJersey.begin()+i);
                            rating.erase(rating.begin()+i);
                        }
                    }
                    break;
                case'u'://Update Player rating
                    cout<<"Enter a jersey number:"<<endl;
                    cin>>numJersey2;
                    cout<<"Enter a new rating for player:"<<endl;
                    cin>>renewrating;
                    for(i=0;i<numJersey.size();++i)
                    {
                        if (numJersey2 == numJersey.at(i)) {
                            rating.at(i) = renewrating;
                        }
                    }
                    break;
                case'r'://Output Player above a rating
                    cout<<"Enter a rating:"<<endl;
                    cin>>aboverating;
                    cout<<endl<<"ABOVE "<<aboverating<<endl;
                    for(i=0;i<numJersey.size();++i)
                    {
                        if(rating.at(i)>aboverating)
                        {cout<<"Player "<<i+1<< " -- Jersey number: " << numJersey.at(i)
                             << ", Rating: " << rating.at(i)<<endl;}

                    }

                    break;
                case'o'://Output Roster
                    cout << "ROSTER" << endl;
                    for (i = 0; i < numJersey.size(); ++i)
                    {
                        cout << "Player " << i + 1 << " -- Jersey number: " << numJersey.at(i)
                             << ", Rating: " << rating.at(i)
                             << endl;
                    }
                    break;
                case'q'://Quit
                    return 0;
                default:break;
            }
        }
    }
    return 0;
}
