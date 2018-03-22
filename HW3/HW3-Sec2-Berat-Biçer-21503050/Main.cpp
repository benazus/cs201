#include <iostream>
#include <string>
#include "JukeBox.h"
using namespace std;

int main() {
	JukeBox jb;

	jb.addTrack("Scarecrow", 2008);
	jb.addTrack("Parasite", 2011);
	jb.addTrack("The Vengeful One", 2015);
	jb.addTrack("Morphogenesis", 2008);
	jb.addTrack("Now That We're Dead", 2016);
	jb.addTrack("The Last Stand", 2016);
	jb.addTrack("A Voice in the Dark", 2010);
	cout << endl;


	jb.addMusician("Scarecrow", "Kai", "Hansen", "1");
	jb.addMusician("Scarecrow", "Timo", "Tolkki", "2");
	jb.addMusician("Scarecrow", "Sharon Den", "Adel", "3");
	jb.addMusician("Scarecrow", "Jens", "Ludwig", "4");
	jb.addMusician("Scarecrow", "Henjo", "Richter", "5");
	jb.addMusician("Scarecrow", "Alex", "Holzwarth", "6");
	jb.addMusician("A Voice in the Dark", "Blind", "Guardian", "1");
	cout << endl;


	jb.showAllTracks();
	cout << endl;


	jb.showTrack("Scarecrow");
	cout << endl;
	jb.showTrack("Parasite");
	cout << endl;
	jb.showTrack("The Vengeful One");
	cout << endl;
	jb.showTrack("Morphogenesis");
	cout << endl;
	jb.showTrack("Now That We're Dead");
	cout << endl;
	jb.showTrack("The Last Stand");
	cout << endl;
	jb.showTrack("A Voice in the Dark");
	cout << endl;


	jb.showMusicianRoles("kjjaldkkjasl", "klşdkjjasdalnsjdjkhjrkf");
	cout << endl;
	jb.showMusicianRoles("KAI", "HanSEn");
	cout << endl;
	jb.showMusicianRoles("BliNd", "Guardian");
	cout << endl;


	jb.removeMusician("Scarecrow", "Kai", "Hansen");
	jb.removeMusician("Scarecrow", "Henjo", "Richter");
	jb.removeMusician("Scarecrow", "Alex", "Holzwarth");
	jb.removeMusician("Scarecrow", "Jens", "Ludwig");
	jb.removeMusician("Scarecrow", "Timo", "Tolkki");
	jb.removeMusician("Scarecrow", "Sharon Den", "Adel");
	jb.removeMusician("A Voice in the Dark", "Blind", "Guardian");
	cout << endl;



	jb.removeTrack("Scarecrow");
	jb.removeTrack("The Last Stand");
	jb.removeTrack("Parasite");
	jb.removeTrack("Morphogenesis");
	jb.removeTrack("The Vengeful One");
	jb.removeTrack("Now That We're Dead");
	jb.removeTrack("A Voice in the Dark");
	cout << endl;


	int a;
	cin >> a;
	return 0;
}