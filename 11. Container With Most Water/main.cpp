//
//  main.cpp
//  11. Container With Most Water
//
//  Created by 强文杰 on 2020/11/8.
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
    int maxArea(vector<int>& height) {
        /**
         Two pointers ,one at the beginning and one at the end
         they must move,
         since limitation of the shorter line, we need mv the short to the longer
         */
        int len = height.size();
        int l = 0, r = len -1;
        int max= 0;
        while (l < r) {
            int s = (r-l) * min(height[l],height[r]);
            if (s > max) {
                max = s;
            }
            if (height[l] < height[r]) {
                l++;
            }else{
                r--;
            }
        }   
        return max;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
