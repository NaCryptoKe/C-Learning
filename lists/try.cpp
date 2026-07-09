/*
 * Thursday 9, July 2026
 * In C++, a list refers to the std::list, which is a sequence container
 * implemented as a doubly linked-list
 *
 * Unlike vectors, lists store elements in non-contigous memory location
 * They offer a constant-time O(1) insertion and removal from anywhere in
 * the container
 */

#include <iostream>
#include <list>     // Required header for list

int main(void) {
    // Declaration
    /*
     * When declaring we use the following format:
     * std::list<data type (even struct and classes)> name;
     */
    std::list<int> numbers;

    // Declaration with initialization
    std::list<std::string> cars = {"Volvo", "BMW", "Ford"};

    return 0;
}
