# NeetCode 150 - My Google SWE Interview Journey

Welcome to my comprehensive journey through the NeetCode 150 problems! This repository contains my personal learning journey, solutions, and insights for all 150 problems, implemented in C++ as I prepare for Google SWE interviews.

## 🎯 My Google Interview Goals
- Master fundamental data structures and algorithms
- Develop problem-solving intuition and pattern recognition
- Improve C++ coding skills and best practices
- Build a portfolio of clean, well-documented solutions
- Learn to think like a Google engineer

## 📊 My Progress Journey

### Overall Progress: 5/150 (3.3%)

### Category Breakdown
| Category | Problems | Completed | Progress |
|----------|----------|-----------|----------|
| Arrays & Hashing | 21 | 5/21 | 🟩🟩🟩🟩🟩⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜ |
| Two Pointers | 11 | 0/11 | ⬜⬜⬜⬜⬜ |
| Sliding Window | 9 | 0/9 | ⬜⬜⬜⬜⬜ |
| Stack | 9 | 0/9 | ⬜⬜⬜⬜⬜ |
| Binary Search | 9 | 0/9 | ⬜⬜⬜⬜⬜ |
| Linked List | 12 | 0/12 | ⬜⬜⬜⬜⬜ |
| Trees | 20 | 0/20 | ⬜⬜⬜⬜⬜ |
| Tries | 4 | 0/4 | ⬜⬜⬜⬜⬜ |
| Heap/Priority Queue | 8 | 0/8 | ⬜⬜⬜⬜⬜ |
| Backtracking | 8 | 0/8 | ⬜⬜⬜⬜⬜ |
| Graphs | 13 | 0/13 | ⬜⬜⬜⬜⬜ |
| Advanced Graphs | 5 | 0/5 | ⬜⬜⬜⬜⬜ |
| 1-D Dynamic Programming | 12 | 0/12 | ⬜⬜⬜⬜⬜ |
| 2-D Dynamic Programming | 9 | 0/9 | ⬜⬜⬜⬜⬜ |

## 📁 Project Structure
```
Neetcode/
├── 01-Arrays-and-Hashing/
├── 02-Two-Pointers/
├── 03-Sliding-Window/
├── 04-Stack/
├── 05-Binary-Search/
├── 06-Linked-List/
├── 07-Trees/
├── 08-Tries/
├── 09-Heap-Priority-Queue/
├── 10-Backtracking/
├── 11-Graphs/
├── 12-Advanced-Graphs/
├── 13-1D-Dynamic-Programming/
├── 14-2D-Dynamic-Programming/
├── README_TEMPLATE.md
├── .gitignore
└── README.md
```

## 🎯 My Completed Problems & Patterns Mastered

### ✅ Arrays & Hashing (5/21 Complete)

#### **Problem #1: Contains Duplicate** - Easy
- **Pattern:** Hash set existence checking
- **Key Insight:** O(1) lookup for duplicate detection
- **Complexity:** O(n) time, O(n) space

#### **Problem #2: Valid Anagram** - Easy  
- **Pattern:** Frequency counting
- **Key Insight:** Character frequency comparison
- **Complexity:** O(n) time, O(1) space (26 letters)

#### **Problem #3: Two Sum** - Easy
- **Pattern:** Complement detection (MOST IMPORTANT!)
- **Key Insight:** target - current = complement
- **Complexity:** O(n) time, O(n) space

#### **Problem #4: Group Anagrams** - Medium
- **Pattern:** String signature grouping
- **Key Insight:** Sorted strings as hash map keys
- **Complexity:** O(n × m log m) time, O(n × m) space

#### **Problem #5: Longest Consecutive Sequence** - Medium
- **Pattern:** Sequence detection with start detection
- **Key Insight:** (num - 1) doesn't exist = sequence start
- **Complexity:** O(n) time, O(n) space

---

## 🧠 Key Google Patterns I've Mastered

### **1. Hash Set Patterns**
- **Existence checking** - O(1) lookup
- **Duplicate detection** - immediate validation
- **Set operations** - efficient membership testing

### **2. Hash Map Patterns** 
- **Key-value storage** - number → index mapping
- **Grouping patterns** - signature → list of items
- **Complement lookup** - O(1) partner finding

### **3. Array/String Patterns**
- **Frequency counting** - character/number occurrence
- **Signature generation** - sorting for grouping
- **Sequence detection** - start detection logic

### **4. Optimization Thinking**
- **O(n²) → O(n)** - complement pattern
- **O(n log n) → O(n)** - hash set over sorting
- **Space-time tradeoffs** - when to use extra space

---

## 🚀 My Google Interview Readiness

### **What I've Learned:**
- ✅ **Pattern recognition** - identify problem types instantly
- ✅ **Data structure selection** - choose optimal structures
- ✅ **Complexity analysis** - understand O(n) vs O(n log n)
- ✅ **Algorithm design** - think step by step
- ✅ **C++ syntax mastery** - references, iterators, containers

### **My Problem-Solving Approach:**
1. **Understand constraints** - read requirements carefully
2. **Consider brute force** - natural solution first
3. **Look for optimization** - can we do better?
4. **Choose data structures** - right tool for the job
5. **Implement step by step** - build incrementally
6. **Analyze complexity** - justify my choices

### **Ready For:**
- Hash set/hash map problems
- Frequency counting challenges  
- Complement pattern questions
- Grouping and organization tasks
- O(n) optimization requirements

## 🛠️ Methodology
For each problem, I follow a structured approach:

1. **Problem Analysis**: Understand constraints and edge cases
2. **Visualization**: Create step-by-step diagrams and explanations
3. **Algorithm Design**: Choose optimal approach and justify it
4. **Implementation**: Write clean, commented C++ code
5. **Testing**: Verify with multiple test cases
6. **Reflection**: Document key insights and lessons learned

## 📝 Problem Template
Each problem includes:
- Detailed problem statement and examples
- Visual explanation of the approach
- Time/space complexity analysis
- Well-commented C++ implementation
- Test cases and edge case coverage
- Key takeaways and alternative approaches

## 🚀 Getting Started
1. Clone this repository
2. Navigate to any category folder
3. Each problem has its own folder with README.md and solution files
4. Use the README_TEMPLATE.md as a guide for understanding the format

## 📚 Learning Resources
- [NeetCode Website](https://neetcode.io/)
- [LeetCode](https://leetcode.com/)
- [C++ Reference](https://en.cppreference.com/)

## 📈 Study Plan
- **Phase 1**: Arrays, Two Pointers, Sliding Window (Weeks 1-2)
- **Phase 2**: Stack, Binary Search, Linked List (Weeks 3-4)
- **Phase 3**: Trees, Tries, Heaps (Weeks 5-6)
- **Phase 4**: Backtracking, Graphs (Weeks 7-8)
- **Phase 5**: Dynamic Programming (Weeks 9-10)
- **Phase 6**: Review and Optimization (Weeks 11-12)

## 🎖️ Milestones
- [ ] First 25 problems completed
- [ ] Halfway point (75 problems)
- [ ] All 150 problems completed
- [ ] Solutions optimized and reviewed

---

*"The journey of a thousand miles begins with a single step."* - Lao Tzu

Happy coding! 🚀
