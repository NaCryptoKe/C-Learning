#include "wareHouse.hpp"
#include <iostream>

class Worker {
private:
    std::weak_ptr<StorageUnit> unit;

public:
    bool inspectStorage();
};