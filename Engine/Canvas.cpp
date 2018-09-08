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
	left = int(center.x - width / 2);
	top = int(center.y - height / 2);
}

int Canvas::GetWidth()
{
	return width;
}

int Canvas::GetHeight()
{
	return height;
}

void Canvas::Draw()
{
	for (int x = left; x < left + width; x++)
	{
		gfx.PutPixel(x, top, Colors::White);
		gfx.PutPixel(x, top + height, Colors::White);
	}
	for (int y = top +1 ; y < top + height - 1; y++)
	{
		gfx.PutPixel(left, y, Colors::White);
		gfx.PutPixel(left + width, y, Colors::White);
	}
}
