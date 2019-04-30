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
	T_P M_Inicio;
	T_P M_Fin;

	// Esta variable determina cuanto timepo a transcurrido desde que iniciamos el cronometro .
	std::chrono::duration<double>  M_Resultado;

	std::chrono::milliseconds M_miliSegundos;//<= la variable que indica los milisegundos 
	std::chrono::microseconds M_macroSegundos;//<= la variable que indica los microsegundos.
	std::chrono::seconds M_Segundos;//<= la variable que indica los segundos.

private:
	void PrintResultado();
	enum Banderas// estos enums son para indicar las medicion de tiempo que va presentar el objeto.
	{
		AUTO = -1,
		Defecto = 0,// Es indica al objecto lo que hace por defecto . 
		Macrosegundos = 1,// Indica al objecto que va a sacar el timepo en Macrosegundos  
		Milisegundos = 2,// Indica al objecto que va a sacar el tiempo en Milisegundos 
		Segundo = 3// Indica al objecto que va a sacar el tiempo en Segundos .
	};

	Banderas m_Format = Defecto;
};

