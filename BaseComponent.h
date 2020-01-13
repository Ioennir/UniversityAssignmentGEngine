/*
**	Glass Engine
**	$filename
**	Author: Francisco Núñez Villagómez "Ioennir"
**	Date: 2019
*/
#pragma once
#include "dataDefinitions.h"

class BaseComponent 
{
private:
	uint32 instanceID;
	bool8 instanceFlags; // RENDERIZABLE, USEPHYSICS...

public:
	BaseComponent(uint32 id, bool8 flags) { instanceID = id; instanceFlags = flags; };
	virtual void Init() {};
	virtual void Update() {};
	inline uint32 getInstanceID() { return instanceID; };
	inline bool8 getInstanceFlags() { return instanceFlags; };
	
};