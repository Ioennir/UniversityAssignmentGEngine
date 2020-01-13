/*
**	Glass Engine
**	$filename
**	Author: Francisco Núñez Villagómez "Ioennir"
**	Date: 2019
*/
#pragma once

#include "BaseComponent.h"

class cTransform : public BaseComponent 
{
public:

	cTransform(uint32 id, bool8 flags) : BaseComponent(id, flags) {};
	void Init() {};
};
