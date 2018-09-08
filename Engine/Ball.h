#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "RectF.h"
#include "FrameTimer.h"
#include "BrickLayout.h"
#include "SpriteCodex.h"
#include "Canvas.h"
#include "Paddle.h"

class Ball
{
public:
	Ball() = default;
	Ball(Graphics& gfx, Vec2 pos, Vec2 vel,Canvas& in_canvas, BrickLayout& in_layout, Paddle& in_paddle);
	void Draw(Graphics& gfx) const;
	void Update();
	void ReboundX();
	void ReboundY();
	void ManageBrickCollision();
	RectF GetBoundingBox() const;
private:
	RectF boundingBox;
	Graphics& gfx;
	Canvas& canvas;
	BrickLayout& layout;
	Paddle& paddle;
	Vec2 pos;
	Vec2 vel;
	Color c = Colors::Green;
	static constexpr int radius = 7;
	FrameTimer ft;
};