/*
 * Artist.h
 * 
 * David Alejandro Martinez Tristan
 * 28/2/2019
 */

#ifndef ARTIST_H
#define ARTIST_H
#define SONGS_ARRAY_SIZE 50
#include <iostream>
#include "Song.h"

using namespace std;

class Artist
{
	private:
		int id;
		int songCount;
		string name, company;
		Song songs[50];
	public:
		Artist();
		Artist(int, string, string);
		int getId();
		int getSongCount();
		string getName();
		string getCompany();
		Song* getSongs();
		void setId(int);
		void setName(string);
		void setCompany(string);
		void toString();
		bool addSong(Song);
		bool modifySong(int, Song);
		void removeAllSongs();
};

Artist::Artist()
{
	id = -1;
	name = "N/A";
	company = "N/A";
	songCount = 0;
}

Artist::Artist(int id, string name, string company)
{
	this->id = id;
	this->name = name;
	this->company = company;
	songCount = 0;
}

int Artist::getId()
{
	return id;
}

int Artist::getSongCount()
{
	return songCount;
}

string Artist::getName()
{
	return name;
}

string Artist::getCompany()
{
	return company;
}

Song* Artist::getSongs()
{
	return songs;
}

void Artist::setId(int id)
{
	this->id = id;
}

void Artist::setName(string name)
{
	this->name = name;
}

void Artist::setCompany(string company)
{
	this->company = company;
}

void Artist::toString()
{
	cout << id << endl;
	cout << songCount << endl;
	cout << name << endl;
	cout << company << endl;
	cout << songs << endl;

	for (int i = 0; i < SONGS_ARRAY_SIZE; i++)
		songs[i].toString();
}

bool Artist::addSong(Song song)
{
	if (songCount == SONGS_ARRAY_SIZE)
		return false;
	
	songs[songCount] = song;
	songCount++;
	return true;
}

bool Artist::modifySong(int id, Song song)
{
	int songNum = 0;

	while (id != songs[songNum].getId())
	{
		if (songNum == SONGS_ARRAY_SIZE)
			return false;

		songNum++;
	}

	songs[songNum] = song;
	return true;
}

void Artist::removeAllSongs()
{
	for (int i = 0; i < SONGS_ARRAY_SIZE; i++)
		songs[i].setDefaultValue();

	songCount = 0;
}

#endif