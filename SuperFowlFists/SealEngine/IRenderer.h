#pragma once
#include "Sprite.h"
namespace SealEngine { class Transform; }

namespace SealEngine {
	class IRenderer {
	public:
		virtual void Render(Transform* transform) const;

		const Sprite* sprite = nullptr;

		IRenderer(const Sprite* sprite = nullptr);
	};
}
