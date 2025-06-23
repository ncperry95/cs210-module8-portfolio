#ifndef INVESTMENT_H
#define INVESTMENT_H

class Investment {
private:
    double initialInvestment;
    double monthlyDeposit;
    double annualInterest;
    int numYears;

public:
    Investment(double initInvest, double monthDep, double annualInt, int years);

    void displayWithoutMonthlyDeposit() const;
    void displayWithMonthlyDeposit() const;
};

#endif
