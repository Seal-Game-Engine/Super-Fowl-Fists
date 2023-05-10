#pragma once
#include "Player.h"
class TikeMyson_Player : public Player {
protected:
	void Attack_Mini() override;
private:
	TikeMyson_Player* _Clone() const override { return new TikeMyson_Player(*this); }
};

