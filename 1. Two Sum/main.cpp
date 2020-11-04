//
//  main.cpp
//  1. Two Sum
//
//  Created by 强文杰 on 2020/10/13.
//  Copyright © 2020 强文杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> imap;
        
        for(int i = 0; ;i++){
            auto it =  imap.find(target -nums[i]);
            if(it != imap.end()){
                return vector<int>{i,it->second};
            }
            imap[nums[i]] = i;
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    std::cout << "Hello, World!\n";
    return 0;
}
