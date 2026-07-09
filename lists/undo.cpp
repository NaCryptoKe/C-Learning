/*
 * This a basic undo/redo engine utilizing list.
 * Only for learning purposes, which will have 4 commands
 * Print history, Add text, Undo and Redo
 */
#include <iostream>
#include <list>
#include <string>
#include <limits>

void print_history (const std::list <std::string>& history);
void undo (std::list <std::string>& history, std::list <std::string>& redo_history);
void redo (std::list <std::string>& history, std::list <std::string>& redo_history);
void add (std::list <std::string>& history, std::list <std::string>& redo_history, std::string val);

int main() {
    std::list<std::string> history;
    std::list<std::string> redo_history;

        int option;
        std::cout << "1. Add\n2. Undo\n3. Redo\n4. Print History\n5. Quit\n";
        std::cout << "Enter an option (1-5): ";

        if (!(std::cin >> option)) {
            std::cout << "Invalid input! Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cin.ignore();

        switch (option) {
        case 1: {
            std::string val;
            std::getline(std::cin, val);
            add(history, redo_history, std::move(val));
                }
            break;
        case 2:
            undo(history, redo_history);
            break;
        case 3:
            redo(history, redo_history);
            break;
        case 4:
            print_history(history);
            break;
        case 5:
            return 0;
        default:
            std::cout << "Invalid option\n";
            break;
        }
}

void undo (std::list <std::string>& history, std::list <std::string>& redo_history) {
    if (history.empty()) return;    // Invariant 1: Empty history can't be processed
    redo_history.splice(redo_history.end(), history, std::prev(history.end()));
}

void redo (std::list <std::string>& history, std::list <std::string>& redo_history) {
    if (redo_history.empty()) return;    // Invariant 1: Empty redo history can't be processed
    history.splice(history.end(), redo_history, std::prev(redo_history.end()));
}

void add (std::list <std::string>& history, std::list <std::string>& redo_history, std::string val) {
    history.push_back(std::move(val));
    redo_history.clear();
}

void print_history(const std::list <std::string>& history) {
    for (auto i: history)   std::cout << i << "\n";
}
