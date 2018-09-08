#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "Canvas.h"

class RectF
{
public:
	RectF(Vec2 topLeft, Vec2 bottomRight);
	RectF(Vec2 center, float width, float height);
	void MoveCenterTo(Vec2 pos);
	int IsOutsideScreenWidth(Graphics& gfx);
	int IsOutsideScreenHeight(Graphics& gfx);
	int IsOutsideCanvasWidth(Canvas& canvas);
	int IsOutsideCanvasHeight(Canvas& canvas);
	void Draw(Graphics& gfx);
	int IsOverlapping(RectF rec2);
	Vec2 GetCenter();
private:
	float top;
	float bottom;
	float left;
	float right;
	float width;
	float height;
};