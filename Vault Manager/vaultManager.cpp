#include "vaultManager.hpp"
#include <iostream>
#include <algorithm>

void VaultManager::transferVault(std::shared_ptr<Vault> vault, VaultManager& vaultManager) {
    for (auto& vault : vaults) {
        vaultManager.addVault(vault);
    }
}

void VaultManager::addVault(std::shared_ptr<Vault> vault) {
    vaults.push_back(vault);
}

void VaultManager::showVaults() {
    for (const auto& vault : vaults) {
        vault->showItems();
    }
}