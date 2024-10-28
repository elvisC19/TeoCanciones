// Sis457.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "song.h"
#include "trackSong.h"
#include "tracker.h"

//vectores y listas usar para este ejercicio 

int main()
{

    // Crear algunas canciones
    song s1("Cancion1", 3, 30); // 3 minutos y 30 segundos
    song s2("Cancion2", 2, 45); // 2 minutos y 45 segundos
    song s3("Cancion3", 4, 15); // 4 minutos y 15 segundos

    // Crear un rastreador
    tracker t1;
    t1.SetSong(s1); // Establecer la canción actual para el rastreador

    // Agregar historial de reproducciones
    t1.addHistorical(trackSong(1, 30, 5));  // 1:30, calificación 5
    t1.addHistorical(trackSong(2, 0, 4));    // 2:00, calificación 4
    t1.addHistorical(trackSong(3, 15, 3));   // 3:15, calificación 3
    t1.addHistorical(trackSong(3, 30, 5));   // 3:30, calificación 5

    // Obtener el número de canciones reproducidas con una calificación específica
    float numPlayed = t1.getNumberSongPlayed(100); // Buscar reproducciones con al menos un 100%
    std::cout << "Numero de veces que se ha reproducido la cancion con al menos 100%: " << numPlayed << std::endl;

    // Obtener la mejor calificación
    float bestRating = t1.getBestRatingPercent();
    std::cout << "La mejor calificacion porcentual de la cancion es: " << bestRating << "%" << std::endl;

    // Imprimir estrellas para el historial
    std::cout << "Historial de calificaciones en estrellas:\n";
    t1.printStars();

    // Imprimir historial filtrado por calificación
    std::cout << "Historial de reproducciones con calificacion 5:\n";
    t1.printHistoricalwithRate(5);

    // Imprimir las barras de duración
    std::cout << "Barras de duracion de cada reproduccion:\n";
    t1.printBarPercent();

    // Limpiar el historial
    t1.ClearHistorical();
    std::cout << "Historial despues de limpiar:\n";
    t1.printStars(); 
    return 0;
}

