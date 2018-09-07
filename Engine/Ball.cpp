#include "Ball.h"

Ball::Ball(Graphics& in_gfx, Vec2 in_pos, Vec2 in_vel)
	:
	pos(in_pos),
	vel(in_vel),
	rect(in_pos, radius*2, radius*2),
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
	rect.MoveCenterTo(pos);
	if (rect.IsOutsideScreen(gfx) != 0 )
	{
		if (rect.IsOutsideScreen(gfx) == 1)
		{
			ReboundX();
			pos.x = radius;
		}
		if (rect.IsOutsideScreen(gfx) == 2)
		{
			ReboundX();
			pos.x = gfx.ScreenWidth - radius;
		}
		if (rect.IsOutsideScreen(gfx) == 3)
		{
			ReboundY();
			pos.y = radius;
		}
		if (rect.IsOutsideScreen(gfx) == 4)
		{
			ReboundY();
			pos.y = gfx.ScreenHeight - radius;
		}
		rect.MoveCenterTo(pos);
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
