// Author: Nathan Perry
// CS 210 - Project One: Chada Tech Clocks
// This program simulates dual 12-hour and 24-hour clocks with interactive menu options.

#include <iostream>
#include <iomanip>  // for setw and setfill
#include <string>
using namespace std;

// Clock class to store and manipulate time
class Clock {
private:
    int hour;
    int minute;
    int second;

public:
    // Constructor to initialize time
    Clock(int h = 0, int m = 0, int s = 0) {
        hour = h;
        minute = m;
        second = s;
    }

    // Add 1 hour, with rollover at 24
    void addHour() {
        hour = (hour + 1) % 24;
    }

    // Add 1 minute, and handle rollover into hour
    void addMinute() {
        minute++;
        if (minute >= 60) {
            minute = 0;
            addHour();
        }
    }

    // Add 1 second, and handle rollover into minute
    void addSecond() {
        second++;
        if (second >= 60) {
            second = 0;
            addMinute();
        }
    }

    // Display both 12-hour and 24-hour clocks side by side
    void displayClocks() {
        // Compute 12-hour values
        int displayHour = hour % 12;
        if (displayHour == 0) displayHour = 12;
        string period = (hour >= 12) ? "PM" : "AM";

        // Clock headers
        cout << "**************************     **************************" << endl;
        cout << "*     12-Hour Clock      *     *     24-Hour Clock      *" << endl;
        cout << "*     ";

        // 12-hour time
        cout << setw(2) << setfill('0') << displayHour << ":"
            << setw(2) << setfill('0') << minute << ":"
            << setw(2) << setfill('0') << second << " " << period
            << "      *     *     ";

        // 24-hour time
        cout << setw(2) << setfill('0') << hour << ":"
            << setw(2) << setfill('0') << minute << ":"
            << setw(2) << setfill('0') << second << "          *" << endl;

        cout << "**************************     **************************" << endl;
    }
};

// Prints the user menu
void printMenu() {
    cout << "\n**************************" << endl;
    cout << "* 1 - Add One Hour       *" << endl;
    cout << "* 2 - Add One Minute     *" << endl;
    cout << "* 3 - Add One Second     *" << endl;
    cout << "* 4 - Exit Program       *" << endl;
    cout << "**************************" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int h, m, s;

    // Get initial time from user
    cout << "Enter starting hour (0-23): ";
    cin >> h;
    cout << "Enter starting minute (0-59): ";
    cin >> m;
    cout << "Enter starting second (0-59): ";
    cin >> s;

    // Create clock object
    Clock myClock(h, m, s);
    int choice;

    // Menu loop
    do {
#ifdef _WIN32
        system("cls");  // Clear screen on Windows
#else
        system("clear");  // Clear screen on Unix/Linux/Mac
#endif
        myClock.displayClocks();
        printMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            myClock.addHour();
            break;
        case 2:
            myClock.addMinute();
            break;
        case 3:
            myClock.addSecond();
            break;
        case 4:
            cout << "\nExiting program. Goodbye!" << endl;
            break;
        default:
            cout << "\nInvalid input. Please choose 1-4." << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
