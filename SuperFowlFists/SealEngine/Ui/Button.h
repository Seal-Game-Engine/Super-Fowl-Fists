#pragma once
#include "UiElement.h"
#include "../IRenderer.h"
#include <functional>

namespace SealEngine {
	namespace Ui {
		class Button : public UiElement {
		public:
			std::function<void(Button*)> onClick = [](Button*){};
			std::function<void(Button*)> onSelected = [](Button*) {};
			std::function<void(Button*)> onDeselected = [](Button*) {};

			Button(std::function<void(Button*)> onClick = [](Button*){}, std::function<void(Button*)> onSelected = [](Button*){}, std::function<void(Button*)> onDeselected = [](Button*){});

			void Awake() override;
			void Update() override;
			void OnGui() override;

		private:
			bool _isSelected = false;

			IRenderer* _image = nullptr;

			Button* _Clone() const override { return new Button(*this); }
		};
	}
}

