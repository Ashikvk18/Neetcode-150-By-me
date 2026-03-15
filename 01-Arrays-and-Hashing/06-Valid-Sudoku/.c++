#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool isVS(vector<vector<char>>& board) {
    unordered_set<char> row[9];
    unordered_set<char> col[9];
    unordered_set<char> box[9];

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            char c = board[i][j];
            if(c != '.') {
                if (row[i].contains(c)){
                    return false;
                }
                if (col[j].contains(c)){
                    return false;
                }
                int bI = (i/3)*3 + (j/3);
                if (box[bI].contains(c)){
                    return false;
                }
                row[i].insert(c);
                col[j].insert(c);
                box[bI].insert(c);
            }
            
        }
    }
    return true;
}
