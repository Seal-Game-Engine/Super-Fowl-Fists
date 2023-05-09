#pragma once
#include "SealEngine.h"
using namespace SealEngine;
class Entity;

enum class Factions {
	NoFaction,//neutral, explosion, world objects
	Faction1,
	Faction2,
};

struct DamageData {
	Factions faction = Factions::NoFaction;
	float damage = 1;
	float knockbackMagnitude = 1;
	Entity* entity = nullptr;
};

class IDamageable{
public:
	virtual void TakeDamage(DamageData data, Vector2 knockbackDirection) = 0;

	Factions faction = Factions::NoFaction;
};