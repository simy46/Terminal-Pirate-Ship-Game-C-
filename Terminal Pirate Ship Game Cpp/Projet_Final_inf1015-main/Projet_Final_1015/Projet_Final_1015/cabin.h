#pragma once
#include "Object.h"

class Cabin {
public:

    Cabin();
    Cabin(const std::string& name, const std::string& description);

    const std::string& getName() const;
    const std::string& getDescription() const;
    const std::vector<Object>& getObjects() const;

    void addObject(const Object& object);

    const Object* findObject(const std::string& keyword) const;

private:
    std::string name_;
    std::string description_;
    std::vector<Object> objects_;
};

