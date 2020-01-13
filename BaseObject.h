/*
**	Glass Engine
**	$filename
**	Author: Francisco Núñez Villagómez "Ioennir"
**	Date: 2019
*/
#pragma once
#include <string>
#include <SDL_image.h>
#include "Sprite.h"
#include "dataDefinitions.h"

class BaseObject
{
private:
	Sprite * sprite;
	
public:
	BaseObject(int32 x, int32 y, int32 w, int32 h, real32 rot, uint32 flag, Sprite * spr);
	int32 xPos;
	int32 yPos;
	int32 width;
	int32 height;
	real32 rotation;
	uint32 flags;
	virtual void Init() {};
	virtual void Update() {};
	void Destroy();
	void Draw();
};