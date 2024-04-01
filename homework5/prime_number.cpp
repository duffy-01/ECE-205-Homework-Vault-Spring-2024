//  prime number class
#include <iostream>

class PrimeNumber
{
private:
  int myPrime;

public:
  //    default constructor and constructor via parameter
  PrimeNumber() : myPrime(1){}

  PrimeNumber(int myNum) : myPrime(myNum)
  {
    if (!prime_check(myNum))
    {
      myPrime = 1;
      std::cout << "Number is not prime. Automatically set to 1." << std::endl;
    }
  }
  
  //    other needed functions like returning prime and checking prime status
  int return_prime() const
  {
    return myPrime;
  }

  bool prime_check(int myNum) const
  {
    if (myNum <= 1)
    {
      return false;
    }
    for (int i = 2; i*i <= myNum; ++i)
    {
      if (myNum % i == 0)
      {
        return false;
      }
    }
    return true;
  }

/*    
now for the fun of creating prefix/postfix increment/decrement operators
starting with prefix increment/decrement 
*/

  PrimeNumber &operator++()
  {
    do
    {
      ++myPrime;    //  increment up
    } while (!prime_check(myPrime));
    return *this;
  }

  PrimeNumber &operator--()
  {
    do
    {
      --myPrime;    //  increment down
    } while (!prime_check(myPrime));
    return *this;
  }

/*    
finishing with postfix increment/decrement
boy I wish this was a header file
*/

  PrimeNumber operator++(int)
  {
    PrimeNumber num = *this;
    ++(*this);
    return num;
  }

  PrimeNumber operator--(int)
  {
    PrimeNumber num = *this;
    --(*this);
    return num;
  }
};

//  now lets put it all together!

using namespace std;

int main()
{
  PrimeNumber myFirstNum(7);
  cout << "First num = " << myFirstNum.return_prime() << endl;
  
  PrimeNumber mySecondNum = ++myFirstNum;
  cout << "Second num = " << mySecondNum.return_prime() << endl;

  PrimeNumber myThirdNum = --myFirstNum;
  cout << "Third num = " << myThirdNum.return_prime() << endl;

  PrimeNumber myFourthNum = myFirstNum++;
  cout << "Second num = " << myFourthNum.return_prime() << endl;

  PrimeNumber myFifthNum = myFirstNum--;
  cout << "Third num = " << myFifthNum.return_prime() << endl;
}

