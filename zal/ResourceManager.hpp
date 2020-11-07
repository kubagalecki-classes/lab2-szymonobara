#pragma once

#include "Resource.hpp"

class ResourceManager
{
    public:
    ResourceManager(){}

    ResourceManager(const ResourceManager& rm) 
    {
      get()=rm.get();
    }
    ResourceManager& operator=(ResourceManager& rm)
    {
      get()=rm.get();
      return *this;
    }

    ResourceManager(ResourceManager&& rm)
    {
      get()=std::move(rm.get());
    }
    ResourceManager& operator=(ResourceManager&& rm)
    {
        get()=std::move(rm.get());
        return *this;
    }

    ~ResourceManager(){}

    double get(){return Resource.get();}

};
