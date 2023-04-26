#pragma once
//#include "ApplicationManager.h";
#include <time.h>
#include <chrono>

namespace SealEngine {
	using namespace std::chrono;
	class Time{
	public:
		static float timeScale;

		static float time();
		static double timeAsDouble();
		static float deltaTime();

		static float unscaledTime();
		static double unscaledTimeAsDouble();
		static float unscaledDeltaTime();

		//fixedTime	The time since the last FixedUpdate started(Read Only).This is the time in seconds since the start of the game.
		//fixedTimeAsDouble	The double precision time since the last FixedUpdate started(Read Only).This is the time in seconds since the start of the game.
		//static float fixedDeltaTime();

		//fixedUnscaledTime	The timeScale - independent time at the beginning of the last MonoBehaviour.FixedUpdate phase(Read Only).This is the time in seconds since the start of the game.
		//fixedUnscaledTimeAsDouble	The double precision timeScale - independent time at the beginning of the last FixedUpdate(Read Only).This is the time in seconds since the start of the game.
		//fixedUnscaledDeltaTime	The timeScale - independent interval in seconds from the last MonoBehaviour.FixedUpdate phase to the current one(Read Only).

		//captureDeltaTime	Slows your application’s playback time to allow Unity to save screenshots in between frames.
		//captureFramerate	The reciprocal of Time.captureDeltaTime.
		//frameCount	The total number of frames since the start of the game(Read Only).
		//inFixedTimeStep	Returns true if called inside a fixed time step callback(like MonoBehaviour's FixedUpdate), otherwise returns false.
		//maximumDeltaTime	The maximum value of Time.deltaTime in any given frame.This is a time in seconds that limits the increase of Time.time between two frames.
		//maximumParticleDeltaTime	The maximum time a frame can spend on particle updates.If the frame takes longer than this, then updates are split into multiple smaller updates.
		//realtimeSinceStartup	The real time in seconds since the game started(Read Only).
		//realtimeSinceStartupAsDouble	The real time in seconds since the game started(Read Only).Double precision version of realtimeSinceStartup.
		//smoothDeltaTime	A smoothed out Time.deltaTime(Read Only).
		//timeSinceLevelLoad	The time since this frame started(Read Only).This is the time in seconds since the last non - additive scene has finished loading.
		//timeSinceLevelLoadAsDouble	The double precision time since this frame started(Read Only).This is the time in seconds since the last non - additive scene has finished loading.

		static void OnNextFrame();

	private:
		static steady_clock::time_point _previousFrame;

		static long double _time;
		static float _deltaTime;

		static long double _unscaledTime;
		static float _unscaledDeltaTime;
	};
}

