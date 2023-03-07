#pragma once
#include <string>
#include "time.h"
#include "SealEngine.h"
	using namespace SealEngine;

class Parallax {
public:
	Parallax();

	void drawSquare(float, float);
	void initParallax();
	void scroll(bool, std::string, float);

	float xMax = 1, xMin = 0, yMax = 0, yMin = 1;

	TextureLoader textureLoader;

	clock_t startTime;
};

