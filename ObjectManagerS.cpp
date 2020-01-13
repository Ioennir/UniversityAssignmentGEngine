/*
**	Glass Engine
**	$filename
**	Author: Francisco Núñez Villagómez "Ioennir"
**	Date: 2019
*/
#pragma once

#include "ObjectManagerS.h"

void
ObjectManagerS::Init()
{
	objectCount = 0;
	
}

void
ObjectManagerS::Update()
{
	uint32 i = 0;
	for (i; i < objectCount; i++) {
		objectList[i]->Update();
	}
		
}

void
ObjectManagerS::DestroyObject(BaseObject * object)
{
	uint32 i = 0;
	for (i; i < objectCount; i++) {
		if (objectList[i] == object) {
			objectList.erase(objectList.begin() + i);
			objectCount--;
			break;
		}
	}
}

void
ObjectManagerS::AddObject(BaseObject * object)
{
	objectCount++;
	objectList.push_back(object);
	object->Init();
}