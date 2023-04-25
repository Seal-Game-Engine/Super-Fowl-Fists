#include "Time.h"
using namespace SealEngine;
using namespace std::chrono;

float Time::timeScale = 1;
steady_clock::time_point Time::_previousFrame = steady_clock::now();

long double Time::_time = 0;
float Time::_deltaTime = 0;
long double Time::_unscaledTime = 0;
float Time::_unscaledDeltaTime = 0;

float Time::time() { return (float)_time; }		//current time
double Time::timeAsDouble() { return _time; }	
float Time::deltaTime() { return _deltaTime; }	//Time difference between previous and current frame


//different devices have different frame update time, some functions to help fix that
float Time::unscaledTime() { return (float)_unscaledTime; }
double Time::unscaledTimeAsDouble() { return _unscaledTime; }
float Time::unscaledDeltaTime() { return _unscaledDeltaTime; }

void Time::OnNextFrame(){
	auto currentFrame = steady_clock::now();

	_unscaledDeltaTime = duration_cast<duration<float>>(currentFrame - _previousFrame).count();
	_unscaledTime += _unscaledDeltaTime;

	_deltaTime = _unscaledDeltaTime * timeScale;
	_time += _deltaTime;

	_previousFrame = currentFrame;
}

