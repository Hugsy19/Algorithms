// leetcode 1

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;

vector<int> twoSum_1(vector<int> &nums, int target) {
  for (int i = 0; i < nums.size(); ++i) {
    for (int j = i + 1; j < nums.size(); ++j) {
      if (target == nums[i] + nums[j])
        return {i, j};
    }
  }
  return {};
}

vector<int> twoSum_2(vector<int> &nums, int target) {
  std::unordered_map<int, int> mp;
  for (int i = 0; i < nums.size(); ++i) {
    auto it = mp.find(target - nums[i]);
    if (it != mp.end())
      return {i, it->second};
    mp[nums[i]] = i;
  }
  return {};
}

int main(int argc, char *argv[]) {
  vector<int> ret;
  vector<int> nums;
  int target;
  string input_str;

  while (getline(cin, input_str)) {
    std::stringstream ss(input_str);
    int num;

    while (ss >> num) {
      nums.push_back(num);
    }

    getline(cin, input_str);
    target = std::stoi(input_str);

    ret = twoSum_1(nums, target);
    if (ret.size())
      std::cout << "[" << ret[0] << ", " << ret[1] << "]" << endl;

    ret = twoSum_2(nums, target);
    if (ret.size())
      std::cout << "[" << ret[0] << ", " << ret[1] << "]" << endl;
  }

  return 0;
}