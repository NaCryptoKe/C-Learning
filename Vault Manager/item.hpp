#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

class Item {
private:
    std::string name = "";
    int value = 0;

public:
    Item(const std::string& name, int value);
    std::string getName() const;
    int getValue() const;
    void display() const;
};

#endif