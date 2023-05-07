#pragma once
#include "UiElement.h"
#include "../IRenderer.h"

namespace SealEngine {
    namespace Ui {
        class Panel : public UiElement, public IRenderer {
        public:
            Panel(const Sprite* sprite = nullptr);

            void OnGui() override;
            void Render(Transform* transform) const override;

        private:
            Panel* _Clone() const override { return new Panel(*this); }
        };
    }
}

