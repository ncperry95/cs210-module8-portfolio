#include "ItemTracker.h"
#include <iostream>
#include <string>
#include <sstream>

void DisplayMenu() {
    std::cout << "\n======= Corner Grocer Tracker =======\n";
    std::cout << "1. Lookup frequency of a specific item\n";
    std::cout << "2. Show all item frequencies\n";
    std::cout << "3. Display histogram\n";
    std::cout << "4. Exit\n";
    std::cout << "Select an option: ";
}

int main() {
    ItemTracker tracker("CS210_Project_Three_Input_File.txt", "frequency.dat");

    int choice = 0;
    std::string input;
    std::string item;

    while (true) {
        DisplayMenu();
        std::getline(std::cin, input);
        std::stringstream ss(input);

        // Validate menu choice is an integer between 1 and 4
        if (!(ss >> choice) || choice < 1 || choice > 4) {
            std::cout << "Invalid input. Please enter a number between 1 and 4.\n";
            continue;
        }

        switch (choice) {
        case 1:
            std::cout << "Enter item name: ";
            std::getline(std::cin, item);

            if (item.empty()) {
                std::cout << "Item name cannot be empty.\n";
            }
            else {
                std::cout << item << " was purchased " << tracker.GetItemFrequency(item) << " times.\n";
            }
            break;

        case 2:
            tracker.PrintFrequencies();
            break;

        case 3:
            tracker.PrintHistogram();
            break;

        case 4:
            std::cout << "Exiting program.\n";
            return 0;
        }
    }

    return 0;
}
