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


	//implementar 01/11/2024
	//sobre escribir el operador de comparacion<,considerando considerando que se quieren comparar trakers
	//considera que un traker es menor que otro si la cancion que se esta rastreando es menor
	//conciderar el que menos historias tenga , cantidad de historias 

	bool operator < (const tracker& other) const;

	int getHistoricalTrackSize() const;

};

