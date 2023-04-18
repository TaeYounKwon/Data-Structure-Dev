#include "PlaylistNode.h"
#include <iostream>
using namespace std;

PlaylistNode::PlaylistNode()
{
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = 0;
};
PlaylistNode::PlaylistNode(string uniqueID, string songName, string artistName, int songlength, PlaylistNode* nextLoc)
{
    this->uniqueID = uniqueID;
    this->songName = songName;
    this->artistName = artistName;
    this->songLength = songlength;
    this->nextNodePtr = nextLoc;
};
void PlaylistNode::InsertAfter(PlaylistNode* nodeLoc) {
    this->SetNext(nodeLoc->GetNext());
    nodeLoc->SetNext(this);
}
void PlaylistNode::SetNext(PlaylistNode *nodeLoc)
{
    nextNodePtr=nodeLoc;
}
string PlaylistNode::GetID()
{
    return this->uniqueID;
}
string PlaylistNode::GetSongName()
{
    return this->songName;
}
string PlaylistNode::GetArtistName()
{
    return this-> artistName;
}
int PlaylistNode::GetSongLength()
{
    return this-> songLength;
}

void PlaylistNode::PrintPlaylistNode() {
    cout << "Unique ID: "<<uniqueID << endl;
    cout << "Song Name: "<<songName<< endl;
    cout << "Artist Name: "<<artistName<<endl;
    cout << "Song Length (in seconds): "<<songLength<<endl;
}

PlaylistNode* PlaylistNode::GetNext() {
    return this->nextNodePtr;
}
PlayList::PlayList()
{
    head=tail=0;
}
void PlayList::AddSong(string id, string songname, string artistname, int songlength)
{
    PlaylistNode*n = new PlaylistNode(id, songname, artistname, songlength);
    if(head==0)
        head=tail=n;
    else
    {
        n->InsertAfter(tail);
        tail=n;
    }
}
bool PlayList::RemoveSong(string id)
{
    if(head==nullptr)
    {
        cout<<"Playlist is empty"<<endl;
        return false;
    }
    PlaylistNode* curr = head;
    PlaylistNode* prev = nullptr;
    while(curr != nullptr)
    {
        if(curr->GetID()==id)
        {break;}
        prev=curr;
        curr=curr->GetNext();
    }
    if(curr==nullptr)
    {
        return false;
    }
    else
    {
        if(prev != nullptr)
            prev->SetNext(curr->GetNext());
        else
            head=curr->GetNext();
        if(tail==curr)
            tail=prev;
        cout<<"\""<<curr->GetSongName()<<"\" removed."<<endl;
        delete curr;
        return true;
    }
}
bool PlayList::ChangePosition(int before, int after)
{
    if(head== nullptr)
    {
        cout<<"Playlist is empty"<<endl;
        return false;
    }
    PlaylistNode* prev=nullptr;
    PlaylistNode* curr=head;
    int position;
    if (head == nullptr || head==tail)
        return false;
    for (position =1;curr != nullptr&&position<before;position++)
    {
        prev=curr;
        curr=curr->GetNext();
    }
    if(curr != nullptr)
    {
        string currentSong = curr->GetSongName();
        if(prev==nullptr)
            head=curr->GetNext();
        else
            prev->SetNext(curr->GetNext());
        if (curr==tail)
            tail=prev;
        PlaylistNode* curr1=curr;
        prev=nullptr;
        curr=head;
        for (position = 1; curr != NULL && position < after; position++)
        {
            prev = curr;
            curr = curr->GetNext();
        }
        if (prev == NULL)
        {
            curr1->SetNext(head);
            head = curr1;
        }
        else
            curr1->InsertAfter(prev);

        if (curr == NULL)
            tail = curr1;


        cout << "\"" << currentSong << "\" moved to position " << after<< endl;
        return true;

    }
    else
    {
        cout << "Song's current position is invalid" << endl;
        return false;
    }
}

// SongsByArtist function implementation
void PlayList::SongsByArtist(string artist)
{
    if (head == NULL)
        cout << "Playlist is empty" << endl;
    else
    {
        PlaylistNode* curr = head;
        int i = 1;
        while (curr != NULL)
        {
            if (curr->GetArtistName() == artist)
            {
                cout << "\n" << i << "."<<endl;
                curr->PrintPlaylistNode();
            }
            curr = curr->GetNext();
            i++;
        }
    }
}

// TotalTime function implementation
int PlayList::TotalTime()
{
    int total = 0;
    PlaylistNode* curr = head;

    while (curr != NULL)
    {
        total += curr->GetSongLength();
        curr = curr->GetNext();
    }

    return total;
}


// PrintList function implementation
void PlayList::PrintList()
{
    if (head == NULL)
        cout <<endl <<"Playlist is empty" << endl;
    else
    {
        PlaylistNode* curr = head;
        int i;
        for(i=1;curr != NULL;++i)
        {
            cout << "\n"<< i << "." << endl;
            curr->PrintPlaylistNode();
            curr = curr->GetNext();
        }
    }
}