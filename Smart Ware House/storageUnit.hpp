#pragma once
#include <vector>
#include <memory>
#include "package.hpp"

class StorageUnit {
private:
    std::vector<std::unique_ptr<Package>> packages;

public:
    void addPackage(std::unique_ptr<Package> package);
    void listPackages();
    std::unique_ptr<Package> releasePackage(std::string name);
};