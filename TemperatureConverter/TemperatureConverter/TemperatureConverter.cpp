#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> // Needed for setprecision

using namespace std;

int main() {
    ifstream inputFile("FahrenheitTemperature.txt");   // Open input file
    ofstream outputFile("CelsiusTemperature.txt");     // Create output file

    if (!inputFile) {
        cerr << "Error: Could not open input file.\n";
        return 1;
    }

    if (!outputFile) {
        cerr << "Error: Could not open output file.\n";
        return 1;
    }

    string city;
    int fahrenheit;
    double celsius;

    // Read each city and its temperature
    while (inputFile >> city >> fahrenheit) {
        // Convert to Celsius
        celsius = (fahrenheit - 32) * 5.0 / 9.0;

        // Write formatted output to the file
        outputFile << city << " " << fixed << setprecision(2) << celsius << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Temperature conversion complete. Check CelsiusTemperature.txt.\n";
    return 0;
}
