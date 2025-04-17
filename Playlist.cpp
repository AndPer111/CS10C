#include <iostream>

#include "Playlist.h"

using namespace std;

PlaylistNode::PlaylistNode() : uniqueID("none"), songName("none"), artistName("none"), songLength(0), nextNodePtr(0) {
}

PlaylistNode::PlaylistNode(string id, string name, string artist, int lengthOfSong) {
    uniqueID = id;
    songName = name;
    artistName = artist;
    songLength = lengthOfSong;
    nextNodePtr = nullptr;
}


void PlaylistNode::InsertAfter(PlaylistNode* nodeToInsert) {
    PlaylistNode* curr = nextNodePtr;
    nextNodePtr = nodeToInsert;
    
    nodeToInsert->SetNext(curr);
}

void PlaylistNode::SetNext(PlaylistNode* newNode) {
    if (newNode == nullptr) {
        nextNodePtr = nullptr;
    }

    else {
        nextNodePtr = newNode;
    }
}

string PlaylistNode::GetID() const {
    return uniqueID;
}

string PlaylistNode::GetSongName() const {
    return songName;
}

string PlaylistNode::GetArtistName() const {
    return artistName;
}

int PlaylistNode::GetSongLength() const {
    return songLength;
}

PlaylistNode* PlaylistNode::GetNext() const {
    return nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode() const {
    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length (in seconds): " << songLength << endl;
}

Playlist::Playlist() : head(nullptr), tail(nullptr) {
}

void Playlist::print(string title) const {
    cout << title << " - OUTPUT FULL PLAYLIST" << endl;

    if(empty()) {
        cout << "Playlist is empty" << endl;
        cout << endl;
    }

    else {
        int count = 1;
        PlaylistNode* curr = head;

        // while loop to print songs in a numerical list
        while (curr != nullptr) {
            cout << count << "." << endl;
            curr->PrintPlaylistNode();
            cout << endl;

            ++count;
            curr = curr->GetNext();
        }
    }
}

bool Playlist::empty() const {
    return head == nullptr;
}

void Playlist::add(PlaylistNode* curr) {
    if(empty()) {
        head = curr;
        tail = curr;
    }

    // if empty is not true, call set next for curr node and set tail to curr node
    else {
        tail->SetNext(curr);
        tail = curr;
    }
}

PlaylistNode* Playlist::remove(string id) {
    PlaylistNode* prev = nullptr;
    PlaylistNode* curr = head;

    // while curr isn't nullptr and it's id doesn't equal id entered, move along the list till it's found
    while (curr && curr->GetID() != id) {
        prev = curr;
        curr = curr->GetNext();
    }

    // to remove node after while loop stops, if it's not there return nullptr
    if (curr) {
        // if prev isn't nullptr, set prev's next to curr's next removing curr
        if (prev) {
            prev->SetNext(curr->GetNext());
        }

        // if prev is nullptr than head becomes curr's next removing curr
        else {
            head = curr->GetNext();
        }

        // if curr is the tail then prev becomes the tail
        if (not curr->GetNext()) {
            tail = prev;
        }

        return curr;
    }

    else {
        return nullptr;
    }
}

void Playlist::changePosition(int initialPosition, int newPosition) {
    int index = 1;
    PlaylistNode* prev = nullptr;
    PlaylistNode* curr = head;

    if (initialPosition < 1) {
        cout << "Invalid current posititon." << endl;
        return;
    }

    // while loop to get intial position of node
    while (index < initialPosition) {
        
        // if curr isn't nullptr, set prev to curr and curr to get next while increasing the index
        if (curr) {
            prev = curr;
            curr = curr->GetNext();
            ++index;
    
            if (not curr) {
                cout << "Invalid current position." << endl;
                return;
            }
        }

        else {
            cout << "Invalid current position." << endl;
            return;
        }
    }

    // remove node from the list and set prev's next to curr's next
    if (prev) {
        prev->SetNext(curr->GetNext());
    }

    else {
        head = curr->GetNext();
    }

    // if curr is last element, make tail to point to previous node
    if (curr == tail) {
        tail = prev;
    }

    // place node in new position
    if (newPosition <= 1) { // for nodes inserted at head
        if (empty()) {
            tail = curr;
        }

        curr->SetNext(head);
        head = curr;
        cout << '"' << curr->GetSongName() << '"' << " moved to position 1" << endl;
    }

    else { // for nodes inserted after head
        
        if(empty()) { 
            add(curr);
            cout << '"' << curr->GetSongName() << '"' << " moved to position 1" << endl;
        }

        else {
            int newIndex = 2;
            PlaylistNode* prevNode = head;
            PlaylistNode* nextNode = head->GetNext();

            // while loop to get new position index
            while (newIndex < newPosition && nextNode) {
                prevNode = nextNode;
                nextNode = nextNode->GetNext();
                ++newIndex;
            }

            prevNode->InsertAfter(curr);

            if (not nextNode) { // node inserted at tail
                tail = curr;
            }

            cout << '"' << curr->GetSongName() << '"' << " moved to position " << newIndex << endl;
        }
    }
}

void Playlist::songsByArtist(string artist) const {
    int count = 1;
    PlaylistNode* curr = head;

    while (curr != nullptr) {

        // while curr isn't nullptr and the artist name matches the one entered, output artists songs
        if (curr->GetArtistName() == artist) {
            cout << count << "." << endl;
            curr->PrintPlaylistNode();
            cout << endl;
        }

        ++count;
        curr = curr->GetNext();
    }
}

int Playlist::totalTime() const {
    int total = 0;
    PlaylistNode* curr = head;

    // while curr isn't nullptr, get sum of all song lengths to get total time of playlist
    while (curr) {
        total += curr->GetSongLength();
        curr = curr->GetNext();
    }

    return total;
}