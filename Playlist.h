#pragma once

#include <string>

using namespace std;

class PlaylistNode {
    public:
    //default constructor
    PlaylistNode();

    //Parameterized constructor
    PlaylistNode(string, string, string, int);

    void InsertAfter(PlaylistNode*);
    
    //mutator
    void SetNext(PlaylistNode* );
    
    //accessors
    string GetID() const;
    string GetSongName() const;
    string GetArtistName() const;
    int GetSongLength() const;
    PlaylistNode* GetNext() const;
    
    void PrintPlaylistNode() const;

    private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;
};

//Playlist class for menu options
class Playlist {
    private:
    PlaylistNode* head;
    PlaylistNode* tail;

    public:
    Playlist();

    bool empty() const; //bool to check if playlist is empty

    //menu options
    void print(string) const;
    void add(PlaylistNode*);
    PlaylistNode* remove(string);
    void changePosition(int, int);
    void songsByArtist(string) const;
    int totalTime() const;
};