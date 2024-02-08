#include <iostream> 
#include <fstream> 
#include <ifstream>   
#include <stdlib.h>
#include <cmath>
#include <vector>    
#include <numeric>
#include <algorithm>

using namespace std;

double mean_and_sdeviation(const vector<double> scores)
{
	double mean, standardDeviation = 0.0;
	
	int scoreSize = scores.size();
	
	fixed;
	precision(2);
	
	//	sum elements in vector
	auto sum = accumulate(scores.begin(), scores.end(), 0.0);
	
	mean = sum / scoreSize;
	cout << "The average score is: " mean << endl;
	
	
	for i = 0; i < scoreSize; i++)
	{
		standardDeviation += pow(scores[i] - mean, 2);
	}
	
	standardDeviation = sqrt(standardDeviation/scoreSize);
	cout << "The standard deviation is: " << standardDeviation << endl;
	
	
	ofstream outputFile;
	outputFile.open ("output.txt");
	outputFile << "The average score is: " mean << endl;
	outputFile << "The standard deviation is: " << standardDeviation << endl;
	
}

int main() 
{
	vector<double> scores;
	string fileName;
	ifstream file;
	
	cout << "Input your file name (i.e. filename.txt): ";
	cin >> fileName;
	
	file.open(fileName);
		
	if (file.fail())
	{
		cout << "Error: file failed to open.\n";
		return 1;
	}
	
	
	while(!file.eof())
	{
		getline(file, line);
		scores.push_back(line);
	}
	
	file.close();
	
	for (auto file_line : scores)
		cout << file_line << endl;
	
	mean_and_sdeviation(scores)
	
return 0;	
}