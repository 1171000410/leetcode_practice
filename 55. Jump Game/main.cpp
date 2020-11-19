//
//  main.cpp
//  55. Jump Game
//
//  Created by 强文杰 on 2020/11/19.
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
    bool canJump(vector<int>& nums) {
        // greedy
        if (nums.size() == 1) {
            return true;
        }
        int last = nums.size() -1;
        int temp = last;
        int flag = 0;
        for (int i = last-1; i >=0 ; i--) {
            if(nums[i] >= temp-i){
                temp = i;
            }
            if (temp == 0) {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
