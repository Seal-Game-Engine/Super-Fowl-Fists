#pragma once
#include "SealEngine.h"
using namespace SealEngine;

class TutorialEventManager : public MonoBehaviour{
public:
	void Update() override;

private:
	TutorialEventManager* Clone_impl() const;
};

