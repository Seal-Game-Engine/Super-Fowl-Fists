#pragma once
#include "SealEngine.h"
using namespace SealEngine;

class LandingEventManager : public MonoBehaviour {
public:
	void Update() override;

private:
	LandingEventManager* _Clone()const;
};