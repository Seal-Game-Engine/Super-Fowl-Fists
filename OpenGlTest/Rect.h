#pragma once
#include <string>
#include "Vector2.h"

namespace SealEngine {
	struct Rect {
		static Rect zero();

		Vector2 center;
		float height;//	The height of the rectangle, measured from the Y position.

		Vector2	max;//	The position of the maximum corner of the rectangle.
		Vector2	min;//	The position of the minimum corner of the rectangle.
		Vector2	position;//	The X and Y position of the rectangle.
		Vector2	size;//	The width and height of the rectangle.
		float width;//	The width of the rectangle, measured from the X position.
		float x;//	The X coordinate of the rectangle.
		float xMax;//	The maximum X coordinate of the rectangle.
		float xMin;	//The minimum X coordinate of the rectangle.
		float y;//	The Y coordinate of the rectangle.
		float yMax;//	The maximum Y coordinate of the rectangle.
		float yMin;//	The minimum Y coordinate of the rectangle.

		Rect(float, float, float, float);
		Rect(Vector2, Vector2);

		bool Contains(Vector2);//	Returns true if the x and y components of point is a point inside this rectangle.If allowInverse is present and true, the width and height of the Rect are allowed to take negative values(ie, the min value is greater than the max), and the test will still work.
		bool Overlaps(Rect);//	Returns true if the other rectangle overlaps this one.If allowInverse is present and true, the widths and heights of the Rects are allowed to take negative values(ie, the min value is greater than the max), and the test will still work.
		void Set(float, float, float, float);//	Set components of an existing Rect.
		std::string	ToString();//	Returns a formatted string for this Rect.

		static Rect MinMaxRect(float, float, float, float);//	Creates a rectangle from min / max coordinate values.
		static Vector2 NormalizedToPoint(Rect, Vector2);//	Returns a point inside a rectangle, given normalized coordinates.
		static Vector2 PointToNormalized(Rect, Vector2);//	Returns the normalized coordinates cooresponding the the point.

		bool operator==(const Rect&) const;
	};
}
