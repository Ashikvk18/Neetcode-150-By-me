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
### Step-by-Step Solution
1. **Initialize a hash set** to store seen numbers
2. **Iterate through the array** one element at a time
3. **For each number**: Check if it's already in the set
   - If yes: We found a duplicate, return true
   - If no: Add it to the set and continue
4. **If loop completes**: No duplicates found, return false

### Algorithm
Use a hash set to track numbers we've seen. As we scan the array, if we encounter a number already in our set, we know there's a duplicate.

### Diagram/Flowchart
```
Start → Initialize empty set → For each num in nums:
                              ↓
                    Is num in set? → Yes → Return true
                              ↓
                           No → Add num to set
                              ↓
                        Continue to next element
                              ↓
                        End of array? → Yes → Return false
```

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
