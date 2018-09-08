#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "RectF.h"
#include "FrameTimer.h"
#include "BrickLayout.h"

class Ball
{
public:
	Ball() = default;
	Ball(Graphics& gfx, Vec2 pos, Vec2 vel, BrickLayout& in_layout);
	void Draw(Graphics& gfx);
	void Update();
	void ReboundX();
	void ReboundY();
	void ManageBrickCollision();
	RectF GetBoundingBox();
private:
	RectF boundingBox;
	Graphics& gfx;
	BrickLayout& layout;
	Vec2 pos;
	Vec2 vel;
	Color c = Colors::Green;
	static constexpr int radius = 6;
	FrameTimer ft;
};