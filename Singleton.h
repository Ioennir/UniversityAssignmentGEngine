/*
**	Glass Engine
**	$filename
**	Author: Francisco Núñez Villagómez "Ioennir"
**	Date: 2019
*/
#pragma once
#include "dataDefinitions.h"
#if DEBUG
#include <stdio.h>
#endif
#include <stdlib.h>


template <class T>
class Singleton {

private:
	static T * singletonInstance;

public:
	Singleton() {};
	~Singleton() {};

	inline static void
	CreateSingleton()
	{
		if (!singletonInstance)
		{
			singletonInstance = new T();//(T *)malloc(sizeof(T));
		}
		else
		{
			printf("\nSingleton creation failed or it was already created.");
		}
	};

	inline static void
	DestroySingleton()
	{
		if (singletonInstance)
		{
			free(singletonInstance);
			singletonInstance = 0;
		}
		else
		{
			printf("\nSingleton already destroyed or never created.");
		}
	};

	inline static T*
	GetPTR()
	{
		return singletonInstance;
	}

	inline static T&
	GetREF()
	{
		return *singletonInstance;
	}
};


template <class T>
T * Singleton<T>::singletonInstance = 0;
