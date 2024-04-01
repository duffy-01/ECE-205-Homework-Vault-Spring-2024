#include<iostream>
#include<string>

using namespace std;

class Pizza
{
private:
  char size;
  char type;

  int pepperoni;
  int cheese;

public:

  Pizza(char s, char t, int p, int c) : size(s), type(t), pepperoni(p), cheese(c){}
  void set_size()
  {
    cout << "What size of pizza would you like? "
         << "Press l for large, m for medium, or s for small: ";
    cin >> size;
    if (size != 's' && size != 'm' && size != 'l' && size != 'S' && size != 'M' && size != 'L')
    {
      cout << "Invalid input, size set to small." << endl;
      size = 's';
    }
  }

  void set_type()
  {
    cout << "What type of pizza would you like? "
         << "Press d for deep dish, h for hand tossed, or p for pan: ";
    cin >> type;
    if (type != 'd' && type != 'h' && type != 'p' && type != 'D' && type != 'H' && type != 'P')
    {
      cout << "Invalid input, type set to hand tossed." << endl;
      type = 'h';
    }
  }

  void add_pepperoni()
  {
    cout << "How many pepperoni toppings would you like to add? ";
    cin >> pepperoni;
    if (pepperoni < 0)
    {
      pepperoni = 0;
      cout << "Pepperoni has reached critically low levels, setting to zero." << endl;
    }
  }

  void add_cheese()
  {
    cout << "How many cheese toppings would you like to add? ";
    cin >> cheese;
    if (cheese < 0)
    {
      cheese = 0;
      cout << "Cheese has reached critically low levels, setting to zero." << endl;
    }
  }
  
  string get_type() const
  {
    if (type == 'd' || type == 'D')
    {
      return "Deep Dish";
    }
    else if (type == 'h' || type == 'H')
    {
      return "Hand Tossed";
    }
    else if (type == 'p' || type == 'P')
    {
      return "Pan";
    }
    else
    {
      return "Invalid Type";
    }
  }
  
  string get_size() const
  {
    if (size == 's' || size == 'S')
    {
      return "Small";
    }
    else if (size == 'm' || size == 'M')
    {
      return "Medium";
    }
    else if (size == 'l' || size == 'L')
    {
      return "Large";
    }
    else
    {
      return "Invalid Size";
    }
  }
  
  int get_toppings() const
  {
    return pepperoni + cheese;
  }


  void output_description() const
  {
    cout << "Pizza: " << get_size() << " " << get_type() << " with " << get_toppings() << " toppings" << endl;
  }

  double compute_price() const
  {
    double price = 0;
    if (size == 's' || size == 'S')
    {
      price += 10.0;
    }
    else if (size == 'm' || size == 'M')
    {
      price += 14.0;
    }
    else if (size == 'l' || size == 'L')
    {
      price += 17.0;
    }
    
    price += get_toppings() * 2.0;

    cout << "Price: $" << price << endl;
  }
};