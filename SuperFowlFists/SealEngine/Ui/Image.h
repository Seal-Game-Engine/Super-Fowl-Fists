#pragma once
#include "UiElement.h"
#include "../IRenderer.h"

namespace SealEngine {
    namespace Ui {
        class Image : public UiElement, public IRenderer {
        public:
            Image(const Sprite* sprite = nullptr);

            void OnGui() override;

        private:
            Image* _Clone() const override { return new Image(*this); }
        };
    }
}

