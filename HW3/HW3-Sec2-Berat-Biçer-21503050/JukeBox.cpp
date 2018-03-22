#include <iostream>
#include <string>
#include <algorithm>
#include "JukeBox.h"
using namespace std;

JukeBox::JukeBox() {
	headTrack = NULL;
	//headMusician = nullptr;
}

JukeBox::~JukeBox() {
	if (headTrack != NULL) {
		Track* tmp = headTrack;
		while (tmp != NULL) {
			Track* tmp2 = tmp->next;
			this->deleteTrack(tmp);
			tmp = tmp2;
		}
	}
	
	/*if (headMusician != nullptr) {
		Musician* tmp3 = headMusician;
		while (tmp3 != nullptr) {
			Musician* tmp4 = tmp3->next;
			this->deleteMusician(tmp3);
			tmp3 = tmp4;
		}
	}*/
}

void JukeBox::addTrack(string trackTitle, int releaseYear) {
	// Check if the song already exists
	Track* q = headTrack;
	std::transform(trackTitle.begin(), trackTitle.end(), trackTitle.begin(), ::toupper);
	while (q != NULL) { // That is, the last node in the list
		if ((q->title).compare(trackTitle) == 0) {
			cout << "Warning: A track with the same name already exists in JukeBox" << endl;
			return;
		}
		else
			q = q->next;
	}

	cout << "Creating a new track entry:" << endl;

	// Insert the new song within the list
	if (headTrack == NULL) { // Empty list
		headTrack = new Track;
		headTrack->title = trackTitle;
		std::transform((headTrack->title).begin(), (headTrack->title).end(), (headTrack->title).begin(), ::toupper);
		headTrack->releaseDate = releaseYear;
		headTrack->musician = NULL;
		headTrack->next = NULL;
	}
	else { // Non-empty list
		Track* tmp = headTrack;
		while (tmp->next != NULL) // Find the last track node in the list
			tmp = tmp->next;

		// Create new track entry
		Track* tmp2 = new Track;
		tmp2->title = trackTitle;
		std::transform((tmp2->title).begin(), (tmp2->title).end(), (tmp2->title).begin(), ::toupper);
		tmp2->releaseDate = releaseYear;
		tmp2->musician = NULL;

		// Link the new node to the list
		tmp->next = tmp2;
		tmp2->next = NULL;
	}

	cout << "Warning: A new track entry is created." << endl;

}

void JukeBox::removeTrack(string trackTitle) {
	if (headTrack == NULL) { // Empty list
		cout << "Warning: Empty JukeBox." << endl;
		return;
	}
	else { // Non-empty list
		Track* tmp = headTrack;
		std::transform(trackTitle.begin(), trackTitle.end(), trackTitle.begin(), ::toupper);
		while (tmp != NULL && (tmp->title).compare(trackTitle) != 0)// Find node to be deleted.
			tmp = tmp->next;

		if (tmp == NULL) { // If no track with given title found, tmp will be null
			cout << "Warning: No track with specified name exists in JukeBox." << endl;
			return;
		}
		else if ((tmp->title).compare(trackTitle) == 0) {
			this->deleteTrack(tmp);
			cout << "Warning: Track deleted." << endl;
		}
		else
			return;
	}
}

void JukeBox::deleteTrack(Track* track) {
	std::transform((track->title).begin(), (track->title).end(), (track->title).begin(), ::toupper);
	if ((track->title).compare(headTrack->title) == 0) { // headTrack
		if (track->musician != NULL) {  // If track's Musician list is not empty
			Musician* tmp = track->musician;
			while (tmp != NULL) {
				Musician* tmp2 = tmp->next;
				delete tmp;
				tmp = tmp2;
			}
		}

		Track* tmp3 = track->next;
		delete track;
		headTrack = tmp3;

	}
	else { // Non-head track
		// Find track node and it's previous
		Track* tmp = headTrack;
		Track* prev = NULL;
		bool ctrl = false;
		while (tmp != NULL && ctrl != true) {
			if ((tmp->title).compare(track->title) != 0) { // not the node we need
				prev = tmp;
				tmp = tmp->next;
			}
			else
				ctrl = true;
		}

		if (ctrl == true) { // Node found
			if (track->musician != NULL) {  // If track's Musician list is not empty
				Musician* tmp = track->musician;
				while (tmp != NULL) {
					Musician* tmp2 = tmp->next;
					delete tmp;
					tmp = tmp2;
				}
			}
		
			prev->next = tmp->next;
			tmp->next = NULL;
			delete tmp;
		}
		else if (tmp == NULL) {
			cout << "Warning: nullptr." << endl;
			return;
		}
		else
			return;
	}
	
}

