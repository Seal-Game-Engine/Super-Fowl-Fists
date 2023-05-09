#pragma once
#include "../SealEngine.h"
using namespace SealEngine;

class SealLogoEventManager : public MonoBehaviour {
public:
	void Awake() override;

private:
	SealLogoEventManager* _Clone()const;
};
