// Playlist.cpp : Defines the entry point for the console application.
//memory freed at lines: 166, 229, 267

//#include "stdafx.h"
#include "Song.h"
#include "Playlist.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;

void EnterSelection();
void DisplayMenu();

bool quit = false;
string latestStringInput;
vector<Song*> songs;
vector<Playlist*> playlists;
int playlistIndex = 0;
int songIndex = 0;

void GetLineNotWS(string& inpString) {

	getline(cin, inpString);
	if (inpString.find_first_not_of(" \t") == std::string::npos) {
		getline(cin, inpString);
	}
}

void EnterSelection() {

	cout << "Enter your selection now: ";
	GetLineNotWS(latestStringInput);
	cout << endl;

	if (latestStringInput == "quit") {
		quit = true;
	}
	else if (latestStringInput == "add") {

		cout << "Read in Song names and first lines (type \"STOP\" when done):" << endl;
		cout << "Song Name: ";
		GetLineNotWS(latestStringInput);

		while (latestStringInput != "STOP") {

			songs.resize(songs.size() + 1);
			songs.at(songs.size() - 1) = new Song();

			(*(songs.at(songs.size() - 1))).SetName(latestStringInput);

			cout << "Song's first line: ";
			GetLineNotWS(latestStringInput);

			(*(songs.at(songs.size() - 1))).SetFirstLine(latestStringInput);

			cout << "Song Name: ";
			GetLineNotWS(latestStringInput);
		}

		cout << endl;
	}
	else if (latestStringInput == "list") {

		for (Song* song : songs) {
			
			cout << (*song).GetName() << ": \"" << (*song).GetFirstLine() << "\", ";
			cout << (*song).GetPlayCount() << " play(s)." << endl;
		}
		cout << endl;
	}
	else if (latestStringInput == "addp") {

		cout << "Playlist name: ";
		GetLineNotWS(latestStringInput);

		playlists.resize(playlists.size() + 1);
		playlists.at(playlists.size() - 1) = new Playlist(latestStringInput);

		cout << endl;
	}
	else if (latestStringInput == "addsp") {

		playlistIndex = 0;

		for (Playlist* playlist : playlists) {

			cout << playlistIndex << ": " << (*playlist).GetName() << endl;
			playlistIndex++;
		}

		cout << "Pick a playlist index number: ";
		cin >> playlistIndex;
		cout << endl;

		songIndex = 0;

		for (Song* song : songs) {

			cout << songIndex << ": " << (*song).GetName() << endl;
			songIndex++;
		}

		cout << "Pick a song index number: ";
		cin >> songIndex;
		cout << endl;

		(*playlists.at(playlistIndex)).AddSong(songs.at(songIndex));

		cout << endl;
	}
	else if (latestStringInput == "listp") {

		playlistIndex = 0;

		for (Playlist* playlist : playlists) {

			cout << playlistIndex << ": " << (*playlist).GetName() << endl;
			playlistIndex++;
		}

		cout << endl;
	}
	else if (latestStringInput == "play") {

		playlistIndex = 0;

		for (Playlist* playlist : playlists) {

			cout << playlistIndex << ": " << (*playlist).GetName() << endl;
			playlistIndex++;
		}

		cout << "Pick a playlist index number: ";
		cin >> playlistIndex;
		cout << endl << "Playing first lines of playlist: " << (*playlists.at(playlistIndex)).GetName();
		cout << endl;

		for (Song* song : (*playlists.at(playlistIndex)).GetSongs()) {

			cout << (*song).GetFirstLine() << endl;
			(*song).IncrimentPlays();
		}

		cout << endl;
	}
	else if (latestStringInput == "delp") {

		playlistIndex = 0;

		for (Playlist* playlist : playlists) {

			cout << playlistIndex << ": " << (*playlist).GetName() << endl;
			playlistIndex++;
		}

		cout << "Pick a playlist index number to delete: ";
		cin >> playlistIndex;

		//Free playlist memory
		delete (playlists.at(playlistIndex));

		playlists.erase(playlists.begin() + (playlistIndex));

		cout << endl;

		cout << endl;
	}
	else if (latestStringInput == "delsp") {

		playlistIndex = 0;

		for (Playlist* playlist : playlists) {

			cout << playlistIndex << ": " << (*playlist).GetName() << endl;
			playlistIndex++;
		}

		cout << "Pick a playlist index number: ";
		cin >> playlistIndex;

		songIndex = 0;

		for (Song* song : (*playlists.at(playlistIndex)).GetSongs()) {

			cout << songIndex << ": " << (*song).GetName() << endl;
			songIndex++;
		}

		cout << "Pick a song index number to delete: ";
		cin >> songIndex;
		cout << endl;

		(*playlists.at(playlistIndex)).RemoveSong(songIndex);

		cout << endl;
	}
	else if (latestStringInput == "delsl") {

		songIndex = 0;

		for (Song* song : songs) {

			cout << songIndex << ": " << (*song).GetName() << endl;
			songIndex++;
		}

		cout << "Pick a song index number: ";
		cin >> songIndex;
		cout << endl;

		//Delete song from any playlists
		for (Playlist* playlist : playlists) {

			int playListIndexOfSong = ((*playlist).IndexOfSong(songs.at(songIndex)));

			if (playListIndexOfSong != -1) {

				(*playlist).RemoveSong(playListIndexOfSong);
			}
		}

		//Free song memory
		delete (songs.at(songIndex));

		songs.erase(songs.begin() + (songIndex));

		cout << endl;
	}
	else {
		DisplayMenu();
	}
}

void DisplayMenu() {

	cout << "add      Adds a list of songs to the library" << endl;
	cout << "list     Lists all the songs in the library" << endl;
	cout << "addp     Adds a new playlist" << endl;
	cout << "addsp    Adds a song to a playlist" << endl;
	cout << "listp    Lists all the playlists" << endl;
	cout << "play     Plays a playlist" << endl;
	cout << "delp     Deletes a playlist" << endl;
	cout << "delsp    Deletes a song from a playlist" << endl;
	cout << "delsl    Deletes a song from the library (and all playlists)" << endl;
	cout << "options  Prints this options menu" << endl;
	cout << "quit     Quits the program" << endl << endl;
}

int main()
{

	cout << "Welcome to the Firstline Player! Enter options to see menu options." << endl << endl;

	while (!quit) {

		EnterSelection();
	}

	//free memory of all songs at quit
	for (Song* song : songs) {
		delete song;
	}

	cout << "Goodbye!";
    return 0;
}

