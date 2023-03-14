#pragma once
#include "Vector2.h"
#include "Texture2D.h"
//namespace SealEngine { struct Vector2; }

namespace SealEngine {
	class Sprite
	{
	public:
		//associatedAlphaSplitTexture	Returns the texture that contains the alpha channel from the source texture.Unity generates this texture under the hood for sprites that have alpha in the source, and need to be compressed using techniques like ETC1.Returns NULL if there is no associated alpha texture for the source sprite.This is the case if the sprite has not been setup to use ETC1 compression.
			//border	Returns the border sizes of the sprite.
			//bounds	Bounds of the Sprite, specified by its center and extents in world space units.
			//packed	Returns true if this Sprite is packed in an atlas.
			//packingMode	If Sprite is packed(see Sprite.packed), returns its SpritePackingMode.
			//packingRotation	If Sprite is packed(see Sprite.packed), returns its SpritePackingRotation.
		Vector2 pivot;//	Location of the Sprite's center point in the Rect on the original Texture, specified in pixels.
		//pixelsPerUnit	The number of pixels in the sprite that correspond to one unit in world space. (Read Only)
		//rect	Location of the Sprite on the original Texture, specified in pixels.
		//spriteAtlasTextureScale	The Variant scale of texture used by the Sprite.This is useful to check when a Variant SpriteAtlas is being used by Sprites.
		Texture2D texture;	//Get the reference to the used texture.If packed this will point to the atlas, if not packed will point to the source sprite.
		//textureRect	Get the rectangle this sprite uses on its texture.Raises an exception if this sprite is tightly packed in an atlas.
		Vector2 textureRectOffset;
		//triangles	Returns a copy of the array containing sprite mesh triangles.
		//uv	The base texture coordinates of the sprite mesh.
		Vector2 vertices[4];
	};
}

