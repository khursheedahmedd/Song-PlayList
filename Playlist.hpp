//
//  Playlist.hpp
//  Song PlayList
//
//  Created by Macbook on 08/12/2023.
//

#ifndef Playlist_hpp
#define Playlist_hpp
#include "Song.hpp"

class Playlist {
private:
    Song* head;
    int count;
    
public:
    Playlist();
    
    void insertSongAtEnd(Song* song);
    void displayAll();
    void searchByTitle(string);
    void deleteByTitle(string);
    void deleteFirst();
    void deleteLast();
    void searchMiddle();
    void deleteMiddle();
    void removeDuplicate();
    void mergeTwoList(Song* list1, Song* list2);
    void insertSongAtStart(Song* song);
    void removeSongFromLast();
    void reverseList();
    void findLongestSong();
//    Song* findSong(string);
    
};

#endif /* Playlist_hpp */
