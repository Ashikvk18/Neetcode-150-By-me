# Top K Frequent Elements - My Google SWE Journey

## 🎯 Problem Understanding

**Problem Statement:** Given an integer array `nums` and an integer `k`, return the `k` most frequent elements.

**LeetCode Link:** [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/)

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

## 🔍 Pseudocode Logic Flow

```
FUNCTION topKFrequent(nums, k):
    
    // STEP 1: Count frequencies using hash map
    CREATE unordered_map<int, int> freq
    
    FOR each number in nums:
        freq[number] = freq[number] + 1
    
    // STEP 2: Convert hash map to vector for sorting
    CREATE vector<pair<int, int>> freqVector
    
    FOR each (number, frequency) in freq:
        freqVector.push_back({frequency, number})
    
    // STEP 3: Sort by frequency (highest first)
    SORT freqVector from begin to end:
        // Default sort works because we stored {frequency, number}
        // Pairs compare first element by default
    
    // STEP 4: Extract top k elements
    CREATE vector<int> result
    
    FOR i from 0 to k-1:
        result.push_back(freqVector[i].number)
    
    RETURN result
```

---

## 🎯 Pattern Recognition for Google SWE

### **Primary Pattern: Frequency Counting + Sorting**
This is a fundamental pattern that appears in many Google interview problems:

#### **When to Use This Pattern:**
- **"Find top k most frequent/least frequent"**
- **"Sort by frequency/count"**
- **"Rank elements by occurrence"**

#### **Key Components:**
1. **Hash Map** - Count frequencies in O(n)
2. **Sorting** - Order by frequency in O(n log n)
3. **Extraction** - Take top k elements in O(k)

#### **Google Interview Variations:**
- **Top K Frequent Words** (same pattern, different data type)
- **Sort Characters By Frequency** (same pattern, string manipulation)
- **Find K Most Frequent Elements in Stream** (adds streaming constraint)

### **Secondary Pattern: Smart Data Structure Design**
I learned that **how you store data matters**:

#### **Smart Choice:**
```cpp
// Store {frequency, number} instead of {number, frequency}
freqVector.push_back({pair.second, pair.first});
```

#### **Why This is Google-Level Thinking:**
- **Eliminates need for custom comparator**
- **Reduces code complexity**
- **Leverages language defaults**
- **Shows optimization awareness**

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
