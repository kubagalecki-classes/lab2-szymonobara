#pragma once

#include "Resource.hpp"

class ResourceManager
{
public:
	ResourceManager()
	{
		Resource *r1 = new Resource;
		r = r1;
	}

	ResourceManager(const ResourceManager& rm)
	{
		Resource *r1 = new Resource;
		r1 = rm.r;
		r = r1;
	}

	ResourceManager& operator=(ResourceManager& rm)
	{
		if (&rm == this)
		{
			return *this;
		}
		delete r;
		Resource *r1 = new Resource;
		r1 = rm.r;
		r = r1;
		return *this;
	}

	ResourceManager(ResourceManager&& rm) 
	{
		r = rm.r;
		delete rm.r;
	}

	ResourceManager& operator=(ResourceManager&& rm)
	{
		if (&rm == this)
		{
			return *this;
		}
		r = rm.r;
		delete rm.r;
		return *this;
	}

	~ResourceManager() { delete r; }

	Resource* r;

	double get() { return r->get(); }


};
