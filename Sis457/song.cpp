#include "song.h"

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

bool song :: HastheSameTime(song s)
{
	return (ToSec() == s.ToSec());
}

