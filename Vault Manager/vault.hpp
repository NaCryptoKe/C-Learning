#pragma once
#include <vector>
#include <memory>
#include "item.hpp"

class Vault {
private:
    std::vector<std::unique_ptr<Item>> items;

public:
    void addItem(std::unique_ptr<Item> item);
    void showItems();
    void transferVault();
};