#include <iostream>
#include "PlaylistNode.h"
using namespace std;

void PrintMenu()
{   PlayList list;
    char options;
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    int before, after;
    string title;
    cout<<"Enter playlist's title:"<<endl;
    getline(cin,title);
    while(true)
    {        cout<<"\n"<<title<<" PLAYLIST MENU"<<endl;
        cout<<"a - Add song"<<endl;
        cout<<"d - Remove song"<<endl;
        cout<<"c - Change position of song"<<endl;
        cout<<"s - Output songs by specific artist"<<endl;
        cout<<"t - Output total time of playlist (in seconds)"<<endl;
        cout<<"o - Output full playlist"<<endl;
        cout<<"q - Quit\n"<<endl;
        cout<<"Choose an option:"<<endl;
        cin>>options;
        cin.ignore();
        switch(options)
        {
            case('a')://impliment the adding function
                cout<<"ADD SONG"<<endl;
                cout<<"Enter song's unique ID:"<<endl;
                cin>>uniqueID;
                cin.ignore();
                cout<<"Enter song's name:"<<endl;
                getline(cin,songName);
                cout<<"Enter artist's name:"<<endl;
                getline(cin, artistName);
                cout<<"Enter song's length (in seconds):"<<endl;
                cin>>songLength;
                list.AddSong(uniqueID,songName,artistName,songLength);
                break;

            case('d'):
                cout<<"REMOVE SONG"<<endl;
                cout<<"Enter song's unique ID:"<<endl;
                cin>>uniqueID;
                //impliment the remove function.
                list.RemoveSong(uniqueID);
                break;
            case('c'):
                cout<<"CHANGE POSITION OF SONG"<<endl;
                cout<<"Enter song's current position:"<<endl;
                cin>>before;
                cout<<"Enter new position for song:"<<endl;
                cin>>after;
                list.ChangePosition(before, after);
                break;
            case('s'):
                cout<<"OUTPUT SONGS BY SPECIFIC ARTIST"<<endl;
                cout<<"Enter artist's name:"<<endl;
                getline(cin, artistName);
                list.SongsByArtist(artistName);

                break;
            case('t'):
                cout<<"OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)"<<endl;
                cout<<"Total time: "<<list.TotalTime()<<" seconds"<<endl;

                break;
            case('o'):
                cout<<title<<" - OUTPUT FULL PLAYLIST";
                list.PrintList();

                break;
            case('q'):
                exit(1) ;

            default:
                cout<<"Wrong value. Please try again\n"<<endl;
                break;

        }
    }

}
int main()
{
    PrintMenu();
    return 0;
}