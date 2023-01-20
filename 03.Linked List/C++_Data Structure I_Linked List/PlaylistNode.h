#include <iostream>
using namespace std;
#include <string>
#ifndef UNTITLED2_PLAYLISTNODE_H
#define UNTITLED2_PLAYLISTNODE_H


class PlaylistNode {
public:
    PlaylistNode();
    PlaylistNode(string uniqueID, string songName, string artistName, int songlength, PlaylistNode* nextLoc = nullptr);
    void InsertAfter(PlaylistNode* nodeLoc);
    void SetNext(PlaylistNode* nodeLoc);
    PlaylistNode* GetNext();
    string GetID();
    string GetSongName();
    string GetArtistName();
    int    GetSongLength();
    void PrintPlaylistNode();

private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr=nullptr;

};
class PlayList
{
private:
    PlaylistNode* head;
    PlaylistNode* tail;
public:
    PlayList();
    void AddSong(string id, string songname, string artistname, int songlength);
    bool RemoveSong(string id);
    void PrintList();
    bool ChangePosition(int before, int after);
    void SongsByArtist(string artist);
    int TotalTime();
};


#endif //UNTITLED2_PLAYLISTNODE_H
