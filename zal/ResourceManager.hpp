#pragma once

#include "Resource.hpp"

class ResourceManager
{
    public:
    ResourceManager(){}

    ResourceManager(const ResourceManager& rm) {}
    
      
    
    ResourceManager& operator=(ResourceManager& rm)
    {
      
      return *this;
    }

    ResourceManager(ResourceManager&& rm) {}
    
      
    
    ResourceManager& operator=(ResourceManager&& rm)
    {
        
        return *this;
    }

    ~ResourceManager(){}

    double get(){return Resource::get();}


};
