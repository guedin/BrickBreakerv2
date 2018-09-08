#include "Ball.h"

Ball::Ball(Graphics& in_gfx, Vec2 in_pos, Vec2 in_vel, Canvas& in_canvas, BrickLayout& in_layout)
	:
	pos(in_pos),
	vel(in_vel),
	boundingBox(in_pos, radius * 2, radius * 2),
	gfx(in_gfx),
	canvas(in_canvas),
	layout(in_layout)
{
}

void Ball::Draw(Graphics & gfx) const
{
	SpriteCodex::DrawBall(pos, gfx);
}

void Ball::Update()
{
	float dt = ft.Mark();
	pos += vel * dt;
	boundingBox.MoveCenterTo(pos);

	if (boundingBox.IsOutsideCanvasWidth(canvas) == 1)
	{
		ReboundX();
		pos.x = canvas.GetLeft() + radius;
		boundingBox.MoveCenterTo(pos);
	}

	if (boundingBox.IsOutsideCanvasWidth(canvas) == 2)
	{
		ReboundX();
		pos.x = canvas.GetRight() - radius;
		boundingBox.MoveCenterTo(pos);
	}

	if (boundingBox.IsOutsideCanvasHeight(canvas) == 1)
	{
		ReboundY();
		pos.y = canvas.GetTop() + radius;
		boundingBox.MoveCenterTo(pos);
	}

	if (boundingBox.IsOutsideCanvasHeight(canvas) == 2)
	{
		ReboundY();
		pos.y = canvas.GetBottom() - radius;
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

void Ball::ManageBrickCollision()
{
	int dist = 99999;
	int col = 0;
	int ind;
	for (int i = 0; i < layout.GetNBrick(); i++)
	{
		int curCol = GetBoundingBox().IsOverlapping(layout.GetBrick(i).GetBoundingBox());
		Vec2 distVec = pos - layout.GetBrick(i).GetBoundingBox().GetCenter();
		int curDist = int(distVec.GetLengthSq());
		if (curCol != 0 && curDist < dist && !layout.GetBrick(i).GetIsDestroyed())
		{
			dist = curDist;
			col = curCol;
			ind = i;
		}
	}
	if (col != 0)
	{
		layout.DestroyBrick(ind);
		if (col == 1)
		{
			ReboundY();
		}

		if (col == 2)
		{
			ReboundX();
		}
	}
}

RectF Ball::GetBoundingBox() const
{
	return boundingBox;
}
