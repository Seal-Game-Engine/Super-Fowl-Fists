#include "Time.h"
using namespace SealEngine;
using namespace std::chrono;

float Time::timeScale = 1;
steady_clock::time_point Time::_previousFrame = steady_clock::now();

long double Time::_time = 0;
float Time::_deltaTime = 0;
long double Time::_unscaledTime = 0;
float Time::_unscaledDeltaTime = 0;

float Time::time() { return _time; }
double Time::timeAsDouble() { return _time; }
float Time::deltaTime() { return _deltaTime; }

float Time::unscaledTime() { return _unscaledTime; }
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

