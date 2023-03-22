#pragma once
#include <string>
#include "Vector2.h"

namespace SealEngine {
	struct Rect {
		const Vector2& position() const;
		const Vector2& size() const;
		const Vector2& minVertex() const;
		const Vector2& maxVertex() const;
		const Vector2& center() const;

		void SetPosition(const float x, const float y);
		void SetSize(const float width, const float height);
		void SetMinVertex(const float xMin, const float yMin);
		void SetMaxVertex(const float xMax, const float yMax);
		void SetCenter(const float x, const float y);
		void Set(const float x, const float y, const float width, const float height);

		bool Contains(const Vector2&);
		bool Overlaps(const Rect&);//	Returns true if the other rectangle overlaps this one.If allowInverse is present and true, the widths and heights of the Rects are allowed to take negative values(ie, the min value is greater than the max), and the test will still work.


		static Rect MinMaxRect(const float xMin, const float yMin, const float xMax, const float yMax);
		static Vector2 NormalizedToPoint(const Rect&, const Vector2&);//	Returns a point inside a rectangle, given normalized coordinates.
		static Vector2 PointToNormalized(const Rect&, const Vector2&);//	Returns the normalized coordinates cooresponding the the point.

		static Rect zero();


		Rect(const float x, const float y, const float width, const float height);
		Rect(const Vector2& position, const Vector2& size);


		bool operator==(const Rect&) const;

	private:
		Vector2 _position, _size;
	};
}
