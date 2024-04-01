//  24->12hr notation
#include<iostream>

void convert24_12(int &h, char &meridiem)
{
  if (h >= 12)
  {
    meridiem = 'P';
    
    if (h > 12)
    {
      h -= 12;
    }
  }
  
  else
  {
    meridiem = 'A';
    if (h == 0)
    {
      h = 12;
}}}

using namespace std;

int main()
{
  int hours, minutes;
  char meridiem, cont;
 
  do
  {
    cout << "Hello! Please enter a time in 24-hour notation (HH then mm): ";
    cin >> hours >> minutes;

    convert24_12(hours, meridiem);

    cout << "Your time in 12-hr notation is: " << hours << ":" <<
            (minutes < 10 ? "0" : "") << minutes << " " << meridiem << "M" << endl;
    
    cout << "Would you like to convert another time? [Y/n]: ";
    cin >> cont;

  } while (cont != 'n' && cont != 'N');

  return 0;
}
