#include "trackSong.h"

float trackSong::getRatingPercent(const song& s) const {
	int totalDurationSec = s.ToSec();
	int trackDurationSec = playmin * 60 + playseg;
	return (totalDurationSec > 0) ? (trackDurationSec * 100.0 / totalDurationSec) : 0;
}

trackSong::trackSong()
{
	playmin = 0;
	playseg = 0;
	raeting = 0;
}

trackSong::trackSong(int pm, int ps, int r)
{
	playmin = pm;
	playseg = ps;
	raeting = r;
}

void trackSong::setPlayMin(int pm)
{
	if (pm >= 0)
	{
		playmin = pm;
	}
}

int trackSong::getPlayMin() const
{
	return playmin;
}

void trackSong::setPlaySeg(int ps)
{
	if (ps >= 0 && ps < 60)
	{
		playseg = ps;
	}
}

int trackSong::getPlaySeg() const
{
	return playseg;
}

int trackSong::getRating() const
{
	return raeting;
}