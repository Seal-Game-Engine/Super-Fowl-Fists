#pragma once
#include "Player.h"
class TikeMyson_Player : public Player {
public:
	TikeMyson_Player(const float hp);

protected:
	void Attack_Mini() override;

private:
	TikeMyson_Player* _Clone() const override { return new TikeMyson_Player(*this); }
};

