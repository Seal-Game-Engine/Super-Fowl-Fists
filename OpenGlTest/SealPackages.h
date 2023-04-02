#pragma once

#include <windows.h>

#if _WIN64
	#include <freeglut/glut.h>
	#include <SOIL2.h>
	#include <irrKlang_x64/irrKlang.h>
#elif _WIN32
	#include <glut/glut.h>
	#include <SOIL.h>
#endif
