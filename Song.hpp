//
//  Song.hpp
//  Song PlayList
//
//  Created by Macbook on 08/12/2023.
//

#ifndef Song_hpp
#define Song_hpp
#include <string>
#include <iostream>
using namespace std;

class Song {
private:
    string title;
    string artist;
    float duration;
    Song* next;
    
public:
    Song();
    
    void setTitle(string);
    void setArtist(string);
    void setDuration(float);
    void setNext(Song* next);
    
    string getTitle();
    string getArtist();
    float getDuration();
    Song* getNext();
};

#endif /* Song_hpp */
