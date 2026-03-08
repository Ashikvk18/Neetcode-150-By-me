#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // value -> index
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Check if we've seen the complement
            if (seen.count(complement)) {
                return {seen[complement], i};
            }
            
            // Store current number for future checks
            seen[nums[i]] = i;
        }
        
        return {}; // Should never reach here (guaranteed solution)
    }
};
