//
//  Playlist.cpp
//  Song PlayList
//
//  Created by Khursheed on 08/12/2023.
//

#include "Playlist.hpp"

// Playlist::Playlist() : head(NULL)
// {
//     count = 0;
// }

void Playlist::insertSongAtEnd(Song *newSong)
{
    if (head == NULL)
    {
        head = newSong;
        newSong->setNext(NULL);
        count++;

        cout << "\nThe song is inserted successfully.";
    }
    else
    {
        Song *temp = head;

        while (temp->getNext() != NULL)
        {
            temp = temp->getNext();
        }
        temp->setNext(newSong);
        newSong->setNext(NULL);
        count++;

        cout << "\nThe song is inserted successfully.";
    }
}

void Playlist::displayAll()
{
    if (head == NULL)
    {
        cout << "\nThe playlist is empty.";
        return;
    }

    Song *temp = head;
    int i = 1;
    cout << "========== Playlist ============";
    while (temp != NULL)
    {
        cout << "\n\t\t*---(" << i << ")---*";
        cout << "\nTitle: " << temp->getTitle();
        cout << "\nArtist: " << temp->getArtist();
        cout << "\nDuration: " << temp->getDuration() << "\n";
        i++;
        temp = temp->getNext();
    }
}

void Playlist::insertSongAtStart(Song *newSong)
{
    if (head == NULL)
    {
        head = newSong;
        newSong->setNext(NULL);
        count++;

        cout << "\nThe song is inserted succussfully.";
    }
    else
    {
        newSong->setNext(head);
        head = newSong;
        count++;

        cout << "\nThe node is inserted successfully.";
    }
}

void Playlist::searchByTitle(string title)
{
    if (head == NULL)
    {
        cout << "\nThe playlist is empty.";
        return;
    }

    Song *temp = head;

    if (count == 1 && title == temp->getTitle())
    {
        cout << "\nSong found in list.\n";
        cout << "\nTitle: " << head->getTitle();
        cout << "\nArtist: " << head->getArtist();
        cout << "\nDuration: " << head->getDuration();
        return;
    }

    while (temp->getNext() != NULL)
    {
        temp = temp->getNext();

        if (temp->getTitle() == title)
        {
            cout << "\nSong found in list.\n";
            cout << "\nTitle: " << temp->getTitle();
            cout << "\nArtist: " << temp->getArtist();
            cout << "\nDuration: " << temp->getDuration();
            return;
        }
    }

    cout << "\nThe song not found in list.";
}

void Playlist::deleteByTitle(string title)
{
    if (head == NULL)
    {
        cout << "\nThe playlist is empty.";
        return;
    }

    Song *curr = head;
    Song *prev = NULL;

    if (head->getNext() == NULL)
    {
        head = curr->getNext();
        delete curr;
        count--;

        cout << "\nThe song is deleted successfully.";
        return;
    }

    while (curr->getNext() != NULL && title != curr->getTitle())
    {
        prev = curr;
        curr = curr->getNext();
    }

    if (curr == nullptr)
    {
        cout << "\nThe song is not found in playlist.";
        return;
    }

    if (prev != nullptr)
    {
        prev->setNext(curr->getNext());
    }
    else
    {
        head = curr->getNext();
    }

    delete curr;
    count--;
    cout << "\nThe song is deleted successfully.";
}

void Playlist::deleteFirst()
{
    if (head == NULL)
    {
        cout << "\nThe playlist is empty.";
        return;
    }

    Song *temp = head;
    head = temp->getNext();

    delete temp;
    count--;

    cout << "\nThe first song is deleted successfully.";
}

void Playlist::removeSongFromLast()
{
    if (head == NULL)
    {
        cout << "\nThe list is empty.";
        return;
    }

    Song *curr = head;
    Song *prev = NULL;

    if (curr->getNext() == NULL)
    {
        head = NULL;
        delete curr;

        count--;

        cout << "\nThe last song is deleted successfully.";
        return;
    }

    while (curr->getNext() != NULL)
    {
        prev = curr;
        curr = curr->getNext();
    }

    prev->setNext(NULL);
    delete curr;

    cout << "\nThe song is deleted successfully.";
}

void Playlist::searchMiddle()
{
    if (head == NULL)
    {
        cout << "\nThe playlist is empty.";
        return;
    }

    Song *fastPtr = head;
    Song *slowPtr = head;

    if (fastPtr->getNext() == NULL)
    {
        cout << "\n\t\t*---(" << count << ")---*";
        cout << "\nTitle: " << fastPtr->getTitle();
        cout << "\nArtist: " << fastPtr->getArtist();
        cout << "\nDuration: " << fastPtr->getDuration();
        return;
    }

    int i = 0;
    while (fastPtr->getNext() != NULL && fastPtr->getNext()->getNext() != NULL)
    {
        fastPtr = fastPtr->getNext()->getNext();
        slowPtr = slowPtr->getNext();
        i++;
    }

    cout << "\n\t\t*---(" << i << ")---*";
    cout << "\nTitle: " << slowPtr->getTitle();
    cout << "\nArtist: " << slowPtr->getArtist();
    cout << "\nDuration: " << slowPtr->getArtist();
}

void Playlist::deleteMiddle() /***/
{
    if (head == NULL)
    {
        cout << "\nThe playlist is empty.";
        return;
    }

    Song *fastPtr = head;
    Song *slowPtr = head;
    Song *prev = NULL;

    if (fastPtr->getNext() == NULL)
    {
        delete fastPtr;
        count--;

        cout << "\nThe song is deleted successfully.";
        return;
    }

    while (fastPtr->getNext() != NULL)
    {
        fastPtr = fastPtr->getNext()->getNext();
        prev = slowPtr->getNext();
        slowPtr = slowPtr->getNext();
    }

    prev->setNext(slowPtr->getNext());
    delete slowPtr;
    count--;

    cout << "\nThe song is deleted successfully.";
}

void Playlist::reverseList()
{
    if (head == nullptr || head->getNext() == nullptr)
    {
        return;
    }

    Song *prev = nullptr;
    Song *current = head;
    Song *next = nullptr;

    while (current != nullptr)
    {
        next = current->getNext();
        current->setNext(prev->getNext());
        prev = current;
        current = next;
    }

    head = prev;
}

void Playlist::findLongestSong()
{
    if (head == nullptr)
    {
        std::cout << "\nThe list is empty." << std::endl;
        return;
    }

    int max = head->getDuration();
    Song *newSong = head;
    Song *temp = head->getNext();

    while (temp != nullptr)
    {
        if (temp->getDuration() > max)
        {
            max = temp->getDuration();
            newSong = temp;
        }
        temp = temp->getNext();
    }
    cout << "\ntitle " << newSong->getTitle();
    cout << "\nArtist " << newSong->getArtist();
    cout << "\nDuration " << newSong->getDuration();
}

// Song* Playlist::binarySearchByTitle( string title) {
//         if (head == nullptr || count== 0) {
//             cout << "Playlist is empty." << endl;
//             return nullptr;
//         }
//
//         int low = 0;
//         int high = count - 1;
//
//         while (low <= high) {
//             int mid = low + (high - low) / 2;
//             if (songArray[mid]->title == title) {
//                 return songArray[mid];
//             } else if (songArray[mid]->title < title) {
//                 low = mid + 1;
//             } else {
//                 high = mid - 1;
//             }
//         }
//
//         cout << "Song not found!" << endl;
//         return nullptr;
//     }
