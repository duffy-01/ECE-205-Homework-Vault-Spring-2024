#include<iostream>
#include<sstream>
#include<stack>
#include<string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <cstdlib>

std::string convert_to_rpn(const std::string& infix)
{
  const std::string operators = "+-*/";
  
  std::stringstream myStream;
  std::stack<int> myStack;

  std::stringstream input(infix);
  std::string token;

  while (std::getline(input, token,' '))
  {
    if(token.empty())
    {
      continue;
    }

    char c = token[0];
    size_t idx = operators.find(c);

    if (idx != std::string::npos)
    {
      while (!myStack.empty())
      {
        int prec2 = myStack.top() / 2;
        int prec1 = idx / 2;

        if (prec2 > prec1 || (prec2 == prec1 &&c != '^'))
        {
          myStream << operators[myStack.top()] << ' ';
          myStack.pop();
        }
        else break;
      }
      myStack.push(idx);
    }
    
    else if (c == '(')
    {
        myStack.push(-2);
    }
    
    else if(c == ')')
    {
      while (myStack.top() != -2)
      {
      myStream << operators[myStack.top()] << ' ';
      myStack.pop();
      }
      myStack.pop();
    }
    
    else
    {
        myStream << token << ' ';
    }
  }

  while (!myStack.empty())
  {
    myStream << operators[myStack.top()] << ' ';
    myStack.pop();
  }
  
  return myStream.str();
}

double calculate_rpn(const std::string& rpn)
{
  std::istringstream iss(rpn);
  std::vector<double> myStack;
  std::cout << "Input\tOperation\tStack after" << std::endl;
  std::string token;

  while (iss > token)
  {
    std::cout << token << "\t";
    double tokenNum;
    if (std::istringstream(token) >> tokenNum)
    {
      std:cout << "Push\t\t";
      std.push_back(tokenNum)
    }
    
    else
    {
      std::cout << "Operate\t\t";
      double secondOperand = myStack.back();
      myStack.pop_back();
      double firstOperand = myStack.back();
      myStack.pop_back();

      if (token == "*")
      {
        myStack.push_back(firstOperand * secondOperand);
      }
      else if (token == "/")
      {
        myStack.push_back(firstOperand / secondOperand);
      }
      else if (token == "-")
      {
        myStack.push_back(firstOperand - secondOperand);
      }
      else if (token == "+")
      {
        myStack.push_back(firstOperand + secondOperand);
      }
      else if (token == "^")
      {
        myStack.push_back(std::pow(firstOperand , secondOperand));
      }
      else
      {
        std::err << "Operator Parsing Error" << std::endl;
        std::exit(1);
      }
    }
    std::copy(myStack.begin(), myStack.end(), std::ostream_iterator<double>(std::cout, " "))
  }
  return myStack.back();
}



int main()
{
  std::string infix = "3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3";
  std::cout << "infix:   " << infix << '\n';
  std::cout << "postfix: " << convert_to_rpn(infix) << '\n';
std::cout << "Final answer: " << evaluate_rpn(convert_to_rpn(infix)) << std::endl;
return 0;
}