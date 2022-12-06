#pragma once

#include "Resource.hpp"
#include <iostream>

class ResourceManager
{
public:

    // KONSTRUKTOR DOMYSLNY
    ResourceManager() { resource = new Resource; }

    // DESTRUKTOR
    ~ResourceManager() { delete resource; }

    // KONSTRUKTOR KOPIUJ�CY
    ResourceManager(const ResourceManager& CopyRM) { resource = new Resource{*CopyRM.resource}; }

    // KONSTRUKTOR PRZENOSZENIA
    ResourceManager(ResourceManager&& MoveRM) 
    { 
        resource = MoveRM.resource;
        MoveRM.resource = nullptr;
    }
     
    // KONSTRUKTOR PRZYPISANIA
    ResourceManager& operator=(const ResourceManager& MoveRM) 
    { 
        if (this != &MoveRM) { //this wskazuje na obiekt, dla kt�rego zosta�a wywo�ana metoda
            delete resource;
            resource = new Resource{*MoveRM.resource};
        }
        return *this;
    }
    // OPERATOR PRZYPISANIA (przenosz�cy)
    ResourceManager& operator=(ResourceManager&& MoveRM) 
    { 
        if (this != &MoveRM) {
            delete resource;
            resource = MoveRM.resource;
            MoveRM.resource = nullptr;
        }
        return *this;
    }

    // FUNKCJA DOUBLE GET
    double get() { return resource->get(); }

    // BRAK WYCIEK�W PAMI�CI
private:
    Resource* resource = nullptr; // wskaznik pusty
};
