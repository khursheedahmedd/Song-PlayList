//
//  Song.cpp
//  Song PlayList
//
//  Created by Macbook on 08/12/2023.
//

#include "Song.hpp"

Song::Song() {
    title = getTitle();
    artist = getArtist();
    duration = getDuration();
    next = NULL;
    
}

void Song::setTitle(string title) {
    this->title = title;
}
string Song::getTitle() {
    return title;
}

void Song::setNext(Song* next) {
    this->next = next;
}
Song* Song::getNext() {
    return next;
}

void Song::setArtist(string artist) {
    this->artist = artist;
}
string Song::getArtist() {
    return artist;
}

void Song::setDuration(float duration) {
    this->duration = duration;
}
float Song::getDuration() {
    return duration;
}


