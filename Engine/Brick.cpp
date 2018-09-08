#include "Brick.h"

Brick::Brick(Vec2 in_topLeftPos, float in_width, float in_height, Color in_c)
	:
	topLeftPos(in_topLeftPos),
	width(in_width),
	height(in_height),
	c(in_c)
{
}

void Brick::Draw(Graphics & gfx) const
{
	gfx.DrawRect(int(topLeftPos.x), int(topLeftPos.y), int(topLeftPos.x + width), int(topLeftPos.y + height), c);
}

RectF Brick::GetBoundingBox() const
{
	return RectF(topLeftPos, topLeftPos + Vec2(width, height));
}
