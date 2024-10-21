// Jacobb L. Foster II CS210 Southern New Hampshire University

#include <iostream>
#include <iomanip>  // For formatting the output
using namespace std;

// Function to display report without monthly deposits
void displayReportWithoutDeposits(double initialInvestment, double annualInterest, int years) {
    double openingAmount = initialInvestment;
    double interestRatePerMonth = (annualInterest / 100) / 12;
    
    cout << "Balance and Interest Without Monthly Deposits" << endl;
    cout << "========================================================" << endl;
    cout << "Year\tYear End Balance\tYear End Earned Interest" << endl;
    cout << "--------------------------------------------------------" << endl;
    
    for (int year = 1; year <= years; year++) { // For loop to display yearly rates
        double totalInterestForYear = 0;
        for (int month = 1; month <= 12; month++) {
            double interest = openingAmount * interestRatePerMonth;
            double closingBalance = openingAmount + interest;
            openingAmount = closingBalance;
            totalInterestForYear += interest;
        }
        cout << setw(4) << year << "    $" << setw(10) << fixed << setprecision(2) << openingAmount << "          $" << setw(10) << totalInterestForYear << endl; // Format output to be fixed and iterate for each year
    }
}

// Function to display report with monthly deposits
void displayReportWithDeposits(double initialInvestment, double monthlyDeposit, double annualInterest, int years) {
    double openingAmount = initialInvestment;
    double interestRatePerMonth = (annualInterest / 100) / 12;
    
    cout << "Balance and Interest With Monthly Deposits" << endl;
    cout << "========================================================" << endl;
    cout << "Year\tYear End Balance\tYear End Earned Interest" << endl;
    cout << "--------------------------------------------------------" << endl;
    
    for (int year = 1; year <= years; year++) { // For loop to display yearly rates
        double totalInterestForYear = 0;
        for (int month = 1; month <= 12; month++) {
            double total = openingAmount + monthlyDeposit;
            double interest = total * interestRatePerMonth;
            double closingBalance = total + interest;
            openingAmount = closingBalance;
            totalInterestForYear += interest;
        }
        cout << setw(4) << year << "    $" << setw(10) << fixed << setprecision(2) << openingAmount << "          $" << setw(10) << totalInterestForYear << endl; // Format output to be fixed and iterate for each year
    }
}

int main() {
    double initialInvestment, monthlyDeposit, annualInterest;
    int years;
    char testAnotherAmount;

    // Home page
    cout << "*****************************" << endl;
    cout << "Welcome to Airgead Banking" << endl;
    cout << "*****************************" << endl;
    cout << "Initial Investment Amount: $";
    cin >> initialInvestment;
    cout << "Monthly Deposit: $";
    cin >> monthlyDeposit;
    cout << "Annual Interest Rate: %";
    cin >> annualInterest;
    cout << "Number of Years: ";
    cin >> years;

    // Display reports
    displayReportWithoutDeposits(initialInvestment, annualInterest, years);
    displayReportWithDeposits(initialInvestment, monthlyDeposit, annualInterest, years);

    // Allow user to test another set of values
    do {
        cout << "\nTest another amount? (y/n): ";
        cin >> testAnotherAmount;

        if (testAnotherAmount == 'y' || testAnotherAmount == 'Y') {
            cout << "New Monthly Deposit Amount: $";
            cin >> monthlyDeposit;
            cout << "New Interest Rate: %";
            cin >> annualInterest;
            cout << "New Length of Time (Years): ";
            cin >> years;

            // Display updated reports
            displayReportWithoutDeposits(initialInvestment, annualInterest, years);
            displayReportWithDeposits(initialInvestment, monthlyDeposit, annualInterest, years);
        }

    } while (testAnotherAmount == 'y' || testAnotherAmount == 'Y'); // Edge case for capitol char

    return 0;
}
