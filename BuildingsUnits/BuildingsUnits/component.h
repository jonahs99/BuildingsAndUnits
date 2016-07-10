#pragma once
#include "gfx/AssetLoader.h"
#include "gfx/Tilemap.h"

struct RenderComponent {

	Tilemap* tilemap;
	int tileIndex;

};

struct AnimationComponent {

	int phase, wait;

	bool enable;
	int frame;
	FrameSequence* sequence;

};

struct TranslateComponent {

	float x, y;

};

struct InputComponent {

	bool up, down, left, right;

};

struct AIComponent {

	int phase, wait;

};