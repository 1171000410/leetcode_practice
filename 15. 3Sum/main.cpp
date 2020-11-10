//
//  main.cpp
//  15. 3Sum
//
//  Created by 强文杰 on 2020/11/9.
//  Copyright © 2020 强文杰. All rights reserved.
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        /**
         Very similar to two sum, pay attention to avoid duplication
         */
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<int> scanned;
        int len = (int)nums.size();
        for (int i = 0; i < len-2; i++) {
            if(i>0 && (nums[i]==nums[i-1]) )
                continue;
            int temp = nums[i];
            unordered_map<int, int> imap;
            set<int> scanned;
            for (int j = i+1; j < len; j++) {
                auto it = imap.find(-temp-nums[j]);
                if (it != imap.end()) {
                    ans.push_back(vector<int>{temp,nums[j],-temp-nums[j]});
                    imap.erase(it);
                    scanned.insert(-temp-nums[j]);
                }else{
                    auto itt = scanned.find(nums[j]);
                    if (itt != scanned.end()) {
                        continue;
                    }else{
                        imap[nums[j]] = j;
                    }
                }

            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {0,0,0};
    s.threeSum(nums);
    return 0;
}
