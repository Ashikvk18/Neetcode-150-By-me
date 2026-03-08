# Two Sum - Easy

## Problem Statement
Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

## Examples
```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: nums[0] + nums[1] == 9, so we return [0,1].

Input: nums = [3,2,4], target = 6
Output: [1,2]
Explanation: nums[1] + nums[2] == 6, so we return [1,2].

Input: nums = [3,3], target = 6
Output: [0,1]
Explanation: nums[0] + nums[1] == 6, so we return [0,1].
```

## Constraints
- 2 <= nums.length <= 10^4
- -10^9 <= nums[i] <= 10^9
- -10^9 <= target <= 10^9
- Exactly one valid answer exists

## Visualization & Approach
### 🧠 The "Shopping with a Friend" Analogy
Think of this problem like shopping with a specific budget:

**Scenario**: You and a friend are shopping, need to buy exactly $target worth of items
- **Your job**: Find two items that together cost exactly the target amount
- **Your tool**: A notepad to remember prices you've seen
- **Process**: For each item, calculate what you need and check if you've seen it

### Step-by-Step Solution
1. **📋 Grab an empty notepad** (hash map to store seen numbers)
2. **🛍️ Go through each item** (iterate through array)
3. **💰 Calculate needed amount**: `needed = target - current_item`
4. **🔍 Check notepad**: Have we seen this needed amount before?
   - **Yes?** 🎉 Found the pair! Return both indices
   - **No?** 📝 Write down current item: "I saw price X at position Y"
5. **🏁 Continue until you find the pair** (guaranteed to exist)

### Algorithm
```
For each number at index i:
    Calculate complement = target - nums[i]
    If complement exists in map:
        Return [map[complement], i]
    Store nums[i] with its index in map
```

### Visual Example
```
nums = [2,7,11,15], target = 9

Step 1: nums[0] = 2
        Needed: 9 - 2 = 7
        Notepad: {} → Haven't seen 7
        Store: {2:0} → "I saw 2 at position 0"

Step 2: nums[1] = 7  
        Needed: 9 - 7 = 2
        Notepad: {2:0} → YES! I saw 2 at position 0
        🎉 RETURN [0,1]
```

### Memory Trick
**"What Do I Need? Have I Seen It?"**
- **What do I need?** Calculate complement
- **Have I seen it?** Check the map
- **Store what I have** for future checks

## Complexity Analysis
- **Time Complexity**: O(n) - Single pass through the array
- **Space Complexity**: O(n) - In worst case, store all elements in the hash map

## Implementation (C++)
```cpp
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
```

## Test Cases
- Test case 1: [2,7,11,15], 9 → [0,1]
- Test case 2: [3,2,4], 6 → [1,2]
- Test case 3: [3,3], 6 → [0,1]
- Test case 4: [1,5,3,7,9], 12 → [1,4] (5 + 7 = 12)
- Test case 5: [-1,-2,-3,-4,-5], -8 → [2,4] (-3 + -5 = -8)
- Test case 6: [0,4,3,0], 0 → [0,3] (0 + 0 = 0)

## Key Insights & Lessons Learned
- **Hash map is key** - Enables O(1) lookup of complements
- **Single pass solution** - Much better than O(n²) brute force
- **Store value → index mapping** - Important to store indices, not values
- **Order doesn't matter** - Return indices in any order
- **Guaranteed solution** - No need to handle "no solution" case
- **Alternative approaches**:
  - Brute force O(n²) - Check all pairs
  - Sort + two pointers O(n log n) - But loses original indices

## References
- [NeetCode - Two Sum](https://neetcode.io/problems/two-sum)
- [LeetCode 1 - Two Sum](https://leetcode.com/problems/two-sum/)
