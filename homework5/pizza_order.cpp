#include "pizza.h"
#include<vector>
#pragma once

/*
README README README README README README README README README
THIS IS ASSUMING YOU INCLUDE THE "pizza.h" WITH STD & HEADERS!
README README README README README README README README README
*/

class Order
{
private:
  vector<Pizza> pizzas;

public:
  void order_pizza(const Pizza &newPizza)
  {
    pizzas.push_back(newPizza);
  }

  void order_review() const
  {
    cout << "Your order:" << endl;
    double total = 0.00;

    for (const auto &pizza : pizzas)
    {
        pizza.output_description();
        total += pizza.compute_price();
    }
    cout << "Your total is $" << total << endl;
  }
};

int main() {
    Order myOrder;
    myOrder.order_pizza(Pizza('s', 'd', 1, 0)); // Small Deep Dish with 1 topping
    myOrder.order_pizza(Pizza('m', 'h', 0, 2)); // Medium Hand Tossed with 2 toppings
    myOrder.order_pizza(Pizza('l', 'p', 2, 1)); // Large Pan with 3 toppings

    myOrder.order_review();

    return 0;
}