//
//  main.cpp
//  10. Regular Expression Matching
//
//  Created by 强文杰 on 2020/11/5.
//  Copyright © 2020 强文杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>

using namespace std;

class Solution {
public:
    // Recursion
    bool isMatch0(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }
        // *s is to ensure s is non-empty
        if (p[1] == '*') {
            return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1),p));
        }else{
            return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
        
    }
    
    // DP
    bool isMatch(string s, string p) {
        /**
         * dp[i][j]: if s[0..i-1] matches p[0..j-1]
         * if p[j - 1] != '*'
         *      f[i][j] = dp[i - 1][j - 1] && s[i - 1] == p[j - 1]
         * if p[j - 1] == '*', denote p[j - 2] with x
         *      f[i][j] is true iff any of the following is true
         *      1) "x*" repeats 0 time and matches empty: dp[i][j - 2]
         *      2) "x*" repeats >= 1 times and matches "x*x": s[i - 1] == x && dp[i - 1][j]
         * '.' matches any single character
         */
        
        int m = (int)s.length();
        int n = (int)p.length();
        
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        
        // initialization
        dp[0][0] = true;
        for (int i = 1 ; i<m+1; i++) {
            dp[i][0] = false;
        }
        for (int j = 1; j < n+1; j++) {
            if (j > 1 && p[j-1] == '*' && dp[0][j-2]) {
                dp[0][j] = true;
            }else{
                dp[0][j] = false;
            }
        }
        
        for (int i = 1; i < m+1 ; i++) {
            for (int j = 1; j < n+1; j++) {
                if (p[j-1] != '*') {
                    dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                }else{
                    dp[i][j] = dp[i][j-2] || ((s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j]);
                    
                }
            }
        }
        return dp[m][n];
    }
    
};

int main(int argc, const char * argv[]) {
    Solution s;
    string a = "ab";
    string b = ".*..";
    
    cout << s.isMatch(a,b);
    
    return 0;
}
