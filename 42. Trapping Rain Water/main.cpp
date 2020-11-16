//
//  main.cpp
//  42. Trapping Rain Water
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
    int trap1(vector<int>& height) {
        // bruce force
        int ans = 0;
        for (int i = 0 ; i < height.size(); i++) {
            int k= i ,j = i;
            int left_max = 0 ,right_max = 0;
            
            while (k != -1) {
                left_max = left_max > height[k] ? left_max : height[k];
                k --;
            }
            while (j != height.size()) {
                right_max = right_max > height[j] ? right_max : height[j];
                j ++;
            }
            int min = 0;
            min = left_max > right_max ? right_max : left_max;
            ans += min - height[i];
        }
        return ans;
    }
    
    int trap(vector<int>& height)
    {
        // dynamic programming
        // in fact, left_max and right_max could be store
        if(height.size() == 0)
            return 0;
        int ans = 0;
        int size = height.size();
        vector<int> left_max(size), right_max(size);
        left_max[0] = height[0];
        for (int i = 1; i < size; i++) {
            left_max[i] = max(height[i], left_max[i - 1]);
        }
        right_max[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            right_max[i] = max(height[i], right_max[i + 1]);
        }
        for (int i = 1; i < size - 1; i++) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
