/*
**	Glass Engine
**	$filename
**	Author: Francisco Núñez Villagómez "Ioennir"
**	Date: 2019
*/
#pragma once
#include "GraphicManagerS.h"
#include "dataDefinitions.h"

class Sprite {
public:
	SDL_Texture * image;
	int32 width;
	int32 height;
	void LoadImage(std::string path);
	void Draw(int32 x, int32 y, SDL_Rect* clip = NULL, real32 angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	Sprite(std::string path);
private:
};