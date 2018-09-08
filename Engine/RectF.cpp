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

int RectF::IsOutsideScreenWidth(Graphics & gfx)
{
	if (left <= 0)
	{
		return 1;
	}
	else if (right >= gfx.ScreenWidth)
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

int RectF::IsOutsideScreenHeight(Graphics & gfx)
{
	if (top <= 0)
	{
		return 1;
	}
	else if (bottom >= gfx.ScreenHeight)
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

int RectF::IsOutsideCanvasWidth(Canvas & canvas)
{
	if (left <= canvas.GetLeft())
	{
		return 1;
	}
	else if (right >= canvas.GetRight())
	{
		return 2;
	}
	else
	{
		return 0;
	};
}

int RectF::IsOutsideCanvasHeight(Canvas & canvas)
{
	if (top <= canvas.GetTop())
	{
		return 1;
	}
	else if (bottom >= canvas.GetBottom())
	{
		return 2;
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

int RectF::IsOverlapping(RectF rec2)
{
	if (right > rec2.left && left < rec2.right && bottom > rec2.top && top < rec2.bottom)
	{
		if (GetCenter().GetNormalized().y > rec2.GetCenter().GetNormalized().y)
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	else
	{
		return 0;
	}
}

float RectF::GetLeft() const
{
	return left;
}

float RectF::GetRight() const
{
	return right;
}

float RectF::GetTop() const
{
	return top;
}

float RectF::GetBottom() const
{
	return bottom;
}

float RectF::GetWidth() const
{
	return width;
}

float RectF::GetHeight() const
{
	return height;
}

Vec2 RectF::GetCenter() const
{
	return Vec2(left + width, top + height);
}
