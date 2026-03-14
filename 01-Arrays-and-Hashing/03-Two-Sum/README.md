# Two Sum - My Most Important Google Pattern

**🔗 [NeetCode Problem](https://neetcode.io/problems/two-integer-sum) | [LeetCode 1](https://leetcode.com/problems/two-sum/) | Difficulty: Easy**

---

## 🎯 What I'm Learning for Google
**Skills I need to master:**
- The complement pattern (appears in 20+ Google problems)
- Hash map complement lookup strategy
- Single-pass optimization (O(n²) → O(n))
- Index tracking in hash maps

---

## 📖 Problem Statement
Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

---

## 🧠 My Thinking Process

### **Step 1: Understanding the Problem**
**Question:** "What does 'two numbers such that they add up to the target' mean?"
**My Answer:** "there will be two numbers in the given array in such way that their sum total is equal to a given number" ✅

**What I learned:** I understood the core concept - find two numbers that sum to target.

### **Step 2: How I Would Solve It Manually**
**My approach:** "i will go along the array starting from index zero till end and find the other number that makes the sum total equal to the target"

**What this showed me:** I naturally thought about brute force O(n²) approach!

### **Step 3: The Google Optimization Question**
**My realization:** "our brute force approach will take big O of n^2 time but i am not sure what data structure will be helpful"

**My breakthrough:** I needed something faster than O(n²)!

---

## 🎯 My Algorithm Design

### **My Natural (Brute Force) Algorithm:**
```
FOR each number i:
    FOR each number j (after i):
        IF nums[i] + nums[j] == target:
            RETURN {i, j}
```
**Complexity:** O(n²) time, O(1) space

### **My Google-Level (Optimal) Algorithm:**
```
CREATE hash_map (number → index)
FOR each index i and number in nums:
    complement = target - number
    IF hash_map.contains(complement):
        RETURN {hash_map[complement], i}
    hash_map[number] = i
```
**Complexity:** O(n) time, O(n) space

### **Why This Works for Google:**
- ✅ **Single pass** - optimal O(n) time
- ✅ **Hash map lookup** - O(1) complement checking
- ✅ **Complement pattern** - fundamental Google pattern

---

## 💻 How I Coded It

### **My Key Struggles & Solutions:**

#### **Struggle 1: Pattern Recognition**
**Problem:** "i want to be a swe at google for that i need to learn to recognize patterns"
**Solution:** Learned the complement formula: `complement = target - current`

#### **Struggle 2: Data Structure Choice**
**Problem:** "unordered set teacher?"
**Solution:** Realized I need to store BOTH number AND index → unordered_map!

#### **Struggle 3: Hash Map Syntax**
**Problem:** "hash_map[complement]; and hash_map[key] i am confused"
**Solution:** Learned they're the same operation with different variable names!

#### **Struggle 4: The Critical Order**
**Problem:** "so the logic is we need to store the value from an array as indexes in the unordered map first?"
**Solution:** Learned to CHECK first, then STORE (avoids the duplicate trap!)

### **My Complete Solution:**
```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;  // number → index
    for (int i = 0; i < nums.size(); i++){
        int current = nums[i];
        int compliment = target - current;  // The magic formula!
        if (map.contains(compliment)){
            return {map[compliment], i};  // Return indices
        }
        map[current] = i;  // Store AFTER checking
    }
    return {};
}
```

---

## 📊 My Complexity Analysis

### **Brute Force Approach:**
- **Time:** O(n²) - nested loops
- **Space:** O(1) - no extra storage

### **Hash Map Approach:**
- **Time:** O(n) - single pass through array
- **Space:** O(n) - hash map storage

### **What I Learned About Tradeoffs:**
- **Time optimization:** O(n²) → O(n) is huge!
- **Space cost:** Worth it for time savings
- **Google preference:** Always optimize time when possible

---

## 🎓 What I Learned About Google Interviews

### **What I Did Right:**
1. ✅ **Recognized O(n²) was too slow** - shows optimization thinking
2. ✅ **Chose hash map over set** - need to store indices
3. ✅ **Used complement pattern** - fundamental Google pattern
4. ✅ **Got the order right** - check first, then store

### **Struggles I Had & How I Fixed Them:**

#### **Struggle 1: Complement Formula**
**Problem:** Didn't know the mathematical relationship
**Solution:** `complement = target - current_number`

#### **Struggle 2: Hash Map vs Set**
**Problem:** "unordered set teacher?"
**Solution:** Set stores values, Map stores key-value pairs (number + index)

#### **Struggle 3: Storing Syntax**
**Problem:** "how is syntax storing"
**Solution:** `map[key] = value` stores the pair

#### **Struggle 4: Order of Operations**
**Problem:** Wanted to store first, then check
**Solution:** Check first, then store (avoids duplicate trap!)

---

## 🚀 My Google Prep Journey

### **What This Problem Taught Me:**
1. **Complement pattern** - appears in 20+ Google problems
2. **Hash map mastery** - key-value storage and lookup
3. **Optimization thinking** - O(n²) → O(n)
4. **Order matters** - check first, then store

### **How I'll Use This Knowledge:**
- **Two Sum II** - sorted array version
- **3 Sum** - extend complement pattern
- **4 Sum** - further extension
- **Subarray Sum Equals K** - similar complement thinking

### **Key Tricks I Must Remember:**
```cpp
// Complement formula
int complement = target - current;

// Hash map operations
if (map.contains(complement)) {
    return {map[complement], i};
}
map[current] = i;  // Store AFTER checking
```

---

## 🎯 My Personal Study Notes

### **What I Need to Remember:**
- **Complement pattern** = target - current
- **Hash map** for number → index mapping
- **Check first, then store** (critical order!)
- **Return indices, not values**

### **Syntax I Mastered:**
```cpp
// Hash map declaration
unordered_map<int, int> map;  // number → index

// Check existence
if (map.contains(key))

// Get stored value
int stored_index = map[key];

// Store new pair
map[key] = value;
```

### **What I'm Proud Of:**
- I didn't give up when confused about data structures
- I asked about optimization (Google loves this!)
- I mastered the most important Google pattern
- I got the critical order right

### **My Commitment to Myself:**
- I will recognize complement patterns instantly
- I will always consider time-space tradeoffs
- I will remember "check first, then store"
- I will explain my optimization thinking clearly

---

## 📊 Examples I Mastered

### **Example 1: nums = [2, 7, 11, 15], target = 9**
1. **i=0, current=2:** complement=7, map doesn't contain 7, store map[2]=0
2. **i=1, current=7:** complement=2, map contains 2, return {0, 1}

### **Example 2: nums = [3, 3], target = 6**
1. **i=0, current=3:** complement=3, map doesn't contain 3, store map[3]=0
2. **i=1, current=3:** complement=3, map contains 3, return {0, 1}

---

**I'm three steps closer to Google!** 🚀

*This was my journey through the most important Google interview pattern - the complement strategy!*

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
