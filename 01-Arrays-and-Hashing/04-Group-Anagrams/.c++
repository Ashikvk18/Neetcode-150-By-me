#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupA(vector<string>& strs){
    unordered_map<string, vector<string>> map;
     for (int i=0; i<strs.size(); i++)
     {
      string s = strs[i];
      sort(s.begin(), s.end());
      map[s].push_back(strs[i]);   
     }
     vector<vector<string>> result;
     for ( auto& pair : map)
     {
        result.push_back(pair.second);
     }
     return result;
}
