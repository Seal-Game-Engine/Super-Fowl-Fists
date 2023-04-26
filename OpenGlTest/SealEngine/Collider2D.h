#pragma once
#include "../SealEngine.h"
using namespace SealEngine;

class Collider2D :public MonoBehaviour{
public:
	Collider2D() = default;
	Collider2D(float width, float height);

	void Update() override;
	std::shared_ptr<Collider2D> Clone() const { return std::shared_ptr<Collider2D>(Clone_impl()); }
	static bool checkCollision(Collider2D& a,Collider2D& b);
	Rect colliderBox = Rect(0,0,1,1);

private:
	float width = 1;
	float height = 1;
	virtual Collider2D* Clone_impl() const override { return new Collider2D(*this); }

};

