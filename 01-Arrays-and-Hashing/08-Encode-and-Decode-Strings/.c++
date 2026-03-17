#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for(int i =0;i<strs.size();i++){
            // Convert length to string and append
            // For example, if len is 5, append "5"
            // Then append the string itself
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
        int pos =0;
        
        while(pos < res.length()) {
            string L = "";
            while(res[pos] != '#'){
                L += res[pos];
                pos++;
            }
            pos++;
            int l =stoi(L);
            string s ="";
            for(int i =0;i<l;i++){
                s += res[pos];
                pos++;
            }
            result.push_back(s);
        }    
        return result;
    }
};
