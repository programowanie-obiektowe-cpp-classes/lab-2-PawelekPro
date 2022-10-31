#pragma once

#include "Resource.hpp"
#include <iostream>

using namespace std;

class ResourceManager
{
public:

    // KONSTRUKTOR DOMYSLNY
    ResourceManager() { resource = new Resource; }

     // DESTRUKTOR
    ~ResourceManager() { delete resource; }

    // KONSTRUKTOR KOPIUJ¥CY
    ResourceManager(const ResourceManager& CRM) { resource = new Resource{*CRM.resource}; }

    // KONSTRUKTOR PRZENOSZENIA
    ResourceManager(ResourceManager&& MoveRM) 
    { 
        resource = MoveRM.resource;
        MoveRM.resource = nullptr;
    }
     
    // KONSTRUKTOR PRZYPISANIA
    ResourceManager& operator=(const ResourceManager& MoveRM) 
    { 
        if (this != &MoveRM) {
            delete resource;
            resource = new Resource{*MoveRM.resource};
        }
        return *this;
    }

    // FUNKCJA DOUBLE GET
    double get() { return resource->get(); }


private:
    Resource* resource = nullptr;
};
