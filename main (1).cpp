#include <iostream>

#include <string>

#include "Playlist.h"

using namespace std;

Playlist* playlist;

// Print Menu Function
void PrintMenu(string title);

int main() {
    string title;
    
    cout << "Enter playlist's title:" << endl;
    getline(cin, title);
    cout << endl;

    // create playlist
    playlist = new Playlist();
    
    PrintMenu(title);

    return 0;
}

void PrintMenu(string title) {
    // bool to check when 'q' is reached
    bool quit = false;

    // until 'q' is entered, loop the menu and perform menu options
    while (!quit) {
        char option;
    
        cout << title << " PLAYLIST MENU" << endl;
        cout << "a - Add song" << endl;
        cout << "d - Remove song" << endl;
        cout << "c - Change position of song" << endl;
        cout << "s - Output songs by specific artist" << endl;
        cout << "t - Output total time of playlist (in seconds)" << endl;
        cout << "o - Output full playlist" << endl;
        cout << "q - Quit" << endl;
        cout << endl;
        cout << "Choose an option:" << endl;

        cin >> option;
        cin.ignore(); // ignore newline character 

        if (option == 'a') { // add song 
            string id;
            string songName;
            string artistName;
            int length;

            cout << "ADD SONG" << endl;

            cout << "Enter song's unique ID:" << endl;
            getline(cin, id);

            cout << "Enter song's name:" << endl;
            getline(cin, songName);

            cout << "Enter artist's name:" << endl;
            getline(cin, artistName);

            cout << "Enter song's length (in seconds):" << endl;
            cin >> length;

            cin.ignore(); // ignore newline character

            // create new playlist node to insert in the list
            PlaylistNode* newSong = new PlaylistNode(id, songName, artistName, length);
            
            // add function used to insert song at the end of the list or first if no songs are inputted already
            playlist->add(newSong);
            cout << endl;
        }

        else if (option == 'd') { // remove song
            string id;

            cout << "REMOVE SONG" << endl;

            cout << "Enter song's unique ID:" << endl;
            getline(cin, id);

            // calls function to remove song using id given and stores it in removed node
            PlaylistNode* removedNode = playlist->remove(id);

            // checks to see if removedNode isn't null, else it outputs that song is not found
            if (removedNode) {
                cout << '"' << removedNode->GetSongName() << '"' << " removed." << endl;
            }
            
            else {
                cout << "Song with unique ID " << id << " not found!" << endl;
            }

            cout << endl;
        }
    
        else if (option == 'c') { // change position of song
            int initialPosition;
            int newPosition;

            cout << "CHANGE POSITION OF SONG" << endl;

            cout << "Enter song's current position:" << endl;
            cin >> initialPosition;
            cout << "Enter new position for song:" << endl;
            cin >> newPosition;
            
            cin.ignore(); // ignores newline characters

            // calls change position function using initial and desired position entered
            playlist->changePosition(initialPosition, newPosition);
            cout << endl;
        }

        else if (option == 's') { // output songs by artist
            string artistName;

            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
        
            cout << "Enter artist's name:" << endl;
            getline(cin, artistName);

            cout << endl;

            // calls function to output all songs by artist using artist name entered
            playlist->songsByArtist(artistName);
        }

        else if (option == 't') { // total time of playlist
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;

            // calls function to find total time
            cout << "Total time: " << playlist->totalTime() << " seconds" << endl;
            cout << endl;
        }

        else if (option == 'o') { // output full playlist
           
            // calls print function to print whole playlist 
            playlist->print(title);
        }   

        else if (option == 'q') { 
            // quit bool set to true when 'q' is entered to end while loop
            quit = true;
        }

        // if none of the options are entered, output "invalid selection" and loop again
        else {
            cout << "Invalid selection." << endl;
        }
    }
}
