#include "RectF.h"

RectF::RectF(Vec2 topLeft, Vec2 bottomRight)
	:
	top(topLeft.y),
	bottom(bottomRight.y),
	left(topLeft.x),
	right(bottomRight.x),
	width(right - left),
	height(bottom - top)
{
}

RectF::RectF(Vec2 center, float in_width, float in_height)
	:
	top(center.y - in_height/2),
	bottom(center.y + in_height/2),
	left(center.x - in_width/2),
	right(center.x + in_width/2),
	width(in_width),
	height(in_height)
{
}

void RectF::MoveCenterTo(Vec2 pos)
{
	top = pos.y - height / 2;
	bottom = pos.y + height / 2;
	left = pos.x - width / 2;
	right = pos.x + width / 2;
}

int RectF::IsOutsideScreen(Graphics & gfx)
{
	if (left <= 0)
	{
		return 1;
	}
	else if (right >= gfx.ScreenWidth)
	{
		return 2;
	}
	else if (top <= 0)
	{
		return 3;
	}
	else if (bottom >= gfx.ScreenHeight)
	{
		return 4;
	}
	else
	{
		return 0;
	}
}

void RectF::Draw(Graphics& gfx)
{
	gfx.DrawRect(int(left), int(top), int(right), int(bottom), Colors::Cyan);
}
