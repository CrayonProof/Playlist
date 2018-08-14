#include "stdafx.h"
#include "Song.h"
#include "Playlist.h"
#include <vector>
#include <string>
using namespace std;

string playlistName;
vector<Song*> playlistSongs;

Playlist::Playlist() {
	playlistName = "none";
}

Playlist::Playlist(string playlistName) {
	this->playlistName = playlistName;
}

Playlist::~Playlist() {

}

void Playlist::SetName(string playlistName) {
	this->playlistName = playlistName;
}

string Playlist::GetName() {
	return playlistName;
}

vector<Song*> Playlist::GetSongs() {
	return playlistSongs;
}

void Playlist::AddSong(Song* song) {
	playlistSongs.resize(playlistSongs.size() + 1);
	playlistSongs.at(playlistSongs.size() - 1) = song;
}

void Playlist::RemoveSong(int deleteSongIndex) {
	playlistSongs.erase(playlistSongs.begin() + (deleteSongIndex));
}

//Returns the index at which the song is stored in the playlist
//if the playlist does not contain the song, returns -1
int Playlist::IndexOfSong(Song* song) {

	int songIndex = 0;

	for (Song* songToCheck : playlistSongs) {
		if (songToCheck == song) {
			return songIndex;
		}

		songIndex++;
	}
	return -1;
}