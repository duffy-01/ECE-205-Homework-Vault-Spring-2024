#include <iostream>
#include <algorithm>
#include <random>
#include <stdlib.h>
#include <unordered_map>
#include <ctime>

using namespace std;

int main() {
    srand(unsigned(time(0)));
    unordered_map<int, bool> winningContestants;

    const int CONTESTANT_NUM = 100000;
    int nums[CONTESTANT_NUM];

    for (int i = 0; i < CONTESTANT_NUM; ++i) {
        nums[i] = i + 1;
    }
    random_shuffle(nums, nums + CONTESTANT_NUM);

    for (int i = 0; i < 5; i++)
    {
        int randomIndex;

        do {
            randomIndex = rand() % CONTESTANT_NUM;
        } while (winningContestants.find(nums[randomIndex]) != winningContestants.end());

        winningContestants[nums[randomIndex]] = true;
        cout << "Contestant " << nums[randomIndex] << ", you win a prize!" << std::endl;
    }

    return 0;
}