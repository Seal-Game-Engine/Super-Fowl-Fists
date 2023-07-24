#pragma once
#include "UiElement.h"
#include <string>
#include "../Texture2D.h"

namespace SealEngine {
	namespace Ui {
		class Text : public UiElement {
		public:
			enum class Alignment { Left, Center, Right };

			std::string text = "";
			const Texture2D* fontTexture = nullptr;
			float fontSize = 1;
			Alignment alignment = Alignment::Center;

			Text(const std::string& text, const Texture2D* fontTexture, int fontSize = 1, Alignment alignment = Alignment::Center);

			void OnGui() override;

		private:
			Text* _Clone() const override { return new Text(*this); }
		};
	}
}

