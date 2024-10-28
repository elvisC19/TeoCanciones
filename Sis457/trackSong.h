#pragma once
#include <iostream>
#include <string>
#include "song.h"
class trackSong
{
public : 
	int playmin;
	int playseg;
	int raeting;

	//agregar una fucion 
	float getRatingPercent(const song& s) const;
	trackSong ();
	trackSong(int pm, int ps, int r);

	void setPlayMin(int pm);
	int getPlayMin() const;

	void setPlaySeg(int ps);
	int getPlaySeg() const;

	int getRating() const;
};

