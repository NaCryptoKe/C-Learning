#include "wareHouse.hpp"
#include <iostream>
#include <algorithm>

void Warehouse::addUnit(std::shared_ptr<StorageUnit> unit) {
    units.push_back(unit);
}
void Warehouse::transferUnit(std::shared_ptr<StorageUnit>, Warehouse& warehouse) {
    for (auto& unit: units) {
        warehouse.addUnit(unit);
    }
}