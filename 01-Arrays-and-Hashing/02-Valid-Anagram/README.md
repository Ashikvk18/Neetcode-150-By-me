# Valid Anagram - Easy

## Problem Statement
Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, and `false` otherwise.

## Examples
```
Input: s = "anagram", t = "nagaram"
Output: true
Explanation: Both strings contain the same characters with same frequencies.

Input: s = "rat", t = "car"
Output: false
Explanation: Different characters and frequencies.
```

## Constraints
- 1 <= s.length, t.length <= 5 * 10^4
- s and t consist of lowercase English letters only
- Both strings must have same length to be anagrams

## Visualization & Approach
### 🧠 The "Scrabble Tile Bag" Analogy
Think of this problem like checking if two people have the same Scrabble tiles:

**Scenario**: Two players each have a bag of letters
- **Your job**: Verify both bags have identical tiles
- **Your tool**: A frequency counter (like sorting tiles by letter)
- **Process**: Count each letter, compare the counts

### Step-by-Step Solution
1. **📏 Quick check**: Are the strings same length? If not, immediately false!
2. **🗂️ Grab a frequency counter** (array of size 26 for each letter)
3. **🔢 Count letters in first string**: For each 'a', increment counter[0], etc.
4. **🔍 Count letters in second string**: For each letter, decrement counter
5. **✅ Final check**: Are all counters back to zero? If yes → anagram!

### Algorithm
```
If lengths differ → Return false
Create array of 26 zeros (one for each letter)
For each character in s:
    Increment its counter
For each character in t:
    Decrement its counter
If all counters are zero → Return true
Else → Return false
```

### Visual Example
```
s = "rat", t = "art"

Step 1: Lengths equal? Yes (both 3) ✅
Step 2: Counters = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

Step 3: Count "rat":
        r (index 17): [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0]
        a (index 0):  [1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0]
        t (index 19): [1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0]

Step 4: Subtract "art":
        a (index 0):  [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0]
        r (index 17): [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0]
        t (index 19): [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

Step 5: All zeros? Yes! ✅ RETURN TRUE
```

### Memory Trick
**"Count Up, Count Down, Check Zero"**
- **Count Up** letters from first string
- **Count Down** letters from second string  
- **Check Zero** at the end

## Complexity Analysis
- **Time Complexity**: O(n) - We scan both strings once
- **Space Complexity**: O(1) - Fixed array of 26 elements (constant space)

## Implementation (C++)
```cpp
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Quick length check
        if (s.length() != t.length()) {
            return false;
        }
        
        // Frequency counter for 26 letters
        vector<int> count(26, 0);
        
        // Count characters in s
        for (char c : s) {
            count[c - 'a']++;
        }
        
        // Subtract characters in t
        for (char c : t) {
            count[c - 'a']--;
        }
        
        // Check if all counts are zero
        for (int num : count) {
            if (num != 0) {
                return false;
            }
        }
        
        return true;
    }
};
```

## Test Cases
- Test case 1: "anagram", "nagaram" → true
- Test case 2: "rat", "car" → false
- Test case 3: "a", "a" → true (single character)
- Test case 4: "ab", "a" → false (different lengths)
- Test case 5: "aaaa", "aaab" → false (same length, different chars)
- Test case 6: "listen", "silent" → true (common anagram)

## Key Insights & Lessons Learned
- **Early exit optimization** - Check lengths first to avoid unnecessary work
- **Fixed-size array** is better than hash map for limited character set
- **Two-pass approach** - Count up then count down is very efficient
- **Character to index mapping** - `c - 'a'` converts letter to 0-25 index
- **Alternative approaches**:
  - Sort both strings and compare (O(n log n) time)
  - Use hash map instead of array (more flexible but slower)

## References
- [NeetCode - Valid Anagram](https://neetcode.io/problems/valid-anagram)
- [LeetCode 242 - Valid Anagram](https://leetcode.com/problems/valid-anagram/)
