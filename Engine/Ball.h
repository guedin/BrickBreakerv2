#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "RectF.h"
#include "FrameTimer.h"
#include "BrickLayout.h"
#include "SpriteCodex.h"

class Ball
{
public:
	Ball() = default;
	Ball(Graphics& gfx, Vec2 pos, Vec2 vel, BrickLayout& in_layout);
	void Draw(Graphics& gfx) const;
	void Update();
	void ReboundX();
	void ReboundY();
	void ManageBrickCollision();
	RectF GetBoundingBox() const;
private:
	RectF boundingBox;
	Graphics& gfx;
	BrickLayout& layout;
	Vec2 pos;
	Vec2 vel;
	Color c = Colors::Green;
	static constexpr int radius = 7;
	FrameTimer ft;
};