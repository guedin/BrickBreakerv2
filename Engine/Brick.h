#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "RectF.h"

class Brick
{
public:
	Brick(Vec2 in_topLeftPos, float in_width, float in_height, Color in_c);
	void Draw(Graphics& gfx);
	RectF GetBoundingBox();
private:
	Vec2 topLeftPos;
	float width;
	float height;
	Color c;
};