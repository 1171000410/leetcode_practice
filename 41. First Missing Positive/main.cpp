//
//  main.cpp
//  41. First Missing Positive
//
//  Created by 强文杰 on 2020/11/15.
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
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            if (nums[0] < 0) {
                return 0;
            }else{
                return nums[0] + 1;
            }
        }
        
        
        int min = INT32_MAX;
        int sec_min = INT32_MAX;
        int max = -1;
        
        for (int i = 0 ; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                if (nums[i] < min) {
                    sec_min = min;
                    min = nums[i];
                }else if(nums[i] < sec_min){
                    sec_min = nums[i];
                }
                max = nums[i] > max ? nums[i] : max;
            }
        }
        
        if (sec_min - min <= 1 && min == 0) {
            return max +1;
        }
        if (sec_min - min > 1) {
            return sec_min - 1;
        }
        return min - 1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
