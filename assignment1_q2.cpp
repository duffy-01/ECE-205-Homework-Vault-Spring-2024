#include <iostream>
#include<cmath>
#include <windows.h>  
#include <stdlib.h>

// rate = $36.75/hr up to 40 hrs, overtime is 1.5x hourly
// 6% SS, 15% federal income, 4% state, 1% Bethlehem
// $20 union dues, 2+ dependents = $40 health insurance

int main() {

    float hourlyRate = 36.75;       //  here's the wage

    float federalTaxRate = 0.15;    //  this block of variables is devoted to all taxes/fees
    float stateTaxRate = 0.04;
    float cityTaxRate = 0.01;
    float socialSecurityRate = 0.06;
    float unionDues = 20.00;

    int hoursWorked;                //  this block of variables is devoted to all user input data
    int dependents;

    //  user input of dependents and hours worked
    std::cout << "Please enter number of hours worked:\n";
    std::cin >> hoursWorked;
    std::cout << "Please enter number of dependents:\n";
    std::cin >> dependents;

    std::cout << "According to your input, you worked " <<hoursWorked<<" hours and have " << dependents << " dependents.\n";

    //determining gross income before taxes and fees
    float grossIncome;

    if (hoursWorked > 40){
        grossIncome = (40*hourlyRate) + 1.5*(hoursWorked-40)*hourlyRate;
    }
    else if (0 < hoursWorked <= 40){
        grossIncome = hoursWorked * hourlyRate;  
    }
    else if (hoursWorked < 0){
        std::cerr << "Please enter a valid number of working hours.\n";
    }
    else{
        std::cerr << "Exception: Fatal error in hours worked\n";
    }

    //  determining magnitude of taxes and fees
    float insuranceCost;    //  health insurance cost due to dependents
    
    if (dependents > 1){
        insuranceCost = 20.00;
    }
    else if(dependents = 1){
        insuranceCost = 0.00;
    }
    else{
        std::cerr << "Exception: Fatal error in dependents\n";
    }

    //  all "percentage-based" taxes
    float federalTax = grossIncome * federalTaxRate;            //  federal tax
    float stateTax = grossIncome * stateTaxRate;                // state tax
    float cityTax = grossIncome * cityTaxRate;                  //  city tax
    float socialSecurity = grossIncome * socialSecurityRate;    //  social sec. 

    float taxesAndFees = federalTax + stateTax + cityTax + socialSecurity + unionDues + insuranceCost;
    
    //  calculating net income :)
    float netIncome = grossIncome - taxesAndFees;  

    //time to ouput everything!
    std::cout << std::fixed;
    std::cout.precision(2);
    
    std::cout << "Gross Income:" << grossIncome << "\n";

    std::cout << "Federal Tax:" << federalTax << "\n";
    std::cout << "State Tax:" << stateTax << "\n";
    std::cout << "City Tax:" << cityTax << "\n";
    std::cout << "Social Security:" << socialSecurity << "\n";
    std::cout << "Health Insurance:" << insuranceCost << "\n";
    std::cout << "Union Dues:" << grossIncome << "\n";

    std::cout << "Net Income:" << netIncome << "\n";

    return 0; //successful execution return zero
}