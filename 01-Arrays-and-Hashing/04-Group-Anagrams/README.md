# Group Anagrams - My Grouping Pattern Mastery

**🔗 [NeetCode Problem](https://neetcode.io/problems/group-anagrams) | [LeetCode 49](https://leetcode.com/problems/group-anagrams/) | Difficulty: Medium**

---

## 🎯 What I'm Learning for Google
**Skills I need to master:**
- String signature pattern (sorted strings as keys)
- Hash map grouping (multiple values per key)
- Vector operations (2D vectors, push_back)
- Reference parameters (&) for efficiency

---

## 📖 Problem Statement
Given an array of strings `strs`, group the anagrams together. You can return the answer in any order.

---

## 🧠 My Thinking Process

### **Step 1: Building on Previous Knowledge**
**Question:** "How do you know if two strings are anagrams?"
**My Answer:** "we were checking frequency's" ✅

**What I learned:** I could apply my Valid Anagram knowledge to multiple strings!

### **Step 2: The Grouping Challenge**
**My realization:** I needed to group MULTIPLE strings, not just compare two

**My breakthrough:** "sorting operation" - all anagrams become the same when sorted!

### **Step 3: Data Structure Choice**
**My question:** "i am confused about adding to hashmap and the pushback used in it"

**My understanding:** Hash map can store multiple values per key automatically!

---

## 🎯 My Algorithm Design

### **My Signature Pattern:**
```
FOR each string:
    signature = sort_letters(string)
    ADD string to hash_map[signature]
```

### **Why This Works for Google:**
- ✅ **Signature pattern** - elegant grouping approach
- ✅ **Hash map efficiency** - O(1) grouping operations
- ✅ **Clean extraction** - range-based for loops

---

## 💻 How I Coded It

### **My Key Struggles & Solutions:**

#### **Struggle 1: Pattern Recognition**
**Problem:** "i don't want to look at the complete algorithm as it will make me weak"
**Solution:** Built it step by step with pseudocode first!

#### **Struggle 2: Reference Parameter Syntax**
**Problem:** "the syntax for declaring the vector and map is confusing me the &"
**Solution:** Learned `&` = reference (no copy) for efficiency!

#### **Struggle 3: Vector vs Other DS**
**Problem:** "make me understand vector syntax and differences from other similar ds"
**Solution:** Understood vector = dynamic, ordered, random access

#### **Struggle 4: Sort Function Syntax**
**Problem:** "string s = sort(strs[i].begin(), strs[i].end());"
**Solution:** Learned sort() works IN PLACE, doesn't return!

### **My Complete Solution:**
```cpp
vector<vector<string>> groupA(vector<string>& strs){
    unordered_map<string, vector<string>> map;
    for (int i=0; i<strs.size(); i++) {
        string s = strs[i];
        sort(s.begin(), s.end());           // Sort for signature
        map[s].push_back(strs[i]);         // Add to group
    }
    vector<vector<string>> result;
    for (auto& pair : map) {
        result.push_back(pair.second);      // Extract groups
    }
    return result;
}
```

---

## 📊 My Complexity Analysis

### **Time Complexity: O(n × m log m)**
- **n** = number of strings
- **m** = average string length
- **sort()** = O(m log m) for each string

### **Space Complexity: O(n × m)**
- **Hash map storage** for all strings
- **Result vector** for grouped output

### **What I Learned About Tradeoffs:**
- **Time cost:** Sorting each string is necessary for signature
- **Space cost:** Hash map grouping is worth it for organization
- **Reference efficiency:** `&` saves O(n) space

---

## 🎓 What I Learned About Google Interviews

### **What I Did Right:**
1. ✅ **Built on previous knowledge** - used Valid Anagram experience
2. ✅ **Chose elegant pattern** - sorted string signatures
3. ✅ **Used efficient syntax** - range-based for loops, references
4. ✅ **Understood tradeoffs** - time vs space, copy vs reference

### **Struggles I Had & How I Fixed Them:**

#### **Struggle 1: Reference Parameters**
**Problem:** "the & is confusing me"
**Solution:** `&` = reference (no copy) for large parameters

#### **Struggle 2: Sort Function**
**Problem:** Thought sort() returns sorted string
**Solution:** sort() modifies in place, need to copy first

#### **Struggle 3: Hash Map Push Back**
**Problem:** "confused about adding to hashmap and the pushback"
**Solution:** `map[key].push_back(value)` creates/grows groups automatically

#### **Struggle 4: Vector vs Other DS**
**Problem:** Didn't know when to use vector vs array vs map
**Solution:** Vector = dynamic ordered list, Array = fixed ordered list, Map = key-value lookup

---

## 🚀 My Google Prep Journey

### **What This Problem Taught Me:**
1. **Signature pattern** - transform data for grouping
2. **Hash map mastery** - multiple values per key
3. **Efficiency thinking** - references vs copies
4. **Pattern extension** - building on previous knowledge

### **How I'll Use This Knowledge:**
- **Group Shifted Strings** - similar signature pattern
- **Top K Frequent Elements** - hash map + vector extraction
- **Many grouping problems** - same pattern with different signatures

### **Key Tricks I Must Remember:**
```cpp
// String signature
string signature = s;
sort(signature.begin(), signature.end());

// Hash map grouping
map[signature].push_back(original_string);

// Efficient iteration
for (auto& pair : map) {
    result.push_back(pair.second);
}
```

---

## 🎯 My Personal Study Notes

### **What I Need to Remember:**
- **Signature pattern** = transform for grouping
- **Hash map** = signature → list of originals
- **Reference parameters** = `&` for efficiency
- **Sort in place** = copy first, then sort

### **Syntax I Mastered:**
```cpp
// Reference parameter
vector<vector<string>> func(vector<string>& strs)

// String sorting
string s = strs[i];
sort(s.begin(), s.end());

// Hash map grouping
map[key].push_back(value);

// Vector extraction
for (auto& pair : map) {
    result.push_back(pair.second);
}
```

### **What I'm Proud Of:**
- I built on my Valid Anagram knowledge
- I mastered reference parameter efficiency
- I understood the signature pattern
- I chose the right data structures

### **My Commitment to Myself:**
- I will recognize grouping patterns quickly
- I will use references for large parameters
- I will understand when to copy vs reference
- I will explain my pattern choices clearly

---

## 📊 Examples I Mastered

### **Example: strs = ["eat","tea","tan","ate","nat","bat"]**
1. **"eat"** → sort → "aet" → map["aet"] = ["eat"]
2. **"tea"** → sort → "aet" → map["aet"] = ["eat", "tea"]
3. **"tan"** → sort → "ant" → map["ant"] = ["tan"]
4. **"ate"** → sort → "aet" → map["aet"] = ["eat", "tea", "ate"]
5. **"nat"** → sort → "ant" → map["ant"] = ["tan", "nat"]
6. **"bat"** → sort → "abt" → map["abt"] = ["bat"]

**Final result:** [["eat","tea","ate"], ["tan","nat"], ["bat"]]

---

**I'm four steps closer to Google!** 🚀

*This was my journey through grouping patterns and efficient data structures!*

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
