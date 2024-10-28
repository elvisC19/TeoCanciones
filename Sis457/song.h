#pragma once
#include <iostream>
#include <string>
class song
{

private:
	int tminutos;
	int tsegundos;

public:

	std :: string nombre;

	song(std::string n, int m, int s);
	song();	
	int ToSec() const;
	bool HastheSameTime(song s);

	void setTiempominutos(int minutos)
	{
		if (minutos >= 0)
		{
			tminutos = minutos;
		}
	}

	int getTiempominutos() const
	{
		return tminutos;
	}

	void setTsegundos(int segundos)
	{
		if (segundos >= 0 && segundos < 60)
		{
			tsegundos = segundos;
		}
	}

	int getTsegundos() const
	{
		return tsegundos;
	}
};

