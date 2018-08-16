//#include "stdafx.h"
#include "Song.h"
#include <string>
using namespace std;

string songName;
string songFirstLine;
int playCount = 0;

Song::Song() {
	songName = "none";
	songFirstLine = "none";
	playCount = 0;
}

Song::Song(string songName, string songFirstLine) {
	this->songName = songName;
	this->songFirstLine = songFirstLine;
	playCount = 0;
}

Song::~Song() {
}

void Song::SetName(string songName) {
	this->songName = songName;
}
void Song::SetFirstLine(string songFirstLine) {
	this->songFirstLine = songFirstLine;
}

string Song::GetName() {
	return songName;
}

string Song::GetFirstLine() {
	return songFirstLine;
}

int Song::GetPlayCount() {
	return playCount;
}

void Song::IncrimentPlays() {
	playCount += 1;
}