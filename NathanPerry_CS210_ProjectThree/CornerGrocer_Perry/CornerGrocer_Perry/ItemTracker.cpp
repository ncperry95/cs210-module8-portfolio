#include "ItemTracker.h"
#include <iostream>
#include <fstream>
#include <iomanip>

ItemTracker::ItemTracker(const std::string& inputFile, const std::string& outputFile) {
    LoadItems(inputFile);
    SaveFrequencies(outputFile);
}

void ItemTracker::LoadItems(const std::string& filename) {
    std::ifstream inFile(filename);
    std::string item;

    if (!inFile) {
        std::cerr << "Error opening input file.\n";
        return;
    }

    while (inFile >> item) {
        ++itemFrequency[item];
    }

    inFile.close();
}

void ItemTracker::SaveFrequencies(const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error creating frequency file.\n";
        return;
    }

    for (const auto& pair : itemFrequency) {
        outFile << pair.first << " " << pair.second << "\n";
    }

    outFile.close();
}

int ItemTracker::GetItemFrequency(const std::string& item) const {
    auto it = itemFrequency.find(item);
    return (it != itemFrequency.end()) ? it->second : 0;
}

void ItemTracker::PrintFrequencies() const {
    for (const auto& pair : itemFrequency) {
        std::cout << std::setw(15) << std::left << pair.first << " " << pair.second << "\n";
    }
}

void ItemTracker::PrintHistogram() const {
    for (const auto& pair : itemFrequency) {
        std::cout << std::setw(15) << std::left << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}
