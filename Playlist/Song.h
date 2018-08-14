#include <string>
using namespace std;

#pragma once
class Song
{
public:
	Song();
	Song(string songName, string songFirstLine);
	~Song();

	void SetName(string songName);
	void SetFirstLine(string songFirstLine);
	string GetName();
	string GetFirstLine();
	int GetPlayCount();
	void IncrimentPlays();
private:
	string songName;
	string songFirstLine;
	int playCount;
};

