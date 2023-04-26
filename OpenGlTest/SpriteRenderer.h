#pragma once
#include "MonoBehaviour.h"
#include "Sprite.h"

namespace SealEngine {
	class SpriteRenderer : public MonoBehaviour {
	public:
		//adaptiveModeThreshold	The current threshold for Sprite Renderer tiling.
			//color	Rendering color for the Sprite graphic.
			//drawMode	The current draw mode of the Sprite Renderer.
		bool flipX = false, flipY = false;
		//maskInteraction	Specifies how the sprite interacts with the masks.
		//size	Property to set or get the size to render when the SpriteRenderer.drawMode is set to SpriteDrawMode.Sliced or SpriteDrawMode.Tiled.
		const Sprite* sprite = nullptr;
		
		//spriteSortPoint	Determines the position of the Sprite used for sorting the SpriteRenderer.
		//tileMode
		bool forceRenderingOff = false;//	Allows turning off rendering for a specific component.
		/*	isPartOfStaticBatch	Indicates whether the renderer is part of a static batch with other renderers.
			isVisible	Is this renderer visible in any camera ? (Read Only)
			lightmapIndex	The index of the baked lightmap applied to this renderer.
			lightmapScaleOffset	The UV scale & offset used for a lightmap.
			lightProbeProxyVolumeOverride	If set, the Renderer will use the Light Probe Proxy Volume component attached to the source GameObject.
			lightProbeUsage	The light probe interpolation type.
			localBounds	The bounding box of the renderer in local space.
			localToWorldMatrix	Matrix that transforms a point from local space into world space(Read Only).
			material	Returns the first instantiated Material assigned to the renderer.
			materials	Returns all the instantiated materials of this object.
			motionVectorGenerationMode	Specifies the mode for motion vector rendering.
			probeAnchor	If set, Renderer will use this Transform's position to find the light or reflection probe.
			rayTracingMode	Describes how this renderer is updated for ray tracing.
			realtimeLightmapIndex	The index of the real - time lightmap applied to this renderer.
			realtimeLightmapScaleOffset	The UV scale & offset used for a real - time lightmap.
			receiveShadows	Does this object receive shadows ?
			reflectionProbeUsage	Should reflection probes be used for this Renderer ?
			rendererPriority	This value sorts renderers by priority.Lower values are rendered first and higher values are rendered last.
			renderingLayerMask	Determines which rendering layer this renderer lives on.
			shadowCastingMode	Does this object cast shadows ?
			sharedMaterial	The shared material of this object.
			sharedMaterials	All the shared materials of this object.
			sortingLayerID	Unique ID of the Renderer's sorting layer.
			sortingLayerName	Name of the Renderer's sorting layer.
			sortingOrder	Renderer's order within a sorting layer.
			staticShadowCaster	Is this renderer a static shadow caster ?
			worldToLocalMatrix*/
		SpriteRenderer() = default;
		SpriteRenderer(const Sprite* sprite, bool flipX, bool flipY);
		SpriteRenderer(const SpriteRenderer& obj) :MonoBehaviour(obj), sprite(obj.sprite), flipX(obj.flipX), flipY(obj.flipY) {}
		std::shared_ptr<SpriteRenderer> Clone() const { return std::shared_ptr<SpriteRenderer>(Clone_impl()); }

		void Awake() override;
		void Update() override;
		void LateUpdate() override;

	private:
		virtual SpriteRenderer* Clone_impl() const override { return new SpriteRenderer(*this); }
	};
}

