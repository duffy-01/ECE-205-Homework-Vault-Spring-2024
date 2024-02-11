#include <iostream>
#include <algorithm>
#include <iterator>
#include <random>
#include <stdlib.h>

using namespace std;

int main(){
    srand(unsigned(time(0)));
    int nums[25];

    for (int i = 0; i < 25; ++i)
    {
        nums[i] = i + 1;
    }
    random_shuffle(nums, nums + 25);

    for (int i = 0; i < 5; i++)
    {
       cout << "Contestant "<<nums[i] << ", you win a prize!" << endl;
    }

    return 0;
}