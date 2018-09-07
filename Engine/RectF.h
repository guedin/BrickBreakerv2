#pragma once
#include "Vec2.h"
#include "Graphics.h"

class RectF
{
public:
	RectF(Vec2 topLeft, Vec2 bottomRight);
	RectF(Vec2 center, float width, float height);
	void MoveCenterTo(Vec2 pos);
	int IsOutsideScreen(Graphics& gfx);
	void Draw(Graphics& gfx);
private:
	float top;
	float bottom;
	float left;
	float right;
	float width;
	float height;
};