/*
**	Glass Engine
**	$filename
**	Author: Francisco Núñez Villagómez "Ioennir"
**	Date: 2019
*/
// Other includes
#pragma once
#include "Singleton.h"

#include "dataDefinitions.h"
#include "BaseObject.h"
#include <vector>


class ObjectManagerS : public Singleton<ObjectManagerS>
{
	friend class Singleton<ObjectManagerS>;

private:
	uint32 objectCount;
	std::vector<BaseObject*> objectList;
	
public:
	void Init();
	void Update();
	void DestroyObject(BaseObject * object);
	void AddObject(BaseObject * object);
	inline BaseObject * RetrieveObjectFromIndex(uint32 index) {
		if (index < objectCount) return objectList[index];
		return 0;
	};
	inline uint32 GetObjectCount() { return objectCount; };
};