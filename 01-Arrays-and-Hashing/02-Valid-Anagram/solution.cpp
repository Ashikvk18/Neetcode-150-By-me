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
