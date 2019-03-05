/* 
 * artist.cpp
 *
 * David Alejandro Martinez Tristan
 * 28/02/2019
*/

#include <iostream>
#include "Artist.h"
#include "Song.h"
#define ARTISTS_SIZE 20
#define SONGS_SIZE 50
#define SONG_ADDED 1
#define ADD_NEW_ARTIST 1
#define ADD_NEW_SONG 2
#define MODIFY_SONG 3
#define DISPLAY_SONGS_ARTIST_ID 4
#define DISPLAY_SONGS_ARTIST_ALBUM 5
#define DISPLAY_ARTISTS_COMPANY 6
#define DISPLAY_INFO_ARTIST_NAME 7
#define DISPLAY_INFO_SONG_ID 8
#define DISPLAY_NUMBER_SONGS_ARTIST_NAME 9
#define END_PROGRAM 10

using namespace std;

void addArtist(Artist* artists, int& artistCount);
void addSongToArtist(Artist* artists);
void modifySong(Artist* artists);
void displaySongArtistId(Artist* artists);
void displaySongArtistAlbum(Artist* artists);
void displayArtistsCompany(Artist* artists);

void executeChoice(Artist* artists, char choice, int& artistCount);



int main(void)
{
    int choice, artistCount;
    Artist artists[ARTISTS_SIZE];

    artistCount = 0;

    do
    {
        cout << "Please choose an option:" << endl;
        cout << "1- Add new artist" << endl;
        cout << "2- Add new song" << endl;
        cout << "3- Modify song of an artist" << endl;
        cout << "4- Display all songs of an artist" << endl;
        cout << "5- Display all songs of an album" << endl;
        cout << "6- Display all artists of a company" << endl;
        cout << "7- Display all info of an artist" << endl;
        cout << "8- Display all info of a song" << endl;
        cout << "9- Display number of songs of an artist" << endl;
        cout << "10- End the program" << endl;
        cin >> choice;
        if (choice < ADD_NEW_ARTIST || choice > END_PROGRAM)
            cout << "Option not valid" << endl;
        else
            executeChoice(artists, choice, artistCount);
    } while (choice != END_PROGRAM);

    return 0;
}

void addArtist(Artist* artists, int& artistCount)
{
    if (artistCount == ARTISTS_SIZE)
    {
        cout << "Artist array is full, no more artists can be added." << endl << endl;
        return;
    }

    int id;
    string name, company;

    cout << "Please give artist id: ";
    cin >> id;

    for (int i = 0; i < ARTISTS_SIZE; i++)
    {
        if (id == artists[i].getId())
        {
            cout << "The given id is already registered and linked to an artist." << endl;
            return;
        }
    }

    cout << "Please give artist name: ";
    getline(cin, name);

    cout << "Please give artist company: ";
    getline(cin, company);

    artists[artistCount].setId(id);
    artists[artistCount].setName(name);
    artists[artistCount].setCompany(company);

    artistCount++;
}

void addSongToArtist(Artist* artists)
{
    int artistId; 

    cout << "Please give artist id: ";
    cin >> artistId;

    for (int i = 0; i < ARTISTS_SIZE; i++)
    {
        if (artistId == artists[i].getId())
        {
            int songId;
            string songName, songAlbum;
            Song song;
            
            cout << "Please give song id: ";
            cin >> songId;
            cout << "Please give song name: ";
            getline(cin, songName);
            cout << "Please give song album: ";
            getline(cin, songAlbum);

            song.setId(songId);
            song.setName(songName);
            song.setAlbum(songAlbum);

            if (artists[i].addSong(song))
            {
                cout << "Song added successfully!" << endl;
                cout << artists[i].getSongCount << "/" << SONGS_SIZE << " songs have been added" << endl;
                return;
            }
            else
            {
                cout << "Song could not be added, array is full" << endl;
                return;
            }
        }
    }

    cout << "Artist was not found" << endl;
}

void modifySong(Artist* artists)
{
    int artistId;

    cout << "Please give artist id: ";
    cin >> artistId;

    for (int i = 0; i < ARTISTS_SIZE; i++)
    {
        if (artistId == artists[i].getId())
        {
            int songId;

            cout << "Please give song id: ";
            cin >> songId;

            Song* songs = artists[i].getSongs();

            for (int j = 0; j < SONGS_SIZE; j++)
            {
                if (songId == songs[j].getId())
                {
                    Song song;
                    string songName, songAlbum;

                    cout << "Please give new song name: ";
                    getline(cin, songName);
                    cout << "Please give new song album: ";
                    getline(cin, songAlbum);

                    song.setId(songId);
                    song.setName(songName);
                    song.setAlbum(songAlbum);

                    if (artists[i].modifySong(songId, song))
                    {
                        cout << "Song modified succesfully!" << endl;
                        return;
                    }
                }
            }
            cout << "Song not found." << endl;
            return;
        }
    }

    cout << "Artist not found" << endl;
}

void displaySongArtistId(Artist* artists)
{
    int id;

    cout << "Please give artist id: ";
    cin >> id;

    for (int i = 0; i < ARTISTS_SIZE; i++)
    {
        if (id == artists[i].getId())
        {
            Song* songs = artists[i].getSongs();

            for (int j = 0; j < SONGS_SIZE; j++)
                songs[j].toString();

            return;
        }
    }

    cout << "Artist not found" << endl;
}

void displaySongArtistAlbum(Artist* artists)
{
    int id;

    cout << "Please give artist id: ";
    cin >> id;

    for (int i = 0; i < ARTISTS_SIZE; i++)
    {
        if (id == artists[i].getId())
        {
            bool songFound = false;
            string album;
            Song* songs = artists[i].getSongs();

            cout << "Please give artist album: ";
            getline(cin, album);

            for (int j = 0; j < SONGS_SIZE; j++)
            {
                if (album.compare(songs[i].getAlbum()))
                {
                    songs[i].toString();
                    songFound = true;
                }
            }

            if (!songFound)
                cout << "No songs matched given album." << endl;

            return;
        }
    }

    cout << "Artist was not found." << endl;
}

void displayArtistsCompany(Artist* artists)
{
    string company;
    bool artistFound = false;
    
    cout << "Please give company name: ";
    getline(cin, company);

    for (int i = 0; i < ARTISTS_SIZE; i++)
    {
        if (company == artists[i].getCompany())
        {
            artists[i].toString();
            artistFound = true;
        }
    }

    if (!artistFound)
        cout << "No artist matched the company" << endl;
}

void executeChoice(Artist* artists, char choice, int& artistCount)
{
    switch (choice)
    {
        case ADD_NEW_ARTIST:
            addArtist(artists, artistCount);
        case ADD_NEW_SONG:
            addSongToArtist(artists);
        case MODIFY_SONG:
            modifySong(artists);
        case DISPLAY_SONGS_ARTIST_ID:
            displaySongArtistId(artists);
        case DISPLAY_SONGS_ARTIST_ALBUM:
            displaySongArtistAlbum(artists);
        case DISPLAY_ARTISTS_COMPANY:
        {

        }
        case DISPLAY_INFO_ARTIST_NAME:
        {

        }
        case DISPLAY_INFO_SONG_ID:
        {

        }
        case DISPLAY_NUMBER_SONGS_ARTIST_NAME:
        {

        }
        default:
            break;
    }
}