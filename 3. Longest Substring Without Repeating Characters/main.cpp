//
//  main.cpp
//  3. Longest Substring Without Repeating Characters
//
//  Created by 强文杰 on 2020/10/14.
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
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int start = -1;
        int maxLen = 0;
        for (int i = 0 ; i < s.size(); i++) {
            if (m.count(s[i]) !=0) {
                start = max(start, m[s[i]]);
            }
            
            m[s[i]] = i;
            maxLen = max(maxLen, i - start);
            
        }
        
        return maxLen;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
