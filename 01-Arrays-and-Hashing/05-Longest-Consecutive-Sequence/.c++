#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> num(nums.begin(), nums.end());
    int maxR = 0;
    for(int x : num) {
        if(!num.contains(x-1)){
            int current = x;
            int streak =1;
            while (num.contains(current+1)){
                current++;
                streak++;
            }
            maxR = max(maxR, streak);
        }
    }
    return maxR;
}