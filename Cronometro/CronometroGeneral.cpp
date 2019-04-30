#include "CronometroGeneral.h"

// contructor por defecto . 
Cronometro::Cronometro() {}

// contructor sobrecargado valores [mc] [ms] [s]
Cronometro::Cronometro(std::string Indicador)
{
	if (Indicador == "mc") {
		m_Format = Macrosegundos;
	}
	else if (Indicador == "ms") {
		m_Format = Milisegundos;
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
		M_Fin = ::high_resolution_clock::now();
		M_ResultadoPorDefecto = M_Fin - M_Inicio;
		std::cout << "El Timepo Fue " << M_ResultadoPorDefecto.count() << " s";
	}
}

// para Iniciar el conteo del timepo 
void Cronometro::StartTimer()
{
	M_Inicio = ::high_resolution_clock::now();//<= consigo el timepo del inicio 
}

// para Finaliza el conteo del tiempo 
void Cronometro::EndTimer()
{

	M_Fin = ::high_resolution_clock::now();//<= consigo el timepo final 
	M_ResultadoPorDefecto = M_Fin - M_Inicio;//<= el resultado 


	switch (m_Format)
	{
	case(Defecto):
		PrintResultado();
		break;

	case(Segundo):
		M_Segundos = std::chrono::duration_cast<std::chrono::seconds>(M_ResultadoPorDefecto);
		PrintResultado();
		break;

	case(Milisegundos):
		M_miliSegundos = std::chrono::duration_cast<std::chrono::milliseconds>(M_ResultadoPorDefecto);
		PrintResultado();
		break;

	case(Macrosegundos):
		M_macroSegundos = std::chrono::duration_cast<std::chrono::microseconds>(M_ResultadoPorDefecto);
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
	case(Defecto):
		std::cout << "El Timepo fue " << M_ResultadoPorDefecto.count() << "s\n";
		break;
	case(Segundo):
		if (M_Segundos.count() == 1)
		{
			std::cout << "El Timepo fue " << M_Segundos.count() << " Segundo\n";
		}
		else
		{
			std::cout << "El Timepo fue " << M_Segundos.count() << " Segundos\n";
		}
		break;
	case(Milisegundos):
		std::cout << "El Tiempo fue " << M_miliSegundos.count() << " ms\n";
		break;
	case(Macrosegundos):

		if (M_macroSegundos.count() == 1)
		{
			std::cout << "El Tiempo fue " << M_macroSegundos.count() << " MacroSegundo";
		}
		else
		{
			std::cout << "El Tiempo fue " << M_macroSegundos.count() << " MacroSegundos";
		}
		break;
	default:
		std::cout << "El Timepo fue " << M_ResultadoPorDefecto.count() << " s";
		break;
	}
}

void Cronometro::ChoseTimerMeasurement(std::string Indicador) {
	if (Indicador == "mc") {
		m_Format = Macrosegundos;
	}
	else if (Indicador == "ms") {
		m_Format = Milisegundos;
	}
	else if (Indicador == "s") {
		m_Format = Segundo;
	}
	else {
		std::cout << "error no reconosco la medicion de timepo que me indicaste\n El tiempo se presentara de la forma por defecto de presentacion. \n preciona enter";
		std::cin.ignore();
		std::cin.get();
	}


}

