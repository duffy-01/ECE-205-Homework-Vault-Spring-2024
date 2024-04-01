#include <iostream>

class BikeSpeedometer
{
private:
  double distance;
  double time;

public:
  void set_distance(double d)
  {
    if (d >= 0)
    {
      distance = d;
    }
    else
    {
      distance = 0;
      std::cout << "Invalid distance, automatically set to zero." << std::endl;
   }}
  
  void set_time(double t)
  {
    if (t >= 0)
    {
      time = t;
    }
    else
    {
      time = 0;
      std::cout << "Invalid time, automatically set to zero" << std::endl;
  }}

  double average_speed() const
  {
    if (time != 0)
    {
      return (distance / time) * 60.0; //   miles/minute * 60min/hr = miles/hr
    }
    else
    {
      return 0;
}}};

using namespace std;

int main()
{
  double distance, time;
  char cont;

  do
  {
    BikeSpeedometer myTrip;

    cout << "Please enter the distance you travelled in miles: ";
    cin >> distance;
    
    cout << "Please enter your travel time in minutes: ";
    cin >> time;

    myTrip.set_distance(distance);
    myTrip.set_time(time);

    cout << "Trip average speed: " << myTrip.average_speed() << " mph.";
    
    cout << "Would you like to calculate average speed for another ride? [Y/n]: ";
    cin >> cont;

  } while (cont != 'n' && cont != 'N');

  return 0;
}

