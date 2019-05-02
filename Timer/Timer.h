#pragma once
#include <chrono>
#include <cinttypes>

class Timer
{
	/*! used for measuring durations in terms of picoseconds*/
	using TimeMeasurementPico = std::chrono::duration<uint64_t, std::pico>;

	/*! this duration that can have a decimal point
	(just because I get confused with other Representation)*/
	using TimeMeasurementSeconds = std::chrono::duration<double, std::ratio<1, 1>>;

	/*! making a typedef to be used with the chrono library*/
	using TimePointPicoSeconds = std::chrono::time_point<std::chrono::steady_clock, TimeMeasurementPico>;

public:// constructor
	Timer();
	~Timer();
public: // functions 

	void StartTiming();
	void EndTiming();
private:
	void PrintResult();

private:// variables
	TimePointPicoSeconds m_Start;
	TimePointPicoSeconds m_End;

	TimeMeasurementPico m_Result;
};

