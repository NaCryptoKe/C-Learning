#pragma once
#include "vault.hpp"
#include "item.hpp"
#include <vector>
#include <memory>

class VaultManager {
private:
    std::vector<std::shared_ptr<Vault>> vaults;

public:
    void transferVault(std::shared_ptr<Vault> vault, VaultManager& vaultManager);
    void addVault(std::shared_ptr<Vault> vault);
    void showVaults();
};