/*
 * Song.h
 * 
 * David Alejandro Martinez Tristan
 * 28/2/2019
 */

#ifndef SONG_H
#define SONG_H
#include <iostream>

using namespace std;

class Song
{
	private:
		int id;
		string album, name;
	public:
		Song();
		Song(int, string, string);
		int getId();
		string getAlbum();
		string getName();
		void setId(int);
		void setAlbum(string);
		void setName(string);
		void toString();
		void setDefaultValue();
};

Song::Song()
{
	id = -1;
	album = "N/A";
	name = "N/A";
}

Song::Song(int id, string album, string name)
{
	this->id = id;
	this->album = album;
	this->name = name;
}

int Song::getId()
{
	return id;
}

string Song::getAlbum()
{
	return album;
}

string Song::getName()
{
	return name;
}

void Song::setId(int id)
{
	this->id = id;
}

void Song::setAlbum(string album)
{
	this->album = album;
}

void Song::setName(string name)
{
	this->name = name;
}

void Song::toString()
{
	cout << id << " " << album << " " << name << endl;
}

void Song::setDefaultValue()
{
	id = -1;
	album = "N/A";
	name = "N/A";
}

#endif