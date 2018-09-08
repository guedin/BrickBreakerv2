#include "Paddle.h"

Paddle::Paddle(Canvas & in_canvas)
	:
	canvas(in_canvas)
{
}

void Paddle::Draw(Graphics & gfx)
{
	boundingBox.Draw(gfx);
}

void Paddle::Update(Keyboard & kbd)
{
	float dt = ft.Mark();
	if (kbd.KeyIsPressed(VK_LEFT) == true)
	{
		pos.x = pos.x - vel * dt;
	}
	if (kbd.KeyIsPressed(VK_RIGHT) == true)
	{
		pos.x = pos.x + vel * dt;
	}
	boundingBox.MoveCenterTo(pos);

	if (boundingBox.IsOutsideCanvasWidth(canvas) == 1)
	{
		pos.x = canvas.GetLeft() + boundingBox.GetWidth() / 2 + 1;
	}

	if (boundingBox.IsOutsideCanvasWidth(canvas) == 2)
	{
		pos.x = canvas.GetRight() - boundingBox.GetWidth() / 2 - 1;
	}
	boundingBox.MoveCenterTo(pos);
}

RectF Paddle::GetBoundingBox() const
{
	return boundingBox;
}
