#include "BrickLayout.h"

BrickLayout::BrickLayout(Canvas& in_canvas)
	:
	canvas(in_canvas)
{
	Generate();
}

void BrickLayout::Generate()
{
	brickWidth = canvas.GetWidth() / row;
	int i = 0;
	for (float x = 0; x < row; x++)
	{
		for (float y = 0; y < column; y++)
		{
			bricks[i] = Brick(Vec2(x*brickWidth + canvas.GetLeft(), y*brickHeight + canvas.GetTop() + topOffset), brickWidth, brickHeight, Color(255,255,0));
			i++;
		}
	}
}

void BrickLayout::Draw(Graphics& gfx)
{
	for (int i = 0; i < nBrick; i++)
	{
		if (!bricks[i].GetIsDestroyed())
		{
			bricks[i].Draw(gfx);
		}
	}
}

int BrickLayout::GetNBrick() const
{
	return nBrick;
}

Brick & BrickLayout::GetBrick(int i)
{
	return bricks[i];
}

void BrickLayout::DestroyBrick(int i)
{
	bricks[i].Destroy();
}
