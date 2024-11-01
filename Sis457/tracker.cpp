#include "tracker.h"

void tracker::Add(trackSong ts)
{
	historicalTrack.push_back(ts);
}

float tracker::getBestRatingPercent() const {
	float best = 0.0;
	for (const auto& track : historicalTrack) {
		float rating = track.getRatingPercent(trackerSong);
		if (rating > best) {
			best = rating;
		}
	}
	return best;
}

float tracker::getNumberSongPlayed(float porcent)
{
	float count = 0;
	for (int i = 0; i < historicalTrack.size(); i++)
	{
		if (historicalTrack[i].getRatingPercent(trackerSong) == porcent)
		{
			count++;
		}
	}
	return count;
}

void tracker::SetSong(const song& s)
{
	trackerSong = s;
}

void tracker::addHistorical(const trackSong& ts)
{
	historicalTrack.push_back(ts);
}

void tracker::ClearHistorical()
{
	historicalTrack.clear();
}

void tracker::printStars()
{
	for (const auto& track : historicalTrack) {

		std::cout << "Calificacion: " << track.getRating() << " ->";

		for (int i = 0; i < track.getRating(); i++)
		{
			std::cout << "*";
		}

		std::cout << std::endl;
	}
}

void tracker::printHistoricalwithRate(int rate) {
	for (const auto& track : historicalTrack) {

		if (track.getRating() == rate)
		{
			std::cout << "Calificacion: " << track.getRating() << " ->";

			for (int i = 0; i < track.getRating(); i++)
			{
				std::cout << "*";
			}

			std::cout << std::endl;
		}
	}
}


void tracker::printBarPercent()
{
	for (const auto& track : historicalTrack) {
		int totalDuration = trackerSong.ToSec();
		int trackDuration = track.playmin * 60 + track.playseg; 

		// Calcular el porcentaje de reproducci�n
		float percentage = static_cast<float>(trackDuration) / totalDuration * 100;

		
		int numBars = static_cast<int>(percentage / 10); 
		numBars = std::min(numBars, 10); 

		// Imprimir las barras
		std::cout << "Reproduccion: ";
		for (int i = 0; i < numBars; ++i) {
			std::cout << "|";
		}

		std::cout << std::endl;
		//std::cout << " (" << percentage << "%)\n"; 
	}
}
