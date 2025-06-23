#include "Investment.h"
#include <iostream>
#include <iomanip>
#include <cmath>

Investment::Investment(double initInvest, double monthDep, double annualInt, int years) {
    initialInvestment = initInvest;
    monthlyDeposit = monthDep;
    annualInterest = annualInt;
    numYears = years;
}

void Investment::displayWithoutMonthlyDeposit() const {
    double total = initialInvestment;
    std::cout << "\nYear\tYear End Balance\tInterest Earned\n";
    std::cout << "--------------------------------------------------\n";
    for (int i = 1; i <= numYears; i++) {
        double interest = total * (annualInterest / 100);
        total += interest;
        std::cout << i << "\t$" << std::fixed << std::setprecision(2)
            << total << "\t\t$" << interest << "\n";
    }
}

void Investment::displayWithMonthlyDeposit() const {
    double total = initialInvestment;
    std::cout << "\nYear\tYear End Balance\tInterest Earned\n";
    std::cout << "--------------------------------------------------\n";
    for (int i = 1; i <= numYears; i++) {
        double yearlyInterest = 0;
        for (int j = 0; j < 12; j++) {
            total += monthlyDeposit;
            double monthlyInterest = total * ((annualInterest / 100) / 12);
            yearlyInterest += monthlyInterest;
            total += monthlyInterest;
        }
        std::cout << i << "\t$" << std::fixed << std::setprecision(2)
            << total << "\t\t$" << yearlyInterest << "\n";
    }
}
