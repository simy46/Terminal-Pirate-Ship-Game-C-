#pragma once
#include <unordered_map>
#include <string>

class Object {
public:

    Object();
    Object(const std::string& name, const std::string& description);

    const std::string& getName() const;
    const std::string& getDescription() const;

private:
    std::string name_;
    std::string description_;
};
