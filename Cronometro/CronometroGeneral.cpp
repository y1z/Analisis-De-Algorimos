#include "CronometroGeneral.h"

// contructor por defecto . 
Cronometro::Cronometro() {}

// contructor sobrecargado valores validos [mc] [ms] [s] [auto]
Cronometro::Cronometro(std::string Indicador)
{
	if (Indicador == "mc") {
		m_Format = MicroSegundos;
	}
	else if (Indicador == "ms") {
		m_Format = MiliSegundos;
	}
	else if (Indicador == "s") {
		m_Format = Segundo;
	}
	else if (Indicador == "auto" || Indicador == "Auto") {
		m_Format = AUTO;
		StartTimer();
	}
	else {
		std::cout << "ERROR No reconosco este Formate Aqui una lista de formatos validos \n";
		std::cout << "1. 'mc' \n 2. 'ms' \n 3. auto";
		std::cin.ignore();
		std::cin.get();
	}

}

// destructor por defecto .
Cronometro::~Cronometro() {
	if (m_Format == AUTO)
	{
		m_Fin = ::high_resolution_clock::now();
		m_Resultado = m_Fin - m_Inicio;
		std::cout << "El Timepo Fue " << m_Resultado.count() << " s";
	}
}

// para Iniciar el conteo del timepo 
void Cronometro::StartTimer()
{
	m_Inicio = ::high_resolution_clock::now();//<= consigo el timepo del inicio 
}

// para Finaliza el conteo del tiempo 
void Cronometro::EndTimer()
{

	m_Fin = ::high_resolution_clock::now();//<= consigo el timepo final 
	m_Resultado = m_Fin - m_Inicio;//<= el resultado 


	switch (m_Format)
	{
	case(Normal):
		PrintResultado();
		break;

	case(Segundo):
		m_Segundos = std::chrono::duration_cast<std::chrono::seconds>(m_Resultado);
		PrintResultado();
		break;

	case(MiliSegundos):
		m_miliSegundo = std::chrono::duration_cast<std::chrono::milliseconds>(m_Resultado);
		PrintResultado();
		break;

	case(MicroSegundos):
		m_MicroSegundos = std::chrono::duration_cast<std::chrono::microseconds>(m_Resultado);
		PrintResultado();
		break;

	default:
		break;
	}

}

// para enseñar el resultado .
void Cronometro::PrintResultado() {

	// lo que hace este switch case es determinar cual Unidad de timepo presentar al usuario y imprimirlo en la consola.
	switch (m_Format)
	{
	case(Normal):
		std::cout << "El Timepo fue " << m_Resultado.count() << "s\n";
		break;
	case(Segundo):
		if (m_Segundos.count() == 1)
		{
			std::cout << "El Timepo fue " << m_Segundos.count() << " Segundo\n";
		}
		else
		{
			std::cout << "El Timepo fue " << m_Segundos.count() << " Segundos\n";
		}
		break;
	case(MiliSegundos):
		std::cout << "El Tiempo fue " << m_miliSegundo.count() << " ms\n";
		break;
	case(MicroSegundos):

		if (m_MicroSegundos.count() == 1)
		{
			std::cout << "El Tiempo fue " << m_MicroSegundos.count() << " MicroSegundos \n";
		}
		else
		{
			std::cout << "El Tiempo fue " << m_MicroSegundos.count() << " MicroSegundos \n";
		}
		break;
	default:
		std::cout << "El Timepo fue " << m_Resultado.count() << " s";
		break;
	}
	// Reseting the Timer
	m_Inicio.min();
	m_Fin.min();

	m_Resultado.zero();
	m_MicroSegundos.zero();
	m_miliSegundo.zero();

}

void Cronometro::ChoseTimerMeasurement(std::string Indicador) {


	if (Indicador == "mc") {
		m_Format = MicroSegundos;
	}
	else if (Indicador == "ms") {
		m_Format = MiliSegundos;
	}
	else if (Indicador == "s") {
		m_Format = Segundo;
	}
	else {
		std::cout << "error no reconosco el formato que pasaste aqui una lista de formatos valido \n";
		std::cout << "1. [mc]\n 2. [ms] \n 3. [s]";
		std::cin.ignore();
		std::cin.get();
	}


}
