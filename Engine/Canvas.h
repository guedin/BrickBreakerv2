#pragma once
#include "Graphics.h"
#include "Vec2.h"

class Canvas
{
public:
	Canvas() = default;
	Canvas(Graphics& in_gfx);
	void Init();
	float GetWidth() const;
	float GetHeight() const;
	float GetLeft() const;
	float GetRight() const;
	float GetTop() const;
	float GetBottom() const;
	void Draw();
private:
	Graphics & gfx;
	float width = 600.0f;
	float height = 500.0f;
	Vec2 center;
	float top;
	float left;
	float bottom;
	float right;
};