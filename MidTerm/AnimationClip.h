#pragma once
#include <vector>
#include "Object.h"
#include "Sprite.h"

namespace SealEngine {
	class AnimationClip : public Object {
	public:
		struct AnimationFrame {
			const Sprite& sprite;
			float duration;
		};

		float length() const;
		bool loopTime;

		std::vector<AnimationFrame> frames = std::vector<AnimationFrame>{};
		AnimationClip(std::vector<AnimationFrame> frames, bool loopTime);

	private:
		float _length;
	};
}
