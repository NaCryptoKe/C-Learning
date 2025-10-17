#include "worker.hpp"

bool Worker::inspectStorage() {
    if (unit.expired()) {
        return false;
    }
    std::shared_ptr<StorageUnit> storageUnit = unit.lock();
}