void JukeBox::addMusician(string trackTitle, string musicianFirstName, string musicianLastName, string musicianRole) {
	// 1 - Locate the track or check if the track exists
	// 2 - Check if the musician is among the musician list. If he is, skip. Else, add him into the musician list.

	// 1 - Locate the track
	Track* tmp = headTrack;
	bool ctrl = false;

	std::transform(trackTitle.begin(), trackTitle.end(), trackTitle.begin(), ::toupper);
	std::transform(musicianFirstName.begin(), musicianFirstName.end(), musicianFirstName.begin(), ::toupper);
	std::transform(musicianLastName.begin(), musicianLastName.end(), musicianLastName.begin(), ::toupper);
	std::transform(musicianRole.begin(), musicianRole.end(), musicianRole.begin(), ::toupper);

	while (tmp != NULL && ctrl != true) {
		if ((tmp->title).compare(trackTitle) == 0)
			ctrl = true;
		else
			tmp = tmp->next;
	}

	if (tmp == NULL) { // No track exists.
		cout << "Warning: Track not found." << endl;
		return;
	}
	else if (ctrl == true) { // Track found.

		// 2 - Check if the musician is in musicians list.
		Musician* tmp2 = tmp->musician;
		if (tmp2 == NULL) { // First musician to be added in the list.
			Musician* musician = new Musician;
			musician->firstName = musicianFirstName;
			musician->lastName = musicianLastName;
			musician->role = musicianRole;
			tmp->musician = musician;
			musician->next = NULL;

			cout << "Warning: Musician added to the head." << endl;
			return;
		}
		else { // Not the first musician to be added to the list.
			Musician* tmp3 = tmp->musician;
			Musician* prev = NULL;
			bool ctrl2 = false;
			while (tmp3 != NULL && ctrl2 != true) { // Locate the end of the musician list
				std::transform((tmp3->firstName).begin(), (tmp3->firstName).end(), (tmp3->firstName).begin(), ::toupper);
				std::transform((tmp3->lastName).begin(), (tmp3->lastName).end(), (tmp3->lastName).begin(), ::toupper);
				std::transform((tmp3->role).begin(), (tmp3->role).end(), (tmp3->role).begin(), ::toupper);
				if ((tmp3->firstName).compare(musicianFirstName) == 0 && (tmp3->lastName).compare(musicianLastName) == 0)
					ctrl2 = true;
				else {
					prev = tmp3;
					tmp3 = tmp3->next;
				}
			}

			if (ctrl2 != true) { // No musician found with given specifications.
				Musician* tmp4 = new Musician;
				tmp4->firstName = musicianFirstName;
				tmp4->lastName = musicianLastName;
				tmp4->role = musicianRole;
				std::transform((tmp4->firstName).begin(), (tmp4->firstName).end(), (tmp4->firstName).begin(), ::toupper);
				std::transform((tmp4->lastName).begin(), (tmp4->lastName).end(), (tmp4->lastName).begin(), ::toupper);
				std::transform((tmp4->role).begin(), (tmp4->role).end(), (tmp4->role).begin(), ::toupper);
				prev->next = tmp4;
				tmp4->next = tmp3;

				cout << "Warning: Musician added to the middle." << endl;
				return;
			}
			else { // Musician found.
				cout << "Warning: Musician already exists with given specifications." << endl;
				return;
			}
		}
	}
	else { // Safeguard.
		cout << "Warning: Unexpected track value." << endl;
		return;
	}
}

