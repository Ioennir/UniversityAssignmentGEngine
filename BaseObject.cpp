/*
**	Glass Engine
**	$filename
**	Author: Francisco Núñez Villagómez "Ioennir"
**	Date: 2019
*/
// Other includes
#pragma once
#include "BaseObject.h"
#include "ObjectManagerS.h"
#include "GraphicManagerS.h"

BaseObject::BaseObject(int32 x,
						int32 y,
						int32 w,
						int32 h,
						real32 rot,
						uint32 flag,
						Sprite * spr)
{
	xPos = x;
	yPos = y;
	sprite = spr;
	width = w;
	height = h;
	flags = flag;
	rotation = rot;
	ObjectManagerS::GetPTR()->AddObject(this);
	if (flags) GraphicManagerS::GetPTR()->AddRenderObject(this);
}

void
BaseObject::Destroy()
{
	ObjectManagerS::GetPTR()->DestroyObject(this);
	if (flags) GraphicManagerS::GetPTR()->DestroyObject(this);
}

void 
BaseObject::Draw()
{
	sprite->Draw(xPos, yPos);
}