#include "Ball.h"

Ball::Ball(Graphics& in_gfx, Vec2 in_pos, Vec2 in_vel)
	:
	pos(in_pos),
	vel(in_vel),
	boundingBox(in_pos, radius*2, radius*2),
	gfx(in_gfx)
{
}

void Ball::Draw(Graphics & gfx)
{
	gfx.DrawCircle(pos, radius, c);
}

void Ball::Update()
{
	float dt = ft.Mark();
	pos += vel * dt;
	boundingBox.MoveCenterTo(pos);

	if (boundingBox.IsOutsideScreenWidth(gfx) == 1)
	{
		ReboundX();
		pos.x = radius;
		boundingBox.MoveCenterTo(pos);
	}

	if (boundingBox.IsOutsideScreenWidth(gfx) == 2)
	{
		ReboundX();
		pos.x = gfx.ScreenWidth - radius;
		boundingBox.MoveCenterTo(pos);
	}

	if (boundingBox.IsOutsideScreenHeight(gfx) == 1)
	{
		ReboundY();
		pos.y = radius;
		boundingBox.MoveCenterTo(pos);
	}

	if (boundingBox.IsOutsideScreenHeight(gfx) == 2)
	{
		ReboundY();
		pos.y = gfx.ScreenHeight - radius;
		boundingBox.MoveCenterTo(pos);
	}
}

void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}

RectF Ball::GetBoundingBox()
{
	return boundingBox;
}
