#include "object.h"

Object::Object() : name_(""), description_("") {}

Object::Object(const std::string& name, const std::string& description) : name_(name), description_(description) {}

const std::string& Object::getName() const {
    return name_;
}

const std::string& Object::getDescription() const {
    return description_;
}