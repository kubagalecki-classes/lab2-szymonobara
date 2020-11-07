#pragma once

#include "Resource.hpp"

class ResourceManager
{
    public:
    ResourceManager(){}

    ResourceManager(const ResourceManager& rm): r.get(){rm.get()} {}
    
    ResourceManager& operator=(ResourceManager& rm)
    {
      r.get()=rm.get();
      return *this;
    }

    ResourceManager(ResourceManager&& rm) {}
    
    ResourceManager& operator=(ResourceManager&& rm)
    {
        return *this;
    }

    ~ResourceManager(){}

    Resource r;

    double get(){return r.get();}


};
