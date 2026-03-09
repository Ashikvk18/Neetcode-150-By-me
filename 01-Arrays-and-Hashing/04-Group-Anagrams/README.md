# Group Anagrams - Medium

## Problem Statement
Given an array of strings `strs`, group the anagrams together. You can return the answer in any order.

## Examples
```
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Explanation: All anagrams are grouped together.

Input: strs = [""]
Output: [[""]]

Input: strs = ["a"]
Output: [["a"]]
```

## Constraints
- 1 <= strs.length <= 10^4
- 0 <= strs[i].length <= 100
- strs[i] consists of lowercase English letters

## Visualization & Approach
### 🧠 The "Library Book Sorting" Analogy
Think of this problem like organizing books in a library by their letters:

**Scenario**: You're a librarian organizing books by their "letter signature"
- **Your job**: Group books that have exactly the same letters
- **Your tool**: A filing system where each book gets a "signature" (sorted letters)
- **Process**: Create signature for each book, group by same signature

### Step-by-Step Solution
1. **🗂️ Set up filing cabinets** (hash map for grouped anagrams)
2. **📚 Process each book** (iterate through each string)
3. **🔤 Create book signature**: Sort the letters alphabetically
   - "eat" → "aet", "tea" → "aet", "tan" → "ant"
4. **📁 File the book**: Put it in the cabinet labeled with its signature
5. **📖 Collect all books**: Return all groups from the filing cabinets

### Algorithm
```
For each string in strs:
    Create signature by sorting its characters
    Add string to map[signature]
Return all groups from the map
```

### Visual Example
```
strs = ["eat","tea","tan","ate","nat","bat"]

Step 1: "eat" → signature "aet"
        Groups: {"aet": ["eat"]}

Step 2: "tea" → signature "aet"  
        Groups: {"aet": ["eat", "tea"]}

Step 3: "tan" → signature "ant"
        Groups: {"aet": ["eat", "tea"], "ant": ["tan"]}

Step 4: "ate" → signature "aet"
        Groups: {"aet": ["eat", "tea", "ate"], "ant": ["tan"]}

Step 5: "nat" → signature "ant"
        Groups: {"aet": ["eat", "tea", "ate"], "ant": ["tan", "nat"]}

Step 6: "bat" → signature "abt"
        Groups: {"aet": ["eat", "tea", "ate"], "ant": ["tan", "nat"], "abt": ["bat"]}

Result: [["eat","tea","ate"], ["tan","nat"], ["bat"]]
```

### Memory Trick
**"Sort, Group, Collect"**
- **Sort** each string to create a unique signature
- **Group** strings with the same signature
- **Collect** all groups at the end

## Complexity Analysis
- **Time Complexity**: O(n * k log k) where n = number of strings, k = average string length
- **Space Complexity**: O(n * k) - Store all strings in the hash map

## Implementation (C++)
```cpp
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        
        for (string s : strs) {
            // Create signature by sorting characters
            string signature = s;
            sort(signature.begin(), signature.end());
            
            // Group by signature
            groups[signature].push_back(s);
        }
        
        // Collect all groups
        vector<vector<string>> result;
        for (auto& pair : groups) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};
```

## Test Cases
- Test case 1: ["eat","tea","tan","ate","nat","bat"] → [["bat"],["nat","tan"],["ate","eat","tea"]]
- Test case 2: [""] → [[""]]
- Test case 3: ["a"] → [["a"]]
- Test case 4: ["abc","bca","cab","xyz","zyx","zxy","a"] → [["abc","bca","cab"],["xyz","zyx","zxy"],["a"]]
- Test case 5: ["dddd","dddd"] → [["dddd","dddd"]]
- Test case 6: ["abc","def","ghi"] → [["abc"],["def"],["ghi"]]

## Key Insights & Lessons Learned
- **Sorted string as key** - Sorting creates a unique signature for anagrams
- **Hash map grouping** - Perfect for organizing by signature
- **Signature concept** - Transform each string to a canonical form
- **Order doesn't matter** - Within each group, any order is acceptable
- **Alternative approaches**:
  - Count characters (26-length array) as signature (O(n * k))
  - Prime number multiplication (theoretical, overflow issues)

## References
- [NeetCode - Group Anagrams](https://neetcode.io/problems/group-anagrams)
- [LeetCode 49 - Group Anagrams](https://leetcode.com/problems/group-anagrams/)
