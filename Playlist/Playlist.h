#include <vector>
#include <string>
using namespace std;

#pragma once
class Playlist
{
public:
	Playlist();
	Playlist(string name);
	~Playlist();

	void SetName(string playlistName);
	string GetName();
	vector<Song*> GetSongs();
	void AddSong(Song* song);
	void RemoveSong(int deleteSongIndex);
	int IndexOfSong(Song* song);
private:
	string playlistName;
	vector<Song*> playlistSongs;
};

