#pragma once
#include "Graphics.h"
#include "Vec2.h"

class Canvas
{
public:
	Canvas() = default;
	Canvas(Graphics& in_gfx);
	void Init();
	int GetWidth();
	int GetHeight();
	void Draw();
private:
	Graphics & gfx;
	int width = 600;
	int height = 500;
	Vec2 center;
	int top;
	int left;
};