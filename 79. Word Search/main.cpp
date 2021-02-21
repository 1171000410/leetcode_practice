//
//  main.cpp
//  79. Word Search
//
//  Created by 强文杰 on 2021/2/19.
//  Copyright © 2021 强文杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <set>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty()){
            return true;
        }
        if (board.empty() || board[0].empty()) {
            return false;
        }
        // don't init again !
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board,word,0,i,j)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
private:
    int m;
    int n;
    bool dfs(vector<vector<char>>& board, string& word, int k, int i, int j){
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k]) {
            return false;
        }
        if (k == word.length() -1) {
            return true;
        }
        char p = board[i][j];
        board[i][j] = '*';  //find
        bool ret = dfs(board, word, k+1, i-1, j) || dfs(board, word, k+1, i+1, j) ||dfs(board, word, k+1, i, j+1) ||dfs(board, word, k+1, i, j-1);
        
        
        board[i][j] = p;  // reset
        
        return ret;
  
    }
};

int main(int argc, const char * argv[]) {
    string word = "ABCCED";
    vector<vector<char>> board= {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    Solution s ;
    cout << s.exist(board, word);
    return 0;
}
