//  imperial to metric
#include<iostream>

double consolidate_imperial_oz(int pounds, int ounces)
{
  return (static_cast<double>(pounds) * 16.0) + static_cast<double>(ounces);
}

void imperial_to_metric(double totalOz, int &kilograms, int &grams)
{
  //  dimensional analysis says 1oz * 1lb/16oz * 1kg/2.2046lbs * 1000g/1kg -> conv. factor of 28.35g/oz
  grams = (totalOz * 28.35); 

  kilograms = grams / 1000;
  grams %= 1000; 

}

using namespace std;

int main()
{
  int pounds, ounces, kilograms, grams;
  char cont;

  do
  {
    cout << "Hello! I am a robot whose sole purpose is to convert from imperial weight to metric weight!" << endl;

    cout << "Please enter an integer weight in lbs: ";
    cin >> pounds;
    
    cout << "Please enter an integer weight in oz: ";
    cin >> ounces;

    imperial_to_metric(consolidate_imperial_oz(pounds, ounces), kilograms, grams);
    cout << pounds << "lb(s) " << ounces << "oz is equivalent to:" << endl;
    cout << kilograms << "kg(g) " << grams << "g" << endl;

    cout << "Would you like to convert another weight? [Y/n]: ";
    cin >> cont;
  } while (cont != 'n' && cont != 'N');

  return 0;
}
