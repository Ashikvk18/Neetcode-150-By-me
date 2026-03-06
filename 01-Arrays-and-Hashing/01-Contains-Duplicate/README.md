# Contains Duplicate - Easy

## Problem Statement
Given an integer array `nums`, return `true` if any value appears at least twice in the array, and return `false` if every element is distinct.

## Examples
```
Input: nums = [1,2,3,1]
Output: true
Explanation: The value 1 appears twice.

Input: nums = [1,2,3,4]
Output: false
Explanation: All values are distinct.

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
Explanation: Multiple values appear multiple times.
```

## Constraints
- 1 <= nums.length <= 10^5
- -10^9 <= nums[i] <= 10^9
- Array can contain negative numbers
- Array can have up to 100,000 elements

## Visualization & Approach
### 🧠 The "Party Guest List" Analogy
Think of this problem like checking if someone crashed a party twice:

**Scenario**: You're checking IDs at a party entrance
- **Your job**: Make sure no one enters twice
- **Your tool**: A clipboard with names (the hash set)
- **Process**: Check each person, add new names, stop if you see a duplicate

### Step-by-Step Solution
1. **📋 Grab an empty clipboard** (initialize hash set)
2. **👥 Line starts forming** (start iterating through array)
3. **🔍 Check each person's ID**:
   - **New face?** ✅ Add name to clipboard, let them in
   - **Seen before?** 🚨 Security! Duplicate found!
4. **🏁 End of line?** Everyone was unique if we made it through

### Algorithm
```
For each number in the array:
    Have we seen this number before?
    → YES: Return true (duplicate found!)
    → NO: Remember this number for later
Return false (no duplicates)
```

### Visual Example
```
Array: [1, 2, 3, 1]

Step 1: [1] → Clipboard: {1} ✅ New person
Step 2: [2] → Clipboard: {1, 2} ✅ New person  
Step 3: [3] → Clipboard: {1, 2, 3} ✅ New person
Step 4: [1] → Clipboard: {1, 2, 3} 🚨 WAIT, I've seen 1 before!
         → RETURN TRUE immediately!
```

### Memory Trick
**"Check, Add, or Catch"**
- **Check** if you've seen it
- **Add** it if it's new
- **Catch** the duplicate and celebrate!

## Complexity Analysis
- **Time Complexity**: O(n) - We scan the array once, and each set operation is O(1) on average
- **Space Complexity**: O(n) - In the worst case (no duplicates), we store all n elements in the set

## Implementation (C++)
```cpp
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
```

## Test Cases
- Test case 1: [1,2,3,1] -> true
- Test case 2: [1,2,3,4] -> false
- Test case 3: [1,1,1,3,3,4,3,2,4,2] -> true
- Edge case: [1] -> false (single element)
- Edge case: [0,0] -> true (zero duplicate)
- Edge case: [-1,-2,-3,-1] -> true (negative numbers)

## Key Insights & Lessons Learned
- **Hash sets are perfect for membership testing** - O(1) average time complexity
- **Early exit optimization** - Return as soon as we find a duplicate
- **Space-time tradeoff** - We use extra space to achieve O(n) time instead of O(n²)
- **Alternative approaches**:
  - Sort first (O(n log n) time, O(1) space) then check adjacent elements
  - Brute force O(n²) time, O(1) space - too slow for large inputs

## References
- [NeetCode - Contains Duplicate](https://neetcode.io/problems/contains-duplicate)
- [LeetCode 217 - Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)
