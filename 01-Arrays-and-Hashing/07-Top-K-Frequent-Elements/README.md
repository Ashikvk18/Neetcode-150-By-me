# Top K Frequent Elements - My Google SWE Journey

## 🎯 Problem Understanding

**Problem Statement:** Given an integer array `nums` and an integer `k`, return the `k` most frequent elements.

**Example:**
```
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Explanation: Number 1 appears 3 times, number 2 appears 2 times, number 3 appears 1 time
```

---

## 🧠 My Initial Thoughts

When I first read this problem, I immediately thought:
1. **I need to count how many times each number appears** - this sounds like a hash map!
2. **I need to find the top k most frequent** - so I need to sort by frequency
3. **I need to return just the numbers** - not the frequencies

This felt similar to the frequency counting I did in Valid Anagram, but with an extra sorting step.

---

## 💡 My Solution Approach

### Step 1: Frequency Counting
I used an `unordered_map<int, int>` to count occurrences:
- **Key:** the number from the array
- **Value:** how many times it appears

### Step 2: Convert to Sortable Format
Hash maps can't be sorted by values, so I converted to a vector of pairs:
- **Smart choice:** Stored `{frequency, number}` instead of `{number, frequency}`
- **Why:** This made sorting automatic with default sort!

### Step 3: Sort by Frequency
Since I stored `{frequency, number}`, the default sort worked perfectly:
- **No lambda needed** - pairs compare first element by default
- **Descending order** - higher frequencies come first

### Step 4: Extract Top K Elements
Loop through first k elements and extract just the numbers.

---

## 🔍 My Learning Process

### Struggles I Overcame:

#### 1. **Vector Syntax Confusion**
Initially, I wasn't sure about vector syntax:
```cpp
// I learned:
vector<int> result;           // Create empty vector
result.push_back(value);      // Add element
vector<pair<int, int>> fV;   // Vector of pairs
```

#### 2. **Hash Map to Vector Conversion**
I had to understand how to convert hash map to vector:
```cpp
for (auto& pair : freq) {
    fV.push_back({pair.second, pair.first});  // {frequency, number}
}
```

#### 3. **Lambda Function Question**
I wondered if I needed a lambda function for sorting. Then I realized:
- **My smart data structure choice** made lambda unnecessary
- **Default sort works** when you store `{frequency, number}`

#### 4. **Pair Access**
I learned how to access pair elements:
```cpp
fV[i].first   // frequency
fV[i].second  // number
```

---

## 💻 My Solution Code

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    // Step 1: Count frequencies
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    
    // Step 2: Convert to vector of pairs {frequency, number}
    vector<pair<int, int>> fV;
    for (auto& pair : freq) {
        fV.push_back({pair.second, pair.first});
    }

    // Step 3: Sort by frequency (default sort works perfectly!)
    sort(fV.begin(), fV.end());

    // Step 4: Extract top k elements
    vector<int> result;
    for (int i = 0; i < k; i++){
        result.push_back(fV[i].second);  // The number, not frequency
    }
    
    return result;
}
```

---

## 📊 Complexity Analysis

### Time Complexity: O(n log n)
- **Frequency counting:** O(n)
- **Creating vector:** O(n)
- **Sorting:** O(n log n)
- **Extraction:** O(k)

### Space Complexity: O(n)
- **Hash map:** O(n)
- **Vector:** O(n)
- **Result:** O(k)

---

## 🎓 Google Interview Insights

### Key Pattern I Learned:
**Frequency Counting + Sorting Pattern**
- Use hash map to count frequencies
- Convert to sortable format when needed
- Smart data structure choices can simplify code

### Why This Matters for Google:
- **Data structure selection** shows deep understanding
- **Optimization awareness** (avoiding unnecessary lambdas)
- **Clean, readable code** - Google values maintainable solutions

### Alternative Approaches I Considered:
1. **Heap approach** - O(n log k) time, more complex
2. **Bucket sort** - O(n) time, but more code
3. **My approach** - O(n log n), simple and clean

For most interviews, my approach is perfect - simple, correct, and efficient.

---

## 🔗 Related Problems

This pattern connects to:
- **Valid Anagram** - frequency counting
- **Group Anagrams** - frequency counting + grouping
- **Two Sum** - hash map usage

---

## 🚀 My Takeaways

1. **Smart data structure choices** can simplify your code
2. **Understanding default behaviors** (like pair comparison) is valuable
3. **Vector syntax** is fundamental - practice it!
4. **Lambda functions** are powerful but not always necessary

This problem reinforced my hash map skills and taught me about sorting with pairs - perfect preparation for Google interviews!

---

**Problem 7/150 Complete! 🎯**
