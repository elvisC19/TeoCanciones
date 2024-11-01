// Sis457.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "song.h"
#include "trackSong.h"
#include "tracker.h"



int main()
{

    // Crear algunas canciones
    song s1("Cancion1", 3, 30); 
    song s2("Cancion2", 2, 45); 
    song s3("Cancion3", 4, 15); 

    
    tracker t1;
    t1.SetSong(s1); // Establecer la canción actual para el rastreador

    // Agregar historial de reproducciones
    t1.addHistorical(trackSong(1, 30, 5));  
    t1.addHistorical(trackSong(2, 0, 4));    
    t1.addHistorical(trackSong(3, 15, 3));   
    t1.addHistorical(trackSong(3, 30, 5));   

  
    float numPlayed = t1.getNumberSongPlayed(100); 
    std::cout << "Numero de veces que se ha reproducido la cancion con al menos 100%: " << numPlayed << std::endl;
	std::cout << " " << std::endl;
    
    float bestRating = t1.getBestRatingPercent();
    std::cout << "La mejor calificacion porcentual de la cancion es: " << bestRating << "%" << std::endl;

	std::cout << " " << std::endl;  

    // Imprimir estrellas para el historial
    std::cout << "Historial de calificaciones en estrellas:\n";
    t1.printStars();
	std::cout << " " << std::endl;  
    // Imprimir historial filtrado por calificación
    std::cout << "Historial de reproducciones con calificacion 5:\n";
    t1.printHistoricalwithRate(5);
	std::cout << " " << std::endl;
    // Imprimir las barras de duración
    std::cout << "Barras de duracion de cada reproduccion:\n";
    t1.printBarPercent();

	std::cout << " " << std::endl;
    t1.ClearHistorical();
    std::cout << "Historial despues de limpiar:\n";
    t1.printStars(); 
    return 0;
}

