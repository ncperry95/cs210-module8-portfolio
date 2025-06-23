#ifndef ITEMTRACKER_H
#define ITEMTRACKER_H

#include <string>
#include <map>

class ItemTracker {
private:
    std::map<std::string, int> itemFrequency;
    void LoadItems(const std::string& filename);
    void SaveFrequencies(const std::string& filename);

public:
    ItemTracker(const std::string& inputFile, const std::string& outputFile);
    int GetItemFrequency(const std::string& item) const;
    void PrintFrequencies() const;
    void PrintHistogram() const;
};

#endif
