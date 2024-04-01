#include<iostream>

using namespace std;

int main()
{
  int startTime, endTime;
  
  cout << "Please enter your start time (24hr, HHmm): ";
  cin >> startTime;

  cout << "Please enter your end time (24hr, HHmm): ";
  cin >> endTime;

  int startMinutes = (startTime / 100) * 60 + (startTime % 100);
  int endMinutes = (endTime / 100) * 60 + (endTime % 100);

  //    if the end time is smaller than the start time, we'll need to assume that it is on the next day
  if (endTime < startTime)
  {
    endMinutes += 1440; //  1440 = 24*60
  }

  int timeDifference = endMinutes - startMinutes;
  cout << "The time difference in minutes is: " << timeDifference << " minutes.";

  return 0;
}