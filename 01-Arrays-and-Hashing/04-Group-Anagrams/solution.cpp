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
