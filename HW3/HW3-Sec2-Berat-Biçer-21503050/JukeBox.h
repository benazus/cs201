#pragma once
#include <iostream>
#include <string>
using namespace std;

class JukeBox {
public:
	JukeBox();
	~JukeBox();
	void addTrack(string trackTitle, int releaseYear);
	void removeTrack(string trackTitle);
	void addMusician(string trackTitle, string musicianFirstName, string musicianLastName, string musicianRole);
	void removeMusician(string trackTitle, string musicianFirstName, string musicianLastName);
	void showAllTracks() const;
	void showTrack(string trackTitle) const;
	void showMusicianRoles(string musicianFirstName, string musicianLastName) const;
private:
	struct Musician;
	struct Track;

	struct Musician {
		string firstName;
		string lastName;
		string role;
		Musician* next; // Linked list of musicians
		//Track* nextTrack;
	};

	struct Track {
		string title;
		int releaseDate;
		Musician* musician; // Linked list of musicians for those who have a have a part in this song
		Track* next; // Linked list of tracks
	};
	
	Track* headTrack; // Inside JukeBox, you need to keep the song entries whereas inside each song, you need to keep musician entries
	//Musician* headMusician;
	void deleteTrack(Track* track);
};