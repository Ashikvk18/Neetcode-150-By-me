#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++){
        int current = nums[i];
        int compliment = target - current;
        if (map.contains(compliment)){
            return {map[compliment], i};
        }
        map[current] = i;
    }
    return {};
}
