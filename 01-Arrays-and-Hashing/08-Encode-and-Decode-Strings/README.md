# Encode and Decode Strings - My String Manipulation Journey

**🔗 [NeetCode Problem](https://neetcode.io/problems/encode-and-decode-strings) | [LeetCode 271](https://leetcode.com/problems/encode-and-decode-strings/) | Difficulty: Medium**

---

## 🎯 Problem Understanding

**Problem Statement:** Design an algorithm to encode a list of strings to a single string. The encoded string can then be decoded to the original list of strings.

**Example:**
```
Input: ["Hello", "World"]
Output: "5#Hello5#World"
Decoded: ["Hello", "World"]
```

---

## 🧠 My Initial Thoughts

When I first read this problem, I immediately thought:
1. **I need to combine multiple strings into one** - but how do I know where each string ends?
2. **What if strings contain special characters?** Like "#" or numbers
3. **How do I preserve the original order?**
4. **What about empty strings?**

This felt like a data compression/serialization problem - converting complex data to a simple format and back.

---

## 💡 My Solution Approach

### Step 1: Length Prefix Strategy
I decided to use a length prefix approach:
- **Format:** `length + "#" + string`
- **Example:** "Hello" → "5#Hello"
- **Why:** Clear boundaries between strings

### Step 2: Encoding Process
For each string in the list:
- Get its length
- Convert length to string
- Concatenate: `length + "#" + string`
- Add to result

### Step 3: Decoding Process
Parse the encoded string:
- Read digits until "#" → get length
- Read exactly that many characters → get string
- Add to result list
- Repeat until end

---

## 🔍 Pseudocode Logic Flow

```
FUNCTION encode(list_of_strings):
    
    // STEP 1: Handle edge case
    IF list_of_strings is empty:
        RETURN empty string
    
    // STEP 2: Build encoded string
    CREATE empty_string result
    
    FOR each string in list_of_strings:
        length = size of string
        length_str = convert length to string
        encoded_part = length_str + "#" + string
        result = result + encoded_part
    
    RETURN result

FUNCTION decode(encoded_string):
    
    // STEP 1: Handle edge case
    IF encoded_string is empty:
        RETURN empty list
    
    // STEP 2: Parse the encoded string
    CREATE empty_list result
    SET position = 0
    
    WHILE position < length of encoded_string:
        // STEP 2a: Read length until "#"
        CREATE empty_string length_str
        
        WHILE encoded_string[position] is not "#":
            length_str = length_str + encoded_string[position]
            position = position + 1
        
        length = convert length_str to integer
        position = position + 1  // Skip "#"
        
        // STEP 2b: Read the actual string
        CREATE empty_string current_string
        
        FOR i from 0 to length-1:
            current_string = current_string + encoded_string[position]
            position = position + 1
        
        ADD current_string to result
    
    RETURN result
```

---

## 🎯 Pattern Recognition for Google SWE

### **Primary Pattern: Serialization/Deserialization**
This is a fundamental pattern that appears in many Google interview problems:

#### **When to Use This Pattern:**
- **"Convert complex data to simple format"**
- **"Transmit data over network"**
- **"Store structured data in string"**
- **"Data compression/encoding"**

#### **Key Components:**
1. **Delimiter Strategy** - choosing separators that won't conflict
2. **Length Prefixing** - knowing exact boundaries
3. **Parsing Logic** - systematic extraction
4. **Reversible Design** - perfect reconstruction

#### **Google Interview Variations:**
- **Serialize Binary Tree** (same pattern, tree structure)
- **Custom Data Structure Encoding** (same pattern, different data)
- **Network Protocol Design** (adds efficiency constraints)

### **Secondary Pattern: String Parsing**
I learned that **systematic string parsing** is crucial:
- Reading until specific characters
- Converting between data types
- Managing position/index tracking
- Handling edge cases in malformed input

---

## 🔍 My Learning Process

### Struggles I Overcame:

#### 1. **Variable Scope Confusion**
Initially, I declared `res` as a class member variable:
```cpp
class Codec {
    string res = "";  // ❌ Shared between calls
```

**Problem:** Results accumulated from previous calls!

**Solution:** Use local variable inside function:
```cpp
string encode(vector<string>& strs) {
    string res = "";  // ✅ Fresh each call
```

#### 2. **Return Statement Placement**
I accidentally put return inside the loop:
```cpp
for(int i = 0; i < strs.size(); i++) {
    // ... logic ...
    return res;  // ❌ Exited after first iteration!
}
```

**Solution:** Move return outside loop to process all strings.

#### 3. **Character vs String Comparison**
I tried to compare char with string:
```cpp
while(res[pos] != "#") {  // ❌ Can't compare char to string
```

**Solution:** Compare char to char:
```cpp
while(res[pos] != '#') {  // ✅ Compare char to char
```

#### 4. **Variable Reset in Loops**
I forgot to reset length accumulator:
```cpp
string L = "";  // Only set once
while(pos < res.length()) {
    // L accumulates from previous strings!
}
```

**Solution:** Reset inside loop:
```cpp
while(pos < res.length()) {
    string L = "";  // ✅ Fresh for each string
}
```

---

## 💻 My Solution Code

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for(int i = 0; i < strs.size(); i++) {
            string t = strs[i];
            int len = t.length();
            string l = to_string(len);
            res += l + '#' + t;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string res) {
        if(res.empty()) return {};
        vector<string> result;
        int pos = 0;
        
        while(pos < res.length()) {
            string L = "";
            while(res[pos] != '#') {
                L += res[pos];
                pos++;
            }
            pos++;
            int l = stoi(L);
            string s = "";
            for(int i = 0; i < l; i++) {
                s += res[pos];
                pos++;
            }
            result.push_back(s);
        }    
        return result;
    }
};
```

---

## 📊 Complexity Analysis

### Time Complexity: O(N)
- **Encoding:** O(N) - where N is total length of all strings
- **Decoding:** O(N) - each character processed exactly once
- **Total:** O(N)

### Space Complexity: O(N)
- **Encoded string:** O(N) - stores all characters plus length prefixes
- **Result vector:** O(N) - stores original strings
- **Temporary variables:** O(1) - constant space for parsing

---

## 🎓 Google Interview Insights

### Key Pattern I Learned:
**Serialization/Deserialization Pattern**
- Choose clear delimiters that won't conflict with data
- Use length prefixes for unambiguous boundaries
- Ensure perfect reversibility
- Handle edge cases (empty strings, special characters)

### Why This Matters for Google:
- **Network protocols** - data transmission
- **Database storage** - efficient serialization
- **Caching systems** - data compression
- **API design** - data format standardization

### Alternative Approaches I Considered:
1. **Character transformation** - too complex, collision-prone
2. **Fixed-width encoding** - inefficient for variable lengths
3. **Delimiter-only approach** - ambiguous with special characters
4. **My approach** - simple, efficient, unambiguous

For most interviews, my approach is perfect - clear, efficient, and handles all edge cases.

---

## 🔗 Related Problems

This pattern connects to:
- **Serialize and Deserialize Binary Tree** - same pattern, tree structure
- **Custom Data Structure Design** - serialization principles
- **String Compression** - similar encoding concepts
- **Network Protocol Design** - data serialization fundamentals

---

## 🚀 My Takeaways

1. **Variable scope matters** - local vs member variables
2. **Return statement placement** - loop control is crucial
3. **Character vs string types** - attention to data types
4. **Systematic parsing** - position tracking and boundary detection
5. **Edge case handling** - empty inputs, special characters
6. **Reversible design** - perfect reconstruction requirement

This problem taught me fundamental serialization principles and careful string parsing - essential skills for Google SWE interviews!

---

**Problem 8/150 Complete! 🎯**
