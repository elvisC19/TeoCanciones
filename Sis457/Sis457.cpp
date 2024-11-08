// Sis457.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "song.h"
#include <list>
#include "trackSong.h"
#include "tracker.h"


void displaySongComparison(const song& s1, const song& s2) {
    if (s1 == s2) {
        std::cout << "Las canciones son iguales " << std::endl;
    }
    else {
        std::cout << "Las canciones no son iguales. " << std::endl;
    }
    if (s1 < s2) {
        std::cout << s1.getNombre() << " tiene menos duración que " << s2.getNombre() << std::endl;
    }
    else {
        std::cout << s2.getNombre() << " tiene menos duración que " << s1.getNombre() << std::endl;
    }
}


void displayTrackerInfo(tracker& t) {
    float numPlayed = t.getNumberSongPlayed(100);
    std::cout << "Número de veces que se ha reproducido la canción al 100%: " << numPlayed << std::endl ;

    float bestRating = t.getBestRatingPercent();
    std::cout << "La mejor calificación porcentual de la canción es: " << bestRating << std::endl ;

    std::cout << "Historial de calificaciones en estrellas:"<<std::endl ;
    t.printStars();
    std::cout << "Historial de reproducciones con calificación 5 : "<<std::endl ;
    t.printHistoricalwithRate(5);
    std::cout << "Barras de duración de cada reproducción: " <<std ::endl ;
    t.printBarPercent();

    t.ClearHistorical();
    std::cout << "Historial después de limpiar: "<<std::endl ;
    t.printStars();
}


int main()
{

    song s1("ALAL", 3, 15);
    song s2("Aleeee", 4, 15);
    song s3("Locc", 2, 10);
    song s4("KOll", 3, 30);
    song s5("Lol", 1, 30);

 
    std::cout << "Comparación de canciones:" <<std::endl;
    displaySongComparison(s1, s2);
    std::cout << std::endl;
    displaySongComparison(s3, s4);
    std::cout << std::endl;


    tracker t1;
    t1.SetSong(s1);
    t1.addHistorical(trackSong(1, 30, 5));
    t1.addHistorical(trackSong(2, 0, 4));
    t1.addHistorical(trackSong(3, 15, 3));
    t1.addHistorical(trackSong(3, 30, 5));

    // Mostrar información del tracker
    std::cout << "Informacion del tracker:" <<std::endl;
    displayTrackerInfo(t1);
    std::cout << std::endl;

    //01/11/24
   //crear una lista de trakers , determina el traker que tiene mas historias y el que tiene menos historias


    tracker tracker1;
    tracker tracker2;
    tracker tracker3;

   
    tracker1.addHistorical(trackSong(1, 30, 5));
    tracker1.addHistorical(trackSong(2, 15, 4));

    tracker2.addHistorical(trackSong(1, 45, 3));

    tracker3.addHistorical(trackSong(2, 0, 4));
    tracker3.addHistorical(trackSong(1, 30, 5));
    tracker3.addHistorical(trackSong(1, 15, 4));

    std::list<tracker> trackers = { tracker1, tracker2, tracker3 };


    // Variables para guardar los `tracker` con más y menos historias
    auto maxTracker = trackers.begin();
    auto minTracker = trackers.begin();

    for (auto it = trackers.begin(); it != trackers.end(); ++it) {
        if (it->getHistoricalTrackSize() > maxTracker->getHistoricalTrackSize()) {
            maxTracker = it;
        }
        if (it->getHistoricalTrackSize() < minTracker->getHistoricalTrackSize()) {
            minTracker = it;
        }
    }

  
    std::cout << "Tracker con mas historias tiene " << maxTracker->getHistoricalTrackSize() << " historias." << std::endl;
    std::cout << "Tracker con menos historias tiene " << minTracker->getHistoricalTrackSize() << " historias." << std::endl;

	return 0;

}

