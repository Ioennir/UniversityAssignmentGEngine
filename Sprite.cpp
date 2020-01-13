/*
**	Glass Engine
**	$filename
**	Author: Francisco Núñez Villagómez "Ioennir"
**	Date: 2019
*/
#pragma once
#include "Sprite.h"

Sprite::Sprite(std::string path)
{
	LoadImage(path);
}

void 
Sprite::LoadImage(std::string path) {
	SDL_Surface * loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
	image = SDL_CreateTextureFromSurface(GraphicManagerS::GetPTR()->GetRenderer(), loadedSurface);
	width = loadedSurface->w;
	height = loadedSurface->h;
}

void
Sprite::Draw(int32 x, int32 y, SDL_Rect* clip, real32 angle, SDL_Point* center, SDL_RendererFlip flip)
{
	SDL_Rect renderQuad = { x, y, width, height };
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	SDL_RenderCopyEx(GraphicManagerS::GetPTR()->GetRenderer(), image, clip, &renderQuad, angle, center, flip);
}