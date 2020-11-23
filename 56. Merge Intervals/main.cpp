//
//  main.cpp
//  56. Merge Intervals
//
//  Created by 强文杰 on 2020/11/23.
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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        vector<int> p = {intervals[0][0],intervals[0][1]};
        for (int i = 1; i < intervals.size(); i++) {
            if (p[1] >= intervals[i][0]) {
                p[1] = max(p[1], intervals[i][1]);
            }else{
                ans.push_back(p);
                p = {intervals[i][0],intervals[i][1]};
            }
        }
        ans.push_back(p);
        
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
