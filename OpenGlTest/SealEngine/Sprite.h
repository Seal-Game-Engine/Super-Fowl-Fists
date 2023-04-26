#pragma once
#include <array>
#include "Object.h"
#include "Vector2.h"
#include "Rect.h"
namespace SealEngine { class Texture2D; }

namespace SealEngine {
	class Sprite : public Object {
	public:
		//associatedAlphaSplitTexture	Returns the texture that contains the alpha channel from the source texture.Unity generates this texture under the hood for sprites that have alpha in the source, and need to be compressed using techniques like ETC1.Returns NULL if there is no associated alpha texture for the source sprite.This is the case if the sprite has not been setup to use ETC1 compression.
		//border	Returns the border sizes of the sprite.
		//bounds	Bounds of the Sprite, specified by its center and extents in world space units.
		//packed	Returns true if this Sprite is packed in an atlas.
		//packingMode	If Sprite is packed(see Sprite.packed), returns its SpritePackingMode.
		//packingRotation	If Sprite is packed(see Sprite.packed), returns its SpritePackingRotation.
		Vector2 pivot; //	Location of the Sprite's center point in the Rect on the original Texture, specified in pixels.
		float pixelsPerUnit() const;//	The number of pixels in the sprite that correspond to one unit in world space. (Read Only)
		Rect rect;	//Location of the Sprite on the original Texture, specified in pixels.
		//spriteAtlasTextureScale	The Variant scale of texture used by the Sprite.This is useful to check when a Variant SpriteAtlas is being used by Sprites.
		const Texture2D* texture = nullptr;
		//Rect textureRect;
		Vector2 textureRectOffset = Vector2(0, 0);
		//uv	The base texture coordinates of the sprite mesh.
		std::array<Vector2, 4> vertices() const;

		void LoadVertices();
		Sprite(const Texture2D& texture, const Rect& rect, const Vector2& pivot, float pixelsPerUnit);

	private:
		float _pixelsPerUnit = 16;
		std::array<Vector2, 4> _vertices{ Vector2::zero(), Vector2::zero(), Vector2::zero(), Vector2::zero() };
	};
}