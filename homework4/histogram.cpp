#include <iostream>
#include <algorithm>

using namespace std;

int* create_histogram(int arraySize, int* numbers)
{
  int maxNumber = *max_element(numbers, numbers + arraySize);
  int numberOfBins = (maxNumber / 10) + 1;
  int* bins = new int[numberOfBins];

  for (int i = 0; i < arraySize; ++i)
  {
    int binIndex = numbers[i] / 10;
    bins[binIndex]++;
  }

  return bins;

}

int main() 
{
  int usrSize;
  
  cout << "Hello! Please enter the size of your array: ";
  cin >> usrSize;

  int* dataPoints = new int[usrSize];

  cout << "Please enter a list of integers (non-negative): " << endl;

  for (int i = 0; i < usrSize; ++i)
  {
    cin >> dataPoints[i];
  }

  int* myHistogram = create_histogram(usrSize, dataPoints);

  int maxNumber = *max_element(dataPoints, dataPoints + usrSize); 
  int numberOfBins = (maxNumber / 10) + 1; 

  cout << "Here's your histogram!" << endl;
  for (int i = 0; i < numberOfBins; ++i)
  {
    int lowerBound = i * 10;
    int upperBound = (i + 1) * 10 - 1;

    cout << "Bin " << i + 1 << "(" << lowerBound << "-" << upperBound << "):\t" << myHistogram[i] << " values" << endl;
  }
  
  delete[] myHistogram;
  delete[] dataPoints;

  return 0;
}