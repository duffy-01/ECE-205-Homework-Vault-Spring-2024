#include <stdlib.h>
#include <iostream>
#include<iomanip>

using namespace std;
//  before the main(), here's a template for a line by line table generator. This will streamline later printing of the table.
template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
void print_row(std::ostream& os, T0 const& t0, T1 const& t1, T2 const& t2, T3 const& t3, T4 const& t4, T5 const& t5) {
    os  << std::setw(7) << t0 << std::setw(17) << t1 << std::setw(16) << t2
        << std::setw(14) << t3 << std::setw(20) << t4 << std::setw(15) << t5 << '\n';
    }

int main() {
    //  all of the variables in this block will be based on user input
    float loanAmount;
    float monthlyPayment;
    float yearlyInterest;
    
    
    //  all of the values here will be changing as the loop "does it's thing"
    int month = 0;
    float principal;
    float interestMonth;
    float totalPaid = 0.00;
    float totalInterest = 0.00;
    

    //  user input of loan amount, planned monthly payment, and yearly interest with confirmation (for debugging early on)
    cout << "What is the Amount of the loan?\n";
    cin >> loanAmount;
    cout << "What is interest rate of the loan? Please enter the decimal value. e.g. 18.0, 5.0, 4.99\n";
    cin >> yearlyInterest;
    cout << "What is your planned monthly payment?\n";
    cin >> monthlyPayment;

    //  here's a block of variables dependent on the user input.
    float monthlyInterest = yearlyInterest / 1200; 
    float balance = loanAmount;

    print_row(cout, "Month(#)", "Interest", "Principal", "Balance", "Total Interest", "Total Paid");
    //  I ended up using a while loop because if statement caused scoping issues. 
    
    std::cout << std::fixed;
    std::cout.precision(2);
    
    while (balance > 0)
    {
        month += 1;
        totalPaid += monthlyPayment;
        interestMonth = monthlyInterest * balance;
        principal = monthlyPayment - interestMonth;
        balance -= principal;
        totalInterest += interestMonth;

        print_row(cout, month, interestMonth, principal, balance, totalInterest, totalPaid);

    }

    cout << "It would take " << month << " months to pay off your loan. The last month would cost $" << monthlyPayment + balance;
     
}