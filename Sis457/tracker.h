#pragma once
#include "song.h"
#include <vector>
#include "trackSong.h"
class tracker
{
protected:
	song trackerSong;
	std ::vector <trackSong> historicalTrack;
public :

	void Add(trackSong ts);
	float getBestRatingPercent() const;//obtien la calificacion
	float getNumberSongPlayed(float porcent);//devuelve el numero de veces que se ha reproducido

	void SetSong(const song& s);

	void addHistorical(const trackSong& ts);

	void ClearHistorical();
	void printStars();
	void printHistoricalwithRate(int rate) ;
	void printBarPercent();

};

