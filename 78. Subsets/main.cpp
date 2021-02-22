//
//  main.cpp
//  78. Subsets
//
//  Created by 强文杰 on 2021/2/21.
//  Copyright © 2021 强文杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        backtrack(nums, 0, sub, ans);
        return ans;
    }

private:
    void backtrack(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& ans){
        ans.push_back(sub);
        for (int j = i ; j < nums.size(); j++) {
            sub.push_back(nums[j]);
            backtrack(nums, j+1, sub, ans);
            sub.pop_back();
        }
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
