#include "storageUnit.hpp"
#include <iostream>

void StorageUnit::addPackage(std::unique_ptr<Package> package) {
    packages.push_back(std::move(package));
}

void StorageUnit::listPackages() {
    for (const auto& package: packages) {
        package->display();
    }
}

std::unique_ptr<Package> StorageUnit::releasePackage(std::string name) {
    for (const auto& package: packages) {
        if (package->getName() == name) {
            std::unique_ptr<Package> temp = std::move(package);
            return temp;
        }
    }
}