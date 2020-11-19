//
//  main.cpp
//  49. Group Anagrams
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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string str : strs) {
            string t = str;
            sort(t.begin(), t.end());
            mp[t].push_back(str);
        }
        
        vector<vector<string>> ans;
        for (auto p : mp) {
            ans.push_back(p.second);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
