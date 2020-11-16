//
//  main.cpp
//  46. Permutations
//
//  Created by 强文杰 on 2020/11/16.
//  Copyright © 2020 强文杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <set>
#include <stack>
#include <algorithm>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // Similar to the bubble sort method
        // the difference is that the intermediate results of each step need to be saved
        vector<vector<int> > result;
        dfs(0, nums, result);
        return result;
    }
    
    void dfs(int pos, vector<int> &nums, vector<vector<int>> &result){
        if(pos == nums.size()){
            result.push_back(nums);
        }else{
            for(int i=pos; i<nums.size(); i++){
                swap(nums[i], nums[pos]);
                dfs(pos+1, nums, result);
                swap(nums[i], nums[pos]);
            }
        }
    }
   
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> n = {1,2,3};
    s.permute(n);
    std::cout << "Hello, World!\n";
    return 0;
}
