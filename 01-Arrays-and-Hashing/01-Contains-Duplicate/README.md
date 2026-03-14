# Contains Duplicate - My First Problem

**🔗 [NeetCode Problem](https://neetcode.io/problems/duplicate-integer) | [LeetCode 217](https://leetcode.com/problems/contains-duplicate/) | Difficulty: Easy**

---

## 🎯 What I'm Learning for Google
**Skills I need to master:**
- Understanding problems clearly
- Choosing the right data structures
- Analyzing time/space complexity
- Writing clean, efficient code

---

## 📖 Problem Statement
Given an array of integers `nums`, return `true` if any value appears at least twice in the array, and return `false` if every element is distinct.

---

## 🧠 My Thinking Process

### **Step 1: Understanding the Problem**
**Question:** "What does 'return true if any value appears at least twice' mean?"
**My Answer:** "it means there are duplicates" ✅

**What I learned:** I need to make sure I understand the problem before jumping into coding.

### **Step 2: Examples**
I needed to test my understanding:
- **TRUE case:** `{1,2,3,2}` → number 2 appears twice
- **FALSE case:** `{1,2,3,4}` → all numbers unique

### **Step 3: How I Would Solve It Manually**
**My approach:** "I will try to save it somewhere all the numbers one by one but before saving I will check if it is already there"

**What this showed me:** I naturally thought about efficiency instead of brute force!

---

## 🎯 My Algorithm Design

### **My Algorithm:**
```
For each number in the array:
    if (number is already in my storage):
        return true    // Found duplicate!
    else:
        add number to storage
return false    // No duplicates found
```

### **Why This Works for Google:**
- ✅ **Single pass** - optimal time complexity
- ✅ **Early exit** - return as soon as duplicate found
- ✅ **Clean logic** - easy to explain in an interview

---

## 💻 How I Coded It

### **C++ Concepts I Had to Learn:**
```cpp
#include <unordered_set>  // Hash set for O(1) operations
unordered_set<int> seen;  // Create empty set
seen.count(nums[i])       // Check if exists (returns 1 or 0)
seen.insert(nums[i])      // Add to set
```

### **My Complete Solution:**
```cpp
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;                    // My storage!
    for(int i=0; i<nums.size(); i++) {          // Loop through array
        if (seen.count(nums[i])) {               // Check if exists
            return true;                         // Found duplicate!
        }
        seen.insert(nums[i]);                    // Add to set
    }
    return false;                                // No duplicates
}
```

---

## 📊 My Complexity Analysis

### **Time Complexity: O(n)**
**My reasoning:** Loop through array `n` times, each operation is O(1)
**Google confirmation:** This is optimal! Can't do better than O(n)

### **Space Complexity: O(n)**
**My reasoning:** Worst case stores all `n` unique numbers
**What I learned:** Sometimes extra space is worth it for optimal time

---

## 🎓 What I Learned About Google Interviews

### **What I Did Right:**
1. ✅ **Understood the problem first** - didn't rush to code
2. ✅ **Provided examples** - showed I understood edge cases
3. ✅ **Thought about efficiency** - didn't choose brute force
4. ✅ **Chose the right data structure** - hash set was perfect
5. ✅ **Explained my logic** - communication is key

### **Mistakes I Made & Fixed:**
- ❌ **Syntax error:** `#include iostream` → `#include <iostream>`
- ❌ **Wrong variable:** Used `n` instead of `nums.size()`
- ❌ **Incomplete logic:** Didn't know how to check if element exists
- ✅ **Fixed all of them** - Learned from each mistake!

---

## 🚀 My Google Prep Journey

### **What This Problem Taught Me:**
1. **Hash sets are powerful** - O(1) operations change everything
2. **Pattern recognition** - "Have I seen this before?" is common
3. **Complexity thinking** - Always consider time AND space
4. **Interview communication** - Think out loud, explain choices

### **How I'll Use This Knowledge:**
- **Two Sum** - Same "seen before" pattern
- **Valid Anagram** - Similar frequency counting idea
- **Group Anagrams** - Extension of this concept

### **My Study Strategy:**
1. **Master fundamentals** - Arrays, hash sets, complexity
2. **Learn patterns** - Recognize common problem types
3. **Practice communication** - Explain every decision
4. **Build confidence** - Each problem makes me stronger

---

## 🎯 My Personal Study Notes

### **What I Need to Remember:**
- `unordered_set<T>` for O(1) lookups
- `seen.count(x)` returns 1 if exists, 0 if not
- `seen.insert(x)` adds to the set
- Always consider edge cases (empty array, single element)
- Explain my thinking before coding

### **C++ Syntax Reference (What I Learned):**
```cpp
// 1. Include necessary headers
#include <iostream>        // For input/output
#include <unordered_set>  // For hash set
#include <vector>         // For vectors

// 2. Create a hash set
unordered_set<int> seen;  // Empty set for integers

// 3. Check if element exists in set
if (seen.count(element)) {  // Returns 1 if exists, 0 if not
    // Element exists!
}

// 4. Add element to set
seen.insert(element);  // Add element to set

// 5. Loop through vector
for(int i = 0; i < nums.size(); i++) {  // Traditional for loop
    // Access element with nums[i]
}

// 6. Alternative: Range-based for loop
for(int num : nums) {  // Modern C++ style
    // num is each element
}
```

### **Common Syntax Mistakes I Made:**
```cpp
// ❌ Wrong: Missing angle brackets
#include iostream

// ✅ Correct: With angle brackets
#include <iostream>

// ❌ Wrong: Using undefined variable
for(int i=0; i<n; i++)

// ✅ Correct: Using vector size
for(int i=0; i<nums.size(); i++)

// ❌ Wrong: Incomplete statement
if (seen.)

// ✅ Correct: Complete condition
if (seen.count(nums[i]))
```

### **What I'm Proud Of:**
- I didn't give up when I got stuck on syntax
- I asked questions to understand concepts
- I wrote clean, readable code
- I analyzed my own complexity

### **My Commitment to Myself:**
- I will solve every problem with understanding, not memorization
- I will ask questions when confused
- I will celebrate small wins like this one
- I will keep pushing toward my Google goal

---

**I'm one step closer to Google!** 🚀

*This is my journey, my learning, my progress.*
