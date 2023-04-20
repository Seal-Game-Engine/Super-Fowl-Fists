#pragma once
#include "SealEngine.h"
using namespace SealEngine;

class LandingEventManager : public MonoBehaviour {
public:
	void Update() override;

	std::shared_ptr<LandingEventManager> Clone() const { return std::shared_ptr<LandingEventManager>(Clone_impl()); }

private:
	LandingEventManager* Clone_impl()const { return new LandingEventManager(*this); }
};