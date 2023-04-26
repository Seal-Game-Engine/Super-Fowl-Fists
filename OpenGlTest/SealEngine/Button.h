#pragma once
#include "MonoBehaviour.h"
#include "SpriteRenderer.h"
#include <functional>

namespace SealEngine {
	class Button : public MonoBehaviour {
	public:
		std::function<void()> onClick = {};
		void Update() override;

		std::shared_ptr<Button> Clone() const { return std::shared_ptr<Button>(Clone_impl()); }

	private:
		SpriteRenderer* renderer;

		Button* Clone_impl() const override { return new Button(*this); }
	};
}

