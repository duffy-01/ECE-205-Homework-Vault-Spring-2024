#include <iostream>
#include <time.h>
#include <cstdlib> 
#include <bits/stdc++.h>
#include <ctime> 

using namespace std;

double min(double arr[], int n)
{
  return *min_element(arr, arr + n);
}

double max(double arr[], int n)
{
  return *min_element(arr, arr + n);
}

int main()
  {
  double difficulty;
  double scores[7];
  double maxScore, minScore, totalSum;
  double finalScore;

  srand(time(0));

  cout << "Please enter the difficulty of the dive: " << endl;
  cin >> difficulty;
  
  
  if (difficulty < 1.2 || difficulty > 3.8)
    {
      cerr << "Please enter a valid difficulty." << endl;
      abort();
    }
  difficulty *= 0.6;
  
  for (int i = 0; i < 7; ++i)
    {
    scores[i] = (double) rand()/RAND_MAX * 10;
    cout << "Score " << i+1 << ": " <<scores[i] << endl;
    }
  
  int n = 7;

  for (int i = 0; i < 7; ++i)
    {
    totalSum += scores[i]; 
    }

  totalSum -= (min(scores, n) + max(scores, n));

  finalScore = (totalSum) * difficulty;
  cout << "Final Score: " << finalScore;
  return 0;
  }