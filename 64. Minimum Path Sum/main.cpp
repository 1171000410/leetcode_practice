//
//  main.cpp
//  64. Minimum Path Sum
//
//  Created by 强文杰 on 2020/12/17.
//  Copyright © 2020 强文杰. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row,vector<int>(col));
        dp[0][0] = grid[0][0];
        for (int i = 1; i<row; i ++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for (int i = 1; i<col; i ++) {
            dp[0][i] = dp[0][i-1]+ grid[0][i];
        }
        
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                dp[i][j] = min(dp[i-1][j] , dp[i][j-1]) + grid[i][j];
            }
        }
        
        return dp[row -1][col -1];
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
