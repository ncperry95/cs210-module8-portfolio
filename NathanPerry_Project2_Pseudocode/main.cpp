#include "Investment.h"
#include <iostream>

int main() {
    double initAmount, monthlyDep, annualInt;
    int years;

    std::cout << "Welcome to Airgead Banking Investment Calculator\n\n";

    // Input
    std::cout << "Initial Investment Amount: $";
    std::cin >> initAmount;
    std::cout << "Monthly Deposit: $";
    std::cin >> monthlyDep;
    std::cout << "Annual Interest: %";
    std::cin >> annualInt;
    std::cout << "Number of Years: ";
    std::cin >> years;

    // Validate input
    if (initAmount < 0 || monthlyDep < 0 || annualInt < 0 || years <= 0) {
        std::cout << "Invalid input. Please enter positive values.\n";
        return 1;
    }

    // Create investment object and show results
    Investment investment(initAmount, monthlyDep, annualInt, years);
    investment.displayWithoutMonthlyDeposit();
    investment.displayWithMonthlyDeposit();

    return 0;
}