void JukeBox::removeMusician(string trackTitle, string musicianFirstName, string musicianLastName) {
	// Locate the track.
	Track* tmp = headTrack;
	bool ctrl = false;

	std::transform(trackTitle.begin(), trackTitle.end(), trackTitle.begin(), ::toupper);
	std::transform(musicianFirstName.begin(), musicianFirstName.end(), musicianFirstName.begin(), ::toupper);
	std::transform(musicianLastName.begin(), musicianLastName.end(), musicianLastName.begin(), ::toupper);

	while (tmp != NULL && ctrl != true) {
		if ((tmp->title).compare(trackTitle) == 0) {
			ctrl = true;
		}
		else
			tmp = tmp->next;
	}

	if (tmp == NULL) { // No track exists.
		cout << "Warning: Track not found." << endl;
		return;
	}
	else if (ctrl == true) { // Track found.
		if (tmp->musician == NULL) { // Empty musician list
			cout << "Warning: Empty musician list" << endl;
			return;
		}
		else { // not empty musician list
			if ((tmp->musician->firstName).compare(musicianFirstName) == 0 && (tmp->musician->lastName).compare(musicianLastName) == 0) { // First node
				Musician* temp = tmp->musician->next;
				delete tmp->musician;
				tmp->musician = temp;
				cout << "Warning: Musician deleted from head." << endl;
			}
			else { // Middle node
				
				Musician* temp = tmp->musician;
				Musician* prev = NULL;
				bool ctrl2 = false;
				while (temp != NULL && ctrl2 != true) {
					if ((temp->firstName).compare(musicianFirstName) == 0 && (temp->lastName).compare(musicianLastName) == 0)
						ctrl2 = true;
					else {
						prev = temp;
						temp = temp->next;
					}
				}
				if (temp == NULL) { // No musician with given specifications.
					cout << "Warning: No musician with given specifications found." << endl;
					return;
				}
				else if (ctrl2 == true) { // Musician found.
					prev->next = temp->next;
					delete temp;
					temp = NULL;
					cout << "Warning: Musician deleted from middle." << endl;
					return;
				}
				else { // Safeguard.
					cout << "Warning: Unexpected value of musician." << endl;
					return;
				}
			}
		}
	} // end of else if(ctrl == true)
	else {// Safeguard
		return;
		cout << "Warning: Unexpected track value." << endl;
	}
}

void JukeBox::showAllTracks() const {
	Track* tmp = headTrack;
	while (tmp != NULL) {
		cout << tmp->title << ", " << tmp->releaseDate << " " << endl;
		tmp = tmp->next;
	}
}

void JukeBox::showTrack(string trackTitle) const {
	Track* tmp = headTrack;
	std::transform(trackTitle.begin(), trackTitle.end(), trackTitle.begin(), ::toupper);
	bool ctrl = false;
	while (tmp != NULL && ctrl != true) {
		if ((tmp->title).compare(trackTitle) == 0)
			ctrl = true;
		else
			tmp = tmp->next;
	}

	if (tmp == NULL) { // Track doesn't exist.
		cout << "---none---" << endl;
		return;
	}
	else if (ctrl == true) { // Track found.
		cout << tmp->title << ", " << tmp->releaseDate << "." << endl;
		Musician* tmp2 = tmp->musician;
		while (tmp2 != NULL) {
			cout << tmp2->firstName << " " << tmp2->lastName << ", " << tmp2->role << endl;
			tmp2 = tmp2->next;
		}

		cout << "Warning: Track information showed." << endl;
	}
	else { // Safeguard.
		cout << "Warning: Unexpected value of Track." << endl;
		return;
	}
}

void JukeBox::showMusicianRoles(string musicianFirstName, string musicianLastName) const {
	// 1 - From first track until the last one,
	// 2 - Search a track's musician list
	// 3 - If the musician is in that track's musician list, print it out.
	// 4 - Else, keep traversing.

	std::transform(musicianFirstName.begin(), musicianFirstName.end(), musicianFirstName.begin(), ::toupper);
	std::transform(musicianLastName.begin(), musicianLastName.end(), musicianLastName.begin(), ::toupper);

	cout << musicianFirstName << " " << musicianLastName << endl;
	bool ctrl = false;

	Track* tmp = headTrack;
	while (tmp != NULL) { // 1.
		Musician* tmp2 = tmp->musician;
		while (tmp2 != NULL) { // 2.
			if ((tmp2->firstName).compare(musicianFirstName) == 0 && (tmp2->lastName).compare(musicianLastName) == 0) { // 3.
				cout << tmp2->role << ", " << tmp->title << ", " << tmp->releaseDate << endl;
				ctrl = true;
			}
			
			tmp2 = tmp2->next; // 4.
		}
		tmp = tmp->next;
	}

	if (ctrl == false)
		cout << "---none---" << endl;
}