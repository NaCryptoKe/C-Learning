// main.cpp
#include "vaultManager.hpp"
#include <iostream>
#include <memory>

int main() {
    VaultManager vaultManager1;
    VaultManager vaultManager2;

    // Create Vaults on the heap, managed by shared_ptr
    auto vault1 = std::make_shared<Vault>();
    vault1->addItem(std::make_unique<Item>("Gold Coin", 100));
    vault1->addItem(std::make_unique<Item>("Silver Coin", 50));

    auto vault2 = std::make_shared<Vault>();
    vault2->addItem(std::make_unique<Item>("Diamond", 500));

    // Add the shared pointers to the manager
    vaultManager1.addVault(vault1);
    vaultManager1.addVault(vault2);

    std::cout << "--- Vaults in Manager 1 (Before Transfer) ---" << std::endl;
    vaultManager1.showVaults();

    // Transfer vault1 from manager1 to manager2
    vaultManager1.transferVault(vault1, vaultManager2);

    std::cout << "\n--- Vaults in Manager 1 (After Transfer) ---" << std::endl;
    vaultManager1.showVaults();

    std::cout << "\n--- Vaults in Manager 2 (After Transfer) ---" << std::endl;
    vaultManager2.showVaults();

    return 0;
}