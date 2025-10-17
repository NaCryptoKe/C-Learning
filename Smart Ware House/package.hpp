#ifndef PACKAGE_HPP
#define PACKAGE_HPP

#include <string>

class Package {
private: 
    std::string name = "";
    int weight = 0;

public:
    Package(const std::string &name, int value);
    void display() const;
    std::string getName() const;
    ~Package();
};
#endif