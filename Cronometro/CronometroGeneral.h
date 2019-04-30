#pragma once
#include <iostream>
#include <chrono>
#include <string>

//------------------------------------------//
using std::chrono::high_resolution_clock;

class Cronometro
{

	// hice esto para no tener que teclar "std::chrono::high_resolution_clock::time_point" mill veces 
	typedef std::chrono::high_resolution_clock::time_point T_P;
public:
	Cronometro(); 
	// this constructor let the user chose how to measuer time 
	Cronometro(std::string Indicador);

	~Cronometro();
public:
	void StartTimer();
	void EndTimer();
	void ChoseTimerMeasurement(std::string Indicador);
private:
	T_P m_Inicio;
	T_P m_Fin;

	// Esta variable determina cuanto timepo a transcurrido desde que iniciamos el cronometro .
	std::chrono::duration<double>  m_Resultado;

	std::chrono::milliseconds m_miliSegundo;//<= la variable que indica los milisegundos 
	std::chrono::microseconds m_MicroSegundos;//<= la variable que indica los microsegundos.
	std::chrono::seconds m_Segundos;//<= la variable que indica los segundos.

private:
	void PrintResultado();
	enum Flags// estos enums son para indicar las medicion de tiempo que va presentar el objeto.
	{
		AUTO = -1,
		Normal = 0,// Es indica al objecto lo que hace por defecto . 
		Macrosegundos = 1,// Indica al objecto que va a sacar el timepo en Macrosegundos  
		Milisegundos = 2,// Indica al objecto que va a sacar el tiempo en Milisegundos 
		Segundo = 3// Indica al objecto que va a sacar el tiempo en Segundos .
	};

	Flags m_Format = Normal;
};

