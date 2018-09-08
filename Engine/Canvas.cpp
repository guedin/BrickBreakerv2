#include "Canvas.h"

Canvas::Canvas(Graphics& in_gfx)
	:
	gfx(in_gfx)
{
	Init();
}

void Canvas::Init()
{
	center = Vec2(gfx.ScreenWidth / 2, gfx.ScreenHeight / 2);
	left = center.x - width / 2;
	right = center.x + width / 2;
	top = center.y - height / 2;
	bottom = center.y + height / 2;
}

float Canvas::GetWidth() const
{
	return width;
}

float Canvas::GetHeight() const
{
	return height;
}

float Canvas::GetLeft() const
{
	return left;
}

float Canvas::GetRight() const
{
	return right;
}

float Canvas::GetTop() const
{
	return top;
}

float Canvas::GetBottom() const
{
	return bottom;
}

Vec2 Canvas::GetCenter() const
{
	return center;
}

void Canvas::Draw()
{
	for (int x = int(left); x < int(left) + int(width); x++)
	{
		gfx.PutPixel(x, int(top), Colors::White);
		gfx.PutPixel(x, int(top + height), Colors::White);
	}
	for (int y = int(top) +1 ; y < int(top + height) - 1; y++)
	{
		gfx.PutPixel(int(left), y, Colors::White);
		gfx.PutPixel(int(left + width), y, Colors::White);
	}
}
