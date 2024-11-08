#pragma once
#include <iostream>
#include <string>
class song
{

private:
	int tminutos;
	int tsegundos;

public:

	std::string nombre;
	std::string getNombre() const;

	song(std::string n, int m, int s);
	song();
	int ToSec() const;
	bool HastheSameTime(const song& s) const;


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

	//clase 01/11/24
	friend bool operator==(const song& c1, const song& c2);
	
	friend bool operator<(const song& c1, const song& c2);

	void print();
};

