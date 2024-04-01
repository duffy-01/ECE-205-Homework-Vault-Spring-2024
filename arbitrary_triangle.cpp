// arbitrary triangle area

#include <iostream>
#include <cmath>

bool triangle_validity(double a, double b, double c)
{
  // valid if a + b > c, b + c > a, and c + a > b
  if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a)
  {
    return false;
  }
  else
  {
    return true;
}}

void triangle_area(double a, double b, double c, double &perimeter, double &area)
{
  if (triangle_validity(a, b, c))
  {
    perimeter = a + b + c;
    double s = perimeter / 2.0; //  semiperimeter = s

    area = sqrt(s*(s-a)*(s-b)*(s-c));
    
    std::cout << "Area = " << area << " square units" << std::endl;
  
  }
  
  else
  {
    std::cout << "Invalid side lengths violate triangle inequality theorem, or are less than zero. Please enter a valid input." << std::endl;
}}

int main()
{
  double a, b, c, perimeter, area;

  std::cout << "Hello! I am a robot with only one function: calculating triangle area!\n" 
            << "Please note that the provided side lengths should be greater than zero and accommodate the triangle inequality theorem.\n"
            << "Please enter the side lengths of the triangle: " << std::endl;
  std::cin >> a >> b >> c;

  triangle_area(a, b, c, perimeter, area);

  return 0;
}