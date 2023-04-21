#pragma once
#include "SealEngine.h"
using namespace SealEngine;

class LandingEventManager : public MonoBehaviour {
public:
	void Update() override;

	std::shared_ptr<LandingEventManager> Clone() const;

private:
	LandingEventManager* Clone_impl()const;
};