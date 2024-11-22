// Sis457.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "song.h"
#include <list>
#include "trackSong.h"
#include "tracker.h"

using namespace std;

void displaySongComparison(const song& s1, const song& s2) {
    if (s1 == s2) {
        cout << "Las canciones son iguales " << endl;
    }
    else {
        cout << "Las canciones no son iguales. " << endl;
    }
    if (s1 < s2) {
       cout << s1.getNombre() << " tiene menos duracion que " << s2.getNombre() <<endl;
    }
    else {
        cout << s2.getNombre() << " tiene menos duracion que " << s1.getNombre() << endl;
    }
}


void displayTrackerInfo(tracker& t) {
    float numPlayed = t.getNumberSongPlayed(100);
    cout << "Numero de veces que se ha reproducido la cancion al 100%: " << numPlayed << endl ;

    float bestRating = t.getBestRatingPercent();
    cout << "La mejor calificacion porcentual de la cancion es: " << bestRating << endl ;

    cout << "Historial de calificaciones en estrellas:"<<endl ;
    t.printStars();
    cout << "Historial de reproducciones con calificacion 5 : "<<endl ;
    t.printHistoricalwithRate(5);
    cout << "Barras de duracion de cada reproduccion: " <<endl ;
    t.printBarPercent();

    t.ClearHistorical();
    cout << "Historial despues de limpiar: "<<endl ;
    t.printStars();
}


int main()
{

    song s1("Canc1", 3, 15);
    song s2("Can2", 4, 15);
    song s3("Can3", 2, 10);
    song s4("Can4", 3, 30);
    song s5("Can5", 1, 30);

 
    cout << "Comparacion de canciones:" <<std::endl;
    displaySongComparison(s1, s2);
    cout << endl;
    displaySongComparison(s3, s4);
    cout << endl;


    tracker t1;
    t1.SetSong(s1);
    t1.addHistorical(trackSong(1, 30, 5));
    t1.addHistorical(trackSong(2, 0, 4));
    t1.addHistorical(trackSong(3, 15, 3));
    t1.addHistorical(trackSong(3, 30, 5));

    // Mostrar información del tracker
    cout << "Informacion del tracker:" <<endl;
    displayTrackerInfo(t1);
    cout << endl;

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

  
    cout << "Tracker con mas historias tiene " << maxTracker->getHistoricalTrackSize() << " historias." << endl;
    cout << "Tracker con menos historias tiene " << minTracker->getHistoricalTrackSize() << " historias." << endl;

	return 0;

}

