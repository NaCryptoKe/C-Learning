#include "item.hpp"
#include <iostream>

Item::Item(const std::string& name, int value) 
    : name(name), value(value) {}

std::string Item::getName() const {
    return name;
}

int Item::getValue() const {
    return value;
}

void Item::display() const {
    std::cout << "Vault Name: " << name << " (Value "<< value << " )\n";
}