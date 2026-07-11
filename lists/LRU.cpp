#include <iostream>
#include <list>
#include <unordered_map>
#include <string>
#include <limits>

constexpr int CACHE_SIZE = 4;

class LRUCache {
private:
    struct Item {
        int key;
        std::string value;
    };

    std::list<Item> cache_list;
    std::unordered_map<int, std::list<Item>::iterator> cache_map;

public:
    const std::string* get(int key) {
        auto map_it = cache_map.find(key);
        if (map_it == cache_map.end()) {
            return nullptr;
        }

        cache_list.splice(cache_list.begin(), cache_list, map_it->second);
        return &(map_it->second->value);
    }

    void put(int key, std::string value) {
        auto map_it = cache_map.find(key);

        if (map_it != cache_map.end()) {
            map_it->second->value = std::move(value);
            cache_list.splice(cache_list.begin(), cache_list, map_it->second);
            return;
        }

        if (cache_list.size() >= CACHE_SIZE) {
            int lru_key = cache_list.back().key;
            cache_map.erase(lru_key);
            cache_list.pop_back();
        }

        cache_list.push_front({key, std::move(value)});
        cache_map[key] = cache_list.begin();
    }
};

int main() {
    LRUCache cache;

    while (true) {
        std::cout << "\n=== MENU ===\n1. Put into LRU\n2. Get from LRU\n3. Quit\nOption: ";
        int option;
        if (!(std::cin >> option)) break;

        if (option == 1) {
            int key;
            std::string value;
            std::cout << "Enter key: ";
            std::cin >> key;

            // Fix the stream buffer issue
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Enter value: ";
            std::getline(std::cin, value);

            cache.put(key, std::move(value));
        }
        else if (option == 2) {
            int key;
            std::cout << "Enter key: ";
            std::cin >> key;

            const std::string* val = cache.get(key);
            if (val) {
                std::cout << "Value is: " << *val << "\n";
            } else {
                std::cout << "Key not found (-1)\n";
            }
        }
        else if (option == 3) {
            break; // Clean exit, returns 0 automatically from main
        }
        else {
            std::cout << "Invalid option. Try again.\n";
        }
    }
    return 0;
}
