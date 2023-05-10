#pragma once
#include "Player.h"
class Chicken_Player : public Player {
protected:
	void Attack_Mini() override;

private:
	Chicken_Player* _Clone() const override { return new Chicken_Player(*this); }
};

