# Product of Array Except Self - My Two-Pass Algorithm Journey

**🔗 [NeetCode Problem](https://neetcode.io/problems/product-of-array-except-self) | [LeetCode 238](https://leetcode.com/problems/product-of-array-except-self/) | Difficulty: Medium**

---

## 🎯 Problem Understanding

**Problem Statement:** Given an integer array `nums`, return an array `answer` such that `answer[i]` is equal to the product of all elements of `nums` except `nums[i]`.

**Key Constraint:** Solve it in **O(n)** time **without using division**.

**Example:**
```
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Explanation: 
answer[0] = 2*3*4 = 24
answer[1] = 1*3*4 = 12
answer[2] = 1*2*4 = 8
answer[3] = 1*2*3 = 6
```

---

## 🧠 My Initial Thoughts

When I first read this problem, my immediate reaction was:
1. **The obvious solution** - calculate total product and divide by each element
2. **But wait** - the constraint says "without using division"
3. **What about zeros?** Division would fail with zeros in the array
4. **How to exclude the current element?** Need a systematic approach

This felt like a "prefix/suffix" problem - I needed to calculate products from both directions.

---

## 💡 My Solution Approach

### Step 1: Understanding the Constraint
The "no division" constraint is crucial because:
- **Zeros would cause division by zero**
- **Floating-point precision issues**
- **Interviewers want to see the two-pass approach**

### Step 2: Left and Right Products Strategy
I realized I could solve this by:
- **Left products** - product of all elements before current position
- **Right products** - product of all elements after current position
- **Final answer** - left[i] × right[i]

### Step 3: Space Optimization
Instead of storing two separate arrays, I used:
- **Result array** for left products
- **Single variable** for right products (calculated on the fly)

---

## 🔍 Pseudocode Logic Flow

```
FUNCTION productExceptSelf(nums):
    
    // STEP 1: Initialize
    n = length of nums
    result = array of size n
    
    // STEP 2: Calculate left products
    result[0] = 1  // Nothing to the left of first element
    
    FOR i from 1 to n-1:
        result[i] = result[i-1] * nums[i-1]
    END FOR
    
    // At this point: result contains left products
    // Example: nums=[1,2,3,4] → result=[1,1,2,6]
    
    // STEP 3: Calculate right products and multiply
    right_product = 1  // Nothing to the right of last element
    
    FOR i from n-1 down to 0:
        // Multiply left product by right product
        result[i] = result[i] * right_product
        
        // Update right_product for next iteration
        right_product = right_product * nums[i]
    END FOR
    
    // STEP 4: Return result
    RETURN result
```

---

## 🎯 Pattern Recognition for Google SWE

### **Primary Pattern: Two-Pass Algorithm**
This is a fundamental pattern that appears in many Google interview problems:

#### **When to Use This Pattern:**
- **"Calculate something for each element excluding that element"**
- **"Need information from both left and right sides"**
- **"O(n) time with O(1) extra space"**
- **"Can't use division" constraint**

#### **Key Components:**
1. **Forward pass** - accumulate information from left to right
2. **Backward pass** - accumulate information from right to left
3. **In-place calculation** - use output array to store intermediate results
4. **Single variable** for the second pass (space optimization)

#### **Google Interview Variations:**
- **Prefix Sum Array** (same pattern, addition instead of multiplication)
- **Running Sum** (same pattern, single pass)
- **Trapping Rain Water** (same pattern, max instead of product)
- **Maximum Product Subarray** (similar two-direction thinking)

### **Secondary Pattern: Prefix/Suffix Products**
I learned that **prefix/suffix calculations** are crucial:
- Breaking complex calculations into simpler directional passes
- Using the output array efficiently for intermediate storage
- Maintaining running state while traversing

---

## 🔍 My Learning Process

### Struggles I Overcame:

#### 1. **Understanding Right Products**
Initially, I was confused about how to calculate right products:
```cpp
// I was thinking about storing them in an array
vector<int> right_products(n);
```

**Solution:** Use a single variable and go backwards:
```cpp
int right_product = 1;
for(int i = n-1; i >= 0; i--) {
    result[i] *= right_product;
    right_product *= nums[i];
}
```

#### 2. **Indexing Confusion**
I struggled with the correct indexing for left products:
```cpp
// I initially tried:
result[i] = result[i-1] * nums[i+1];  // ❌ Wrong!
```

**Solution:** Use i-1 for the element before current position:
```cpp
result[i] = result[i-1] * nums[i-1];  // ✅ Correct!
```

#### 3. **Vector vs Array Understanding**
I wasn't sure why to use vector instead of array:
```cpp
int arr[n];  // ❌ Size must be known at compile time
vector<int> vec(n);  // ✅ Dynamic size based on input
```

**Solution:** Vector is needed because input size varies at runtime.

---

## 💻 My Solution Code

```cpp
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size());
        result[0] = 1;
        for(int i = 1; i<nums.size(); i++){
            result[i] = result[i-1] * nums[i-1];
        }
        int rightProduct = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            result[i] *= rightProduct;
            rightProduct *= nums[i];
        }
        return result;
    }
};
```

---

## 📊 Complexity Analysis

### Time Complexity: O(n)
- **First pass:** O(n) for left products
- **Second pass:** O(n) for right products
- **Total:** O(n)

### Space Complexity: O(1)
- **Result array** doesn't count as extra space (required for output)
- **Only one extra variable:** `rightProduct`
- **No additional arrays needed**

---

## 🎓 Google Interview Insights

### Key Pattern I Learned:
**Two-Pass Algorithm Pattern**
- Forward pass to accumulate information from one direction
- Backward pass to incorporate information from the other direction
- Use output array efficiently for intermediate storage
- Maintain minimal extra space with running variables

### Why This Matters for Google:
- **Efficiency** - O(n) time with O(1) space
- **Scalability** - works for large arrays
- **Memory optimization** - minimal extra allocation
- **Algorithmic thinking** - breaking complex problems into simpler passes

### Alternative Approaches I Considered:
1. **Division approach** - violates constraint, fails with zeros
2. **Two separate arrays** - correct but uses O(n) extra space
3. **Brute force** - O(n²) time, too slow
4. **My approach** - O(n) time, O(1) space, optimal

For most interviews, my approach is perfect - optimal time and space with clean implementation.

---

## 🔗 Related Problems

This pattern connects to:
- **Trapping Rain Water** - two-pass with max instead of product
- **Maximum Product Subarray** - similar directional thinking
- **Prefix Sum** - same pattern with addition
- **Running Sum** - single-pass variation

---

## 🚀 My Takeaways

1. **Two-pass thinking** - solve problems from both directions
2. **Space optimization** - use output array efficiently
3. **Constraint analysis** - "no division" leads to specific approach
4. **Indexing mastery** - careful with i-1, i+1 relationships
5. **Vector vs array** - understand when to use each
6. **Running variables** - maintain state while traversing

This problem taught me fundamental two-pass algorithm design and space optimization techniques - essential skills for Google SWE interviews!

---

**Problem 9/150 Complete! 🎯**
