#include <iostream>
//  hat size = 2.9(weight) / height (in.)
//  jacket size = (height * weight / 288) , if over 30, + 1/8  for every 10 years over 30
//  waist size = (weight / 5.7) , if over 28 + 1/10 for every 2 years over 28

using namespace std;

int main() {
    double weightLbs;
    double heightIn;
    double ageYr;

    cout << std::fixed;
    cout.precision(1);

    cout << "Welcome to V-tailor. We will attempt to approximate the best hat, jacket, and waist sizing." << endl;
    cout << "Please input your weight in pounds: " << endl;
    cin >> weightLbs;


    cout << "Please input your height in inches: " << endl;
    cin >> heightIn;

    cout << "Please input your age in years: " << endl;
    cin >> ageYr;

    //  hat size
    double hatSize = (2.9 * weightLbs) / heightIn;
    cout << "Your hat size is: " << hatSize << endl;

    //  jacket size
    double jacketSize = (heightIn * weightLbs) / 288;

        if (ageYr > 30)
        {
            int sizeAdj1 = (ageYr - 30) / 10;
            jacketSize += (sizeAdj1 * (0.125));
        }

    cout << "Your jacket size is: " << jacketSize << endl;

    //  waist size
    double waistSize = weightLbs / 5.7;

        if (ageYr > 30)
        {
            int sizeAdj2 = (ageYr - 28) / 2;
            waistSize += (sizeAdj2 * (0.1));
        }

    cout << "Your waist size is: " << waistSize << endl;

    return 0;
}