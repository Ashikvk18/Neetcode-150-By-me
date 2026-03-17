#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    
    vector<pair<int, int>> fV;
    for (auto& pair : freq) {
        fV.push_back({pair.second, pair.first});
    }

    sort(fV.begin(), fV.end());

    vector<int> result;
    for (int i = 0; i < k; i++){
        result.push_back(fV[i].second);
    }
    
    return result;
}






        
    