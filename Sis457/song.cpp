#include "song.h"
#include <string>
#include <iostream>

song::song(std::string n, int m, int s)
{
	nombre = n;
	tminutos = m;
	tsegundos = s;
}

song::song()
{
	nombre = "cacion x";
	tminutos = 30;
	tsegundos = 3;
}

int song :: ToSec() const
{
	return (tminutos * 60 + tsegundos);
}	

bool song :: HastheSameTime( const song& s)const 
{
	return (ToSec() == s.ToSec());
}
//clase 01/11/24
bool operator==(const song& c1, const song& c2)
{
	return c1.nombre == c2.nombre && c1.HastheSameTime(c2);
	//c1.name == c2.name && c1.ToSec() == c2.ToSec();
}


bool operator<(const song& c1, const song& c2)
{
	return c1.tminutos < c2.tminutos;
}

std::string song::getNombre()const {

	return nombre;
}

void song::print()
{
	std::cout << "Nombre: " << nombre << std::endl;
	std::cout << "Duracion: " << tminutos << ":" << tsegundos << std::endl;
}