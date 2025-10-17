#pragma once
#include "storageUnit.hpp"
#include <vector>
#include <memory>

class Warehouse {
private:
    std::vector<std::shared_ptr<StorageUnit>> units;

public:
    void addUnit(std::shared_ptr<StorageUnit> unit);
    void transferUnit(std::shared_ptr<StorageUnit>, Warehouse& warehouse);
};