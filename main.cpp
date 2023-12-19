//
//  main.cpp
//  Song PlayList
//
//  Created by Macbook on 08/12/2023.
//

#include <iostream>
#include "Playlist.hpp"
#include <string>

int main() {
    
    Playlist* list = new Playlist();
    int choice;
    char ch = 'y';
    
    do {
        cout<<"\n*********** PlayList *************";
        cout<<"\n* 1. Insert song at end          *";
        cout<<"\n* 2. Insert song at start        *";
        cout<<"\n* 3. Display All Songs           *";
        cout<<"\n* 4. Search a song by title      *";
        cout<<"\n* 5. Delete a song by title      *";
        cout<<"\n* 6. Delete first song           *";
        cout<<"\n* 7. Delete Last song            *";
        cout<<"\n* 8. Search Middle song          *";
        cout<<"\n* 9. Delete Middle song          *";
        cout<<"\n* 10. Reverse all songs          *";
        cout<<"\n* 11. Remove duplicate songs     *";
        cout<<"\n* 12. Longest duration song      *";
        cout<<"\n* 13. Merge two Playlists        *";
        cout<<"\n* 14. Exit                       *";
        cout<<"\n**********************************";
        cout<<"\nEnter your choiec: ";
        cin>>choice;
        
        switch (choice) {
            case 1: {
                cin.ignore();
                Song* newSong = new Song();
                
                float dur;
                string title;
                string artist;
                
                cout<<"\nEnter the name of the song: ";
                getline(cin,title);
                cout<<"\nEnter the name of the artist: ";
                getline(cin,artist);
                cout<<"\nEnter the duration of the song: ";
                cin>>dur;
                
                newSong->setTitle(title);
                newSong->setArtist(artist);
                newSong->setDuration(dur);
                list->insertSongAtEnd(newSong);
                
                break;
            }
            case 2:{
                
                cin.ignore();
                Song* newSong = new Song();
                
                float dur;
                string title;
                string artist;
                
                cout<<"\nEnter the name of the song: ";
                getline(cin,title);
                cout<<"\nEnter the name of the artist: ";
                getline(cin,artist);
                cout<<"\nEnter the duration of the song: ";
                cin>>dur;
                
                newSong->setTitle(title);
                newSong->setArtist(artist);
                newSong->setDuration(dur);
                list->insertSongAtStart(newSong);
                
                break;
            }
            case 3: {
                list->displayAll();
                
                break;
            }
            case 4: {
                string title;
                
                cin.ignore();
                cout<<"\nEnter the song title to search: ";
                getline(cin,title);
                
                list->searchByTitle(title);
                break;
            }
            case 5: {
                string title;
                
                cin.ignore();
                cout<<"\nEnter title of song to delete: ";
                getline(cin,title);
                
                list->deleteByTitle(title);
                break;
            }
            case 6: {
                list->deleteFirst();
                break;
            }
            case 7: {
                list->removeSongFromLast();
                break;
            }
            case 8: {
                list->searchMiddle();
                break;
            }
            case 9: {
                list->deleteMiddle();
                break;
            }
            case 10: {
                list->reverseList();
                break;
            }
            case 12: {
                list->findLongestSong();
                break;
            }
            case 14: {
                cout<<"\nExiting....\n";
                return 0;
            }
            default:
                cout<<"\nInvalid choice.";
        }
        
        cout<<"\nDo you want to repeat? Press Y: ";
        cin>>ch;
    }while(ch == 'Y' || ch == 'y');
}
