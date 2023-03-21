#pragma once
#include <string>
#include "Vector2.h"

namespace SealEngine {
	struct Rect {
		const Vector2& position() const;
		const Vector2& size() const;
		void SetPosition(const float& x, const float& y);
		void SetSize(const float& width, const float& height);
	
		const Vector2& minVertex() const;
		const Vector2& maxVertex() const;
		void SetMin(const float& xMin, const float& yMin);
		void SetMax(const float& xMax, const float& yMax);

		const Vector2& center() const;
		void SetCenter(const float& x, const float& y);

		void Set(const float& x, const float& y, const float& width, const float& height);

		bool Contains(Vector2);
		bool Overlaps(Rect);//	Returns true if the other rectangle overlaps this one.If allowInverse is present and true, the widths and heights of the Rects are allowed to take negative values(ie, the min value is greater than the max), and the test will still work.
		std::string	ToString();//	Returns a formatted string for this Rect.

		Rect(float x, float y, float width, float height);
		Rect(Vector2 position, Vector2 size);

		static Rect zero();

		static Rect MinMaxRect(float xMin, float yMin, float xMax, float yMax);
		static Vector2 NormalizedToPoint(Rect, Vector2);//	Returns a point inside a rectangle, given normalized coordinates.
		static Vector2 PointToNormalized(Rect, Vector2);//	Returns the normalized coordinates cooresponding the the point.

		bool operator==(const Rect&) const;

	private:
		Vector2 _position, _size;
	};
}
