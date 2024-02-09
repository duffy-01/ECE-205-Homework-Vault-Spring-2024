#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <ctime>

std::vector<uint64_t> gen_unique_random(uint64_t count) 
{
  std::unordered_set<uint64_t> generated{}; 
  for (int c = 0; c < count; c++) 
  {
    while (true) 
    {
      uint64_t random_value = std::rand() % 25 + 1;
      
      if (std::find(generated.begin(), generated.end(), random_value) == generated.end()) 
      {
        generated.emplace(random_value);
        break;
      }
    }
  }
  return std::vector<uint64_t>(generated.begin(),generated.end());
}

int main() 
{
  std::srand(std::time(nullptr)); 
  auto nums = gen_unique_random(5);
  std::for_each(nums.begin(), nums.end(), [](uint64_t num){std::cout << num << std::endl;});
  
  return 0;
}