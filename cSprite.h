/*
**	Glass Engine
**	$filename
**	Author: Francisco Núñez Villagómez "Ioennir"
**	Date: 2019
*/
#pragma once

#include "BaseComponent.h"

class cSprite : public BaseComponent
{
private:
public:
	cSprite(uint32 id, bool8 flags) : BaseComponent(id, flags) {};
};