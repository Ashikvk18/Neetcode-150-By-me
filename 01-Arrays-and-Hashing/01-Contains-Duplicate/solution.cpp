#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        
        for (int num : nums) {
            if (seen.count(num)) {
                return true;  // Found a duplicate
            }
            seen.insert(num);
        }
        
        return false;  // No duplicates found
    }
};
