#pragma once
#include "SealEngine.h"
using namespace SealEngine;

class Explosion :    public MonoBehaviour{
public:
	Explosion(float lifeSpan);

	void Awake() override;

private:
	float _lifeSpan = 1;

	Explosion* _Clone()const override { return new Explosion(*this); }
};

