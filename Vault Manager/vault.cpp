#include "vault.hpp"
#include <iostream>

void Vault::addItem(std::unique_ptr<Item> item) {
    items.push_back(std::move(item));
}

void Vault::showItems() {
    for (const auto& item : items) {
        item->display();
    }
}

