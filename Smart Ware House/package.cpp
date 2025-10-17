#include "package.hpp"
#include <iostream>

Package::Package(const std::string& name, int value) : name(name), weight(weight) {
    std::cout << name << " package created\n";
}

void Package::display() const {
    std::cout << "Name: " <<name << " (Weight: " << weight << ")\n";
}

std::string Package::getName() const {
    return name;
}

Package::~Package() {
    std::cout << name << " package destroyed\n";
}