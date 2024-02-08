#include <iostream>
#include<cmath>

//  seconds to hrs, mins, secs.0000
//  seconds to hrs.0000 and mins.0000

int main() {
    //  declaring seconds in
    float secondsIn;

    //  user input of seconds, with confirmation (for debugging early on)
    std::cout << "Please enter number of seconds:";
    std::cin >> secondsIn;
    std::cout << "Number of seconds entered: "<< secondsIn << "\n";

    //  all whole integer values being calculated (1st part of assignment)
    int secondsInteger = secondsIn;
    int minutesOutInteger = (secondsInteger / 60) % 60;
    int hoursOutInteger = secondsInteger / 3600;

    //  all double values being calculated
    double hoursOutDouble = secondsIn / 3600;
    double minutesOutDouble = secondsIn / 60;
    double secondsOutDouble = fmod(secondsIn, 60);  //  fmod from cmath used to modulus a floating point number 

    //  holding decimal point in "fixed position, and setting precision to 4 places"
    std::cout << std::fixed;
    std::cout.precision(4);

    //  printing everything out
    std::cout << "The number of seconds entered is equivalent to: " <<hoursOutInteger<< " hours, " << minutesOutInteger << " minutes, and " << secondsOutDouble << " seconds.\n";
    std::cout << "This is also equivalent to: "<< hoursOutDouble << " hours or " << minutesOutDouble << " minutes.\n";

    return 0; //successful execution return zero
}