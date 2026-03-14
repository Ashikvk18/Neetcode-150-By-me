
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t) {

    if(s.length() != t.length()) {
        return false;
    }
    int count[26]=0;
    for(int i = 0; i<s.length(); i++)
    {
        int position = s[i] - 'a';
        count[position]++;
    }
    for(int i = 0; i<t.length(); i++)
    {
        int position = t[i] - 'a';
        count[position]--;
    }
    for (int i = 0; i<26; i++)
    {
        if (count[i] !=0)
        {
            return false;
        }
    }
    return true;
}

bool isAnagram_hashmap(string s, string t) {
    // We'll build this step by step
    if(s.length() != t.length()) {
        return false;
    }
    unordered_map<char, int> count;
    for (int i = 0; i<s.length(); i++){
        count[s[i]]++;
    }
    for (int i =0; i<t.length(); i++){
        count[t[i]]--;
    }
    for (auto& pair : count){
        if (pair.second != 0){
            return false;
        }
    }
    return true;

}
