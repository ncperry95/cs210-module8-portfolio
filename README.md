# CS 210 Module Eight Portfolio

Welcome to my CS 210 Module Eight portfolio entry! This repository contains my C++ project and my reflective journal responses for Module Eight.

## Table of Contents

- [Project One Clock Perry](#project-one-clock-perry)  
- [Journal Reflection](#journal-reflection)  
  - [1. Project Summary](#1-project-summary)  
  - [2. What I Did Particularly Well](#2-what-i-did-particularly-well)  
  - [3. Potential Enhancements](#3-potential-enhancements)  
  - [4. Most Challenging Pieces & How I Overcame Them](#4-most-challenging-pieces--how-i-overcame-them)  
  - [5. Transferable Skills](#5-transferable-skills)  
  - [6. Maintainability, Readability, and Adaptability](#6-maintainability-readability-and-adaptability)  

---

## Project One Clock Perry

This folder contains a C++ console application that simulates two clocks—one 12-hour clock and one 24-hour clock—running in parallel. Users can:

- View the current time on both clocks.  
- Add hours, minutes, or seconds to **either** clock via a simple text menu.  
- See time roll over correctly (e.g., 12 → 1 PM, 23 → 0).  

**Why this matters:**  
In many scheduling or logging systems, you need to work with both civilian (12 hr) and military (24 hr) time formats. This project solidifies understanding of object-oriented design, operator overloading, and robust time arithmetic in C++.

> **Open the project folder:**  
> `ProjectOneClockPerry/`

---

## Journal Reflection

### 1. Project Summary  
I built a dual-clock simulator in C++ that maintains both a 12-hour clock and a 24-hour clock. Users interact via a text menu to add hours, minutes, or seconds to either clock and observe proper rollover behavior. This solved the problem of practicing time arithmetic across two common time formats while reinforcing core C++ concepts.

### 2. What I Did Particularly Well  
- **Modular Design:** I encapsulated each clock in its own class (`Clock12` and `Clock24`), keeping responsibilities clear.  
- **Clean Interfaces:** Public methods like `addHours()`, `addMinutes()`, and `addSeconds()` make the API intuitive.  
- **Documentation:** I used Doxygen-style comments and a concise `README.md` so future readers (or employers) can jump in immediately.

### 3. Potential Enhancements  
- **Input Validation & Exception Handling:** Right now, non-numeric input could crash the program. Wrapping `std::cin` reads in `try/catch` blocks would make it more robust.  
- **Unit Tests:** Integrating a testing framework (e.g., Google Test) would let me verify rollover logic automatically.  
- **Logging & Persistence:** Adding file-based logging of time changes and allowing the user to save/restore clock state would make the program more production-ready.

### 4. Most Challenging Pieces & How I Overcame Them  
- **Rollover Logic:** Calculating when seconds or minutes exceeded their bounds took careful modulo arithmetic. I sketched out timeline diagrams on paper before coding to visualize each edge case.  
- **Operator Overloading:** Overloading the stream insertion operator (`operator<<`) for clean output required reading several C++ reference articles. StackOverflow and the C++ Primer textbook were invaluable resources.

### 5. Transferable Skills  
- **Object-Oriented Design:** Defining clear classes and interfaces will apply directly to GUI apps, networked services, or game engines.  
- **Exception Safety & Error Handling:** Learning to anticipate bad input is essential in almost any software context.  
- **Debugging & Testing Mindset:** Breaking down problems, drawing diagrams, and writing small test harnesses scales to larger codebases.

### 6. Maintainability, Readability, and Adaptability  
- **Meaningful Names & Comments:** Every class, method, and variable has a descriptive name and a short comment explaining its purpose.  
- **Separation of Concerns:** UI/menu code lives in `main.cpp`, while time logic stays in `Clock12.cpp/.h` and `Clock24.cpp/.h`.  
- **Scalable Architecture:** I could easily extend this to a third clock format (e.g., UNIX timestamp) by adding another class that implements the same interface.

---

Thank you for reviewing my work! Feel free to explore the source in the `ProjectOneClockPerry/` folder and reach out if you have any questions.  